#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
const long long INF = 1LL<<60;
struct Dinic {  //O(VVE), with minimum cut
    static const int MAXN = 5003;
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init(){
        edges.clear();
        for ( int i = 0 ; i < n ; i++ ) G[i].clear();
        n = 0;
    }

    // min cut start
    bool side[MAXN];
    void cut(int u) {
        side[u] = 1;
        for ( int i : G[u] ) {
            if ( !side[ edges[i].v ] && edges[i].rest ) cut(edges[i].v);
        }
    }
    // min cut end

    int add_node(){
        return n++;
    }

    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool bfs(){
        fill(d,d+n,-1);
        queue<int> que;
        que.push(s); d[s]=0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            f = dfs(e.v, min(a, e.rest) );
            if ( f > 0 ) {
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }

    long long maxflow(int _s, int _t){
        s = _s, t = _t;
        long long flow = 0, mf;
        while ( bfs() ){
            fill(cur,cur+n,0);
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }
} dinic;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    int n = 5;
    int mat[n+5][n+5]={};
    memset(mat,-1,sizeof(mat));
    f1(n){
        fr(j,i+1,n+1){
            mat[i][j]=mat[j][i]=rand()%5;
            if (mat[i][j] == 0) continue;
            int k = 1;
            for (k = 1; ; k++) {
                if (k != i && k != j) break;
            }
            mat[i][k]=mat[k][i]=mat[i][j];
            mat[j][k]=mat[k][j]=mat[i][j];
        }
    }
    f1(n){
        fr(j,1,n+1){
            cout<<setw(3)<<mat[i][j]<<' ';;
        }
        cout << endl;
    }
    f1(n){
        fr(j,1,n+1){
            if(i==j){
                cout<<setw(3)<<-1<<' ';
            }
            else{
                dinic.init();
                dinic.n=n+1;
                fr(k,1,n+1){
                    fr(l,k+1,n+1){
                        dinic.add_edge(k,l,mat[k][l]);
                        dinic.add_edge(l,k,mat[k][l]);
                    }
                }
                cout<<setw(3)<<dinic.maxflow(i,j)<<' ';
            }
        }
        cout << endl;
    }
}
