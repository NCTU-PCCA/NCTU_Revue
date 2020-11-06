#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Dinic { LL flow;
    struct Node : vector<int> { int d, p; };
    struct Edge { int u, v; LL c; };
    vector<Node> N; vector<Edge> E;
    void init(int n) {
        E.clear(); N.clear(); N.resize(n);
        flow = 0;
    }
    void addEdge(int u, int v, LL c) { int m = E.size();
        E.push_back({u, v, c}); N[u].push_back(m++);
        E.push_back({v, u, 0}); N[v].push_back(m++);
    }
    void run(int s, int t) {
        flow = 0; while (bfs(s, t)) flow += dfs(s, t, INF);
    }
    bool bfs(int s, int t) {
        for (auto &v : N) v.d = -1, v.p = 0;
        queue<int> q; q.push(s); N[s].d = 0;
        while (q.size()) { int u = q.front(); q.pop();
            for (auto &e : N[u]) { int v = E[e].v;
                if (!~N[v].d && E[e].c)
                    q.push(v), N[v].d = N[u].d + 1;
            }
        }
        return ~N[t].d;
    }
    LL dfs(int u, int t, LL a) {
        if (u == t || !a) return a; LL flow = 0;
        for (int &p = N[u].p ; p < N[u].size() ; p++) {
            auto e = N[u][p], v = E[e].v;
            if (N[u].d + 1 != N[v].d) continue;
            LL f = dfs(v, t, min(a, E[e].c));
            E[e].c -= f; E[e ^ 1].c += f;
            flow += f; a -= f;
            if (!a) break;
        }
        return flow;
    }
} solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> P(n);
    for (auto &v : P)
        cin >> v;
    vector<vector<LL>> G(n, vector<LL>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> G[i][j];
            if (i != j)
                G[i][j] += P[j];
        }
    }
    vector<vector<LL>> ori = G;
    for (int k = 0 ; k < n ; k++)
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    vector<pair<pair<int, int>, LL>> pool(m);
    for (auto &v : pool) {
        cin >> v.F.F >> v.F.S >> v.S; v.F.F--, v.F.S--;
    }
    solver.init(2 + 2 * m);
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (i == j)
                continue;
            if (pool[i].S + ori[pool[i].F.F][pool[i].F.S] + G[pool[i].F.S][pool[j].F.F] > pool[j].S)
                continue;
            solver.addEdge(1 + i, 1 + m + j, 1);
        }
    }
    for (int i = 0 ; i < m ; i++)
        solver.addEdge(0, i + 1, 1),
        solver.addEdge(i + m + 1, m + m + 1, 1);
    solver.run(0, 1 + m + m);
    cout << m - solver.flow << '\n';
}
