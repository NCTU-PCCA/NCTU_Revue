#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Dinic {
    struct Node : vector<int> { int d, p; };
    struct Edge { int u, v; LL c; };
    vector<Node> N; vector<Edge> E;
    void init(int n) {
        E.clear(); N.clear(); N.resize(n);
    }
    void addEdge(int u, int v, LL c) {
        int m = E.size();
        E.push_back({u, v, c}); N[u].push_back(m++);
        E.push_back({v, u, 0}); N[v].push_back(m++);
    }
    LL maxFlow(int s, int t) {
        LL flow = 0; while (bfs(s, t)) {
            for (auto &v : N) v.p = 0;
            flow += dfs(s, t, INF);
        }
        return flow;
    }
    bool bfs(int s, int t) {
        for (auto &v : N) v.d = -1;
        queue<int> q; q.push(s); N[s].d = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &e : N[u]) {
                int v = E[e].v;
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
            E[e].c -= f; E[e ^ 1].c += f; flow += f; a -= f;
            if (!a) break;
        }
        return flow;
    }
} G;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    G.init(n + m + 3);
    for (int i = 0 ; i < n ; i++) {
        G.addEdge(0, i + 1, 1);
        int num; cin >> num;
        while (num--) {
            int v; cin >> v;
            G.addEdge(i + 1, n + v, 1);
        }
    }
    for (int i = 0 ; i < m ; i++)
        G.addEdge(n + i + 1, n + m + 1, 1);
    G.addEdge(0, n + m + 2, k);
    for (int i = 0 ; i < n ; i++)
        G.addEdge(n + m + 2, i + 1, 1);
    cout << G.maxFlow(0, n + m + 1) << '\n';
}
