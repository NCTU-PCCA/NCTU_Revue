#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Graph { int s, t;
    struct Node : vector<int> {
        int p, d; Node() { clear(); }
    };
    struct Edge { int u, v; LL c, f; };
    vector<Node> N;
    vector<Edge> E;
    Graph (int n) {
        N.clear(); N.resize(n);
        E.clear();
    }
    void addEdge(int u, int v, LL c) {
        E.push_back({u, v, c, 0});
        E.push_back({v, u, 0, 0});
        int m = E.size();
        N[u].push_back(m - 2);
        N[v].push_back(m - 1);
    }
    LL maxFlow(int _s, int _t) {
        s = _s, t = _t;
        LL flow = 0; while (bfs()) {
            for (auto &n : N) n.p = 0;
            flow += dfs(s, INF);
        }
        return flow;
    }
    bool bfs() {
        for (auto &n : N) n.d = -1;
        queue<int> q; q.push(s); N[s].d = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &e : N[u]) {
                int v = E[e].v;
                if (!~N[v].d && E[e].c > E[e].f)
                    q.push(v), N[v].d = N[u].d + 1;
            }
        }
        return ~N[t].d;
    }
    LL dfs(int u, LL a) {
        if (u == t || !a) return a; LL F = 0;
        for (; N[u].p != N[u].size() ; N[u].p++) {
            int e = N[u][N[u].p], v = E[e].v;
            if (N[u].d + 1 != N[v].d) continue;
            LL f = dfs(v, min(a, E[e].c - E[e].f));
            E[e].f += f, E[e ^ 1].f -= f, F += f, a -= f;
            if (!a) break;
        }
        return F;
    }
};
struct Edge { int u, v; LL c; };
typedef pair<int, int> pii;
void dfs(vector<vector<int> > &G, int u, vector<int> &ans) {
    while (G[u].size()) {
        int v = G[u].back();
        G[u].pop_back(); dfs(G, v, ans);
    }
    ans.push_back(u);
}
int main() {
    int n, m; cin >> n >> m;
    vector<int> deg(n, 0);
    vector<Edge> edges;
    for (int i = 0 ; i < m ; i++) {
        int u, v, wuv, wvu;
        cin >> u >> v >> wuv >> wvu;
        u--, v--; deg[u]++, deg[v]++;
        edges.push_back({1 + i, 1 + m + v, wuv});
        edges.push_back({1 + i, 1 + m + u, wvu});
    }
    LL L = -1, R = 1e3 + 5; while (R - L > 1) {
        int M = (R + L) >> 1;
        Graph *g = new Graph(2 + n + m);
        for (auto &e : edges)
            if (e.c <= M)
                g->addEdge(e.u, e.v, 1);
        for (int i = 0 ; i < m ; i++)
            g->addEdge(0, 1 + i, 1);
        for (int i = 0 ; i < n ; i++)
            g->addEdge(1 + m + i, 1 + n + m, deg[i] / 2);
        LL f = g->maxFlow(0, 1 + n + m);
        if (f == m)
            R = M;
        else
            L = M;
        delete g;
    }
    if (R == 1005) {
        cout << "NIE\n";
        exit(0);
    }
    Graph *g = new Graph(2 + n + m);
    for (auto &e : edges)
        if (e.c <= R)
            g->addEdge(e.u, e.v, 1);
    for (int i = 0 ; i < m ; i++)
        g->addEdge(0, 1 + i, 1);
    for (int i = 0 ; i < n ; i++)
        g->addEdge(1 + m + i, 1 + n + m, deg[i] / 2);
    g->maxFlow(0, 1 + n + m);
    vector<vector<int> > G(n);
    map<pii, int> Es;
    for (int i = 0 ; ; i += 2) {
        if (g->E[i].u == 0) break;
        if (g->E[i].f == 0) continue;
        int eIdx = (g->E[i].u - 1) * 2;
        if (edges[eIdx].v == g->E[i].v)
            eIdx ^= 1;
        int u = edges[eIdx].v - 1 - m;
        int v = g->E[i].v     - 1 - m;
        G[v].push_back(u);
        Es[{u, v}] = eIdx / 2 + 1;
    }
    cout << R << '\n';
    vector<int> ans;
    dfs(G, 0, ans);
    for (int i = 1 ; i < ans.size() ; i++)
        cout << Es[{ans[i - 1], ans[i]}] << " \n"[i + 1 == ans.size()];
    delete g;
}
