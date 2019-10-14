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
const int MAXN = 105;
struct E {
    int u, v; LL w;
};
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
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    LL F[MAXN][MAXN];
    vector<E> edges;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> F[i][j];
            if (i < j && F[i][j])
                edges.push_back({i, j, F[i][j]});
        }
    }
    sort(edges.begin(), edges.end(), [](E a, E b){
        return a.w > b.w;
    });
    set<int> st;
    LL A[MAXN][MAXN]; memset(A, 0, sizeof(A));
    for (int i = 0 ; i < n ; i++) A[i][i] = -1;
    LL last = INF;
    vector<E> added;
    vector<int> pa(n, -1);
    for (auto &e : edges) {
        int x = find(e.u, pa);
        int y = find(e.v, pa);
        if (x == y)
            continue;
        pa[x] += pa[y];
        pa[y] = x;
        A[e.u][e.v] = A[e.v][e.u] = e.w;
        added.push_back({e.u, e.v, e.w});
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            dinic.init();
            dinic.n = n;
            for (auto &e : added)
                dinic.add_edge(e.u, e.v, e.w),
                dinic.add_edge(e.v, e.u, e.w);
            if (dinic.maxflow(i, j) != F[i][j]) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
    cout << "YES\n";
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            cout << A[i][j] << " \n"[j + 1 == n];
}
