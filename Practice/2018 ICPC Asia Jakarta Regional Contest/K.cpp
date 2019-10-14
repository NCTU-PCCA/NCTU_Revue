#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
struct E {
    int u, v; bool used;
};
struct A {
    int u, v1, v2;
};
vector<A> ans;
vector<vector<int> > G;
vector<E> edges;
vector<int> vis;
typedef pair<int, int> pii;
void dfs(int u, int pa) {
    for (auto &_e : G[u]) {
        E e = edges[_e];
        if (vis[e.v])
            continue;
        vis[e.v] = true;
        dfs(e.v, e.u);
    }
    vector<pii> target;
    int v1 = -1, v2 = -1, pidx = -1;
    for (int i = 0 ; i < G[u].size() ; i++) {
        if (edges[G[u][i]].used)
            continue;
        if (edges[G[u][i]].v == pa) {
            pidx = G[u][i];
            continue;
        }
        if (v1 == -1) {
            v1 = G[u][i];
        } else {
            v2 = G[u][i];
            target.push_back({v1, v2});
            v1 = -1, v2 = -1;
        }
    }
    if (v2 == -1 && v1 != -1 && pidx != -1 && !edges[pidx].used) {
        target.push_back({v1, pidx});
    }
    for (auto &p : target) {
        edges[p.F].used = true;
        edges[p.S].used = true;
        edges[p.F ^ 1].used = true;
        edges[p.S ^ 1].used = true;
        ans.push_back({edges[p.F].v, u, edges[p.S].v});
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    G.clear(); G.resize(n);
    vis.clear(); vis.resize(n, false);
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(edges.size());
        edges.push_back({u, v, false});
        G[v].push_back(edges.size());
        edges.push_back({v, u, false});
    }
    for (int i = 0 ; i < n ; i++) {
        if (vis[i])
            continue;
        vis[i] = true;
        dfs(i, i);
    }
    cout << ans.size() << '\n';
    for (auto &_a : ans)
        cout << _a.u + 1 << ' ' << _a.v1 + 1 << ' ' << _a.v2 + 1 << '\n';
}
