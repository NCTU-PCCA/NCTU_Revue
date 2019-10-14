#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
typedef int LL;
const LL INF = 0x3f3f3f3f;
vector<int>g[10005];
int dep[10005];
int fa[10005];
void dfs(int now,int pre){
    for(auto i:g[now]){
        if(i==pre)continue;
        dep[i]=dep[now]+1;
        fa[i]=now;
        dfs(i,now);
    }
}
struct Dinic {
    static const int MAXN = 20003;
    struct Edge {
        int u, v;
        LL cap, rest;
    };
    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    void init() {
        edges.clear();
        for (int i = 0 ; i < n ; i++)
            G[i].clear();
        n = 0;
    }
    void add_edge(int u, int v, LL cap) {
        edges.push_back({u, v, cap, cap});
        edges.push_back({v, u, 0, 0LL});
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    bool bfs() {
        fill(d, d + n, -1);
        queue<int> que;
        que.push(s); d[s] = 0;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (int ei : G[u]) {
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0) {
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }
    LL dfs(int u, LL a) {
        if (u == t || a == 0) return a;
        LL flow = 0, f;
        for (int &i = cur[u] ; i < (int)G[u].size() ; i++) {
            Edge &e = edges[G[u][i]];
            if (d[u] + 1 != d[e.v]) continue;
            f = dfs(e.v, min(a, e.rest));
            if (f > 0) {
                e.rest -= f;
                edges[G[u][i] ^ 1].rest += f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    LL maxflow(int _s, int _t) {
        s = _s, t = _t;
        LL flow = 0, mf;
        while (bfs()) {
            fill(cur, cur + n, 0);
            while ( (mf = dfs(s, INF)) ) flow += mf;
        }
        return flow;
    }
}dinic;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    dinic.init();
    dinic.n=n+m+2;
    for(int i=1;i<=n;i++){
        int add;
        cin >> add;
        dinic.add_edge(0,i,add);
    }
    for(int i=1;i<n;i++){
        int add1,add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++){
        int add1,add2,add3;
        cin >> add1 >> add2 >> add3;
        if(dep[add1]<dep[add2]){
            swap(add1,add2);
        }
        int left = dep[add1]-dep[add2];
        int pos1 = add1,pos2=add2;
        while(left--){
            dinic.add_edge(pos1,n+i,1000000);
            pos1=fa[pos1];
        }
        while(pos1!=pos2){
            dinic.add_edge(pos1,n+i,1000000);
            dinic.add_edge(pos2,n+i,1000000);
            pos1=fa[pos1];
            pos2=fa[pos2];
        }
        dinic.add_edge(pos1,n+i,1000000);
        dinic.add_edge(n+i,n+m+1,add3);
    }
    cout<<dinic.maxflow(0, n + m + 1) << '\n';
}
