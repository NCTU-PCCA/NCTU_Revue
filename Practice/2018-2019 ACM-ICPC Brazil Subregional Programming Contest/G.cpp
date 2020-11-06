#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Dinic { LL flow;
    struct Node : vector<int> { int d, p; };
    struct Edge { int u, v; LL c; };
    vector<Node> N; vector<Edge> E;
    void init(int n) {
        E.clear(); N.clear(); N.resize(n); flow = 0;
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
            E[e].c -= f; E[e ^ 1].c += f; flow += f; a -= f;
            if (!a) break;
        }
        return flow;
    }
} solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<int> n1c(n1), n2c(n2);
    LL tot = 0;
    for (auto &v : n1c)
        cin >> v, tot += v;
    for (auto &v : n2c)
        cin >> v;
    vector<pair<pair<int, int>, int>> E(m);
    int L = 0x3f3f3f3f, R = 0;
    for (auto &p : E) {
        cin >> p.F.F >> p.F.S >> p.S;
        p.F.F--, p.F.S--;
        L = min(L, p.S);
        R = max(R, p.S);
    }
    L--, R++; int maxV = R;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        solver.init(n1 + n2 + 2);
        for (int i = 0 ; i < n1 ; i++)
            solver.addEdge(0, 1 + i, n1c[i]);
        for (int i = 0 ; i < n2 ; i++)
            solver.addEdge(1 + n1 + i, 1 + n1 + n2, n2c[i]);
        for (auto &p : E) {
            if (p.S > M)
                continue;
            solver.addEdge(1 + p.F.F, 1 + n1 + p.F.S, INF);
        }
        solver.run(0, 1 + n1 + n2);
        if (solver.flow == tot) {
            R = M;
        } else
            L = M;
    }
    if (R == maxV) {
        cout << -1 << '\n';
    } else 
        cout << R << '\n';
}
