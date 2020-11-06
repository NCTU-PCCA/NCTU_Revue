#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
void cal_pa(auto &G, int u, int p, auto &pa, auto &dep) {
    pa[0][u] = p;
    int n = G.size();
    int lgN = __lg(n) + 5;
    for (int i = lgN - 1 ; i >= 1 ; i--)
        pa[i][u] = pa[i - 1][pa[i - 1][u]];
    for (auto &v : G[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        cal_pa(G, v, u, pa, dep);
    }
}
void cal_co(auto &G, int u, auto &co) {
    for (auto &e : G[u]) {
        co[e.F] = co[u] + e.S;
        cal_co(G, e.F, co);
    }
}
int lca(int u, int v, auto &pa, auto &dep) {
    int n = dep.size();
    if (dep[u] < dep[v]) swap(u, v);
    int lgN = __lg(n) + 5;
    for (int i = lgN - 1 ; i >= 0 ; i--) {
        if (dep[pa[i][u]] >= dep[v])
            u = pa[i][u];
    }
    if (u == v) return u;
    for (int i = lgN - 1 ; i >= 0 ; i--) {
        if (pa[i][u] != pa[i][v])
            u = pa[i][u], v = pa[i][v];
    }
    return pa[0][u];
}
struct Edge {
    int u, v;
    int c1, c2;
};
int find(int x, auto &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    vector<Edge> edges;
    int sum = 0;
    vector<int> djs(n, -1);
    for (int i = 1 ; i < n ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int c1, c2; cin >> c1 >> c2;
        G[u].push_back(v);
        G[v].push_back(u);
        edges.push_back({u, v, c1, c2});
        int x = find(u, djs);
        int y = find(v, djs);
        assert(x != y);
        if (djs[x] > djs[y])
            swap(x, y);
        djs[x] += djs[y];
        djs[y] = x;
        sum += c1 + c2;
    }
    vector<vector<int>> pa(__lg(n) + 5, vector<int>(n));
    vector<int> dep(n, 0);
    cal_pa(G, 0, 0, pa, dep);

    vector<vector<pii>> G1(n), G2(n);
    for (auto &e : edges) {
        if (dep[e.u] == dep[e.v] + 1)
            swap(e.c1, e.c2), swap(e.u, e.v);
        G1[e.u].push_back({e.v, e.c1});
        G2[e.u].push_back({e.v, e.c2});
    }
    vector<int> d1(n, 0);
    cal_co(G1, 0, d1);
    vector<int> d2(n, 0);
    cal_co(G2, 0, d2);
    int q; cin >> q; while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        int l = lca(u, v, pa, dep);
        int co = d2[v] - d2[l] + d1[u] - d1[l];
        cout << sum - co << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
