#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<int, int> pii;
struct Edge {
    int u, v; LL w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
int find(int x, auto &djs) {
    return djs[x] < 0 ? x : djs[x] = find(djs[x], djs);
}
void dfs(int u, Edge p, auto &G, auto &pa, auto &maxV, auto &dep) {
    pa[0][u] = p.u;
    maxV[0][u] = p.w;
    dep[u] = dep[p.u] + 1;
    int lgN = pa.size();
    for (int i = 1 ; i < lgN ; i++) {
        pa[i][u] = pa[i - 1][pa[i - 1][u]];
        maxV[i][u] = max(maxV[i - 1][u], maxV[i - 1][pa[i - 1][u]]);
    }
    for (auto &e : G[u]) {
        if (e.v == p.u) continue;
        dfs(e.v, e, G, pa, maxV, dep);
    }
}
LL solve(int u, int v, auto &pa, auto &maxV, auto &dep) {
    if (dep[u] < dep[v])
        swap(u, v);
    int lgN = pa.size();
    LL ret = 0;
    for (int i = lgN - 1 ; i >= 0 ; i--) {
        if (dep[pa[i][u]] >= dep[v]) {
            ret = max(ret, maxV[i][u]);
            u = pa[i][u];
        }
    }
    if (u == v) return ret;
    for (int i = lgN - 1 ; i >= 0 ; i--) {
        if (pa[i][u] != pa[i][v]) {
            ret = max(ret, maxV[i][u]);
            ret = max(ret, maxV[i][v]);
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    ret = max(ret, maxV[0][u]);
    ret = max(ret, maxV[0][v]);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Edge> E(m);
    map<pii, LL> edge;
    for (int i = 0 ; i < m ; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
        E[i].u--, E[i].v--;
        if (E[i].u > E[i].v)
            swap(E[i].u, E[i].v);
        edge[{E[i].u, E[i].v}] = E[i].w;
    }
    set<pii> inTree;
    sort(E.begin(), E.end());
    LL base = 0;
    vector<int> djs(n, -1);
    vector<vector<Edge>> G(n);
    for (auto &e : E) {
        int u = find(e.u, djs);
        int v = find(e.v, djs);
        if (u == v) continue;
        if (djs[u] > djs[v])
            swap(u, v);
        djs[u] += djs[v];
        djs[v] = u;
        base += e.w;
        inTree.insert({e.u, e.v});
        G[e.u].push_back({e.u, e.v, e.w});
        G[e.v].push_back({e.v, e.u, e.w});
    }
    int lgN = __lg(n) + 5;
    vector<vector<int>> pa(lgN, vector<int>(n));
    vector<vector<LL>> maxV(lgN, vector<LL>(n, 0));
    vector<int> dep(n, 0);
    dfs(0, {0, 0, 0}, G, pa, maxV, dep);
    int q; cin >> q; while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        if (inTree.count(make_pair(u, v))) {
            cout << base << '\n';
        } else {
            LL tmp = solve(u, v, pa, maxV, dep);
            cout << base - solve(u, v, pa, maxV, dep) + edge[{u, v}] << '\n';
        }
    }
    
}
