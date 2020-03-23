#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<int, int> pii;
struct Dinic {
  struct Node : vector<int> { int d, p; };
  struct Edge { int u, v; LL c; };
  vector<Node> N; vector<Edge> E;
  void init(int n) {
    E.clear(); N.clear(); N.resize(n);
  }
  void addEdge(int u, int v, LL c) { int m = E.size();
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
      for (auto &e : N[u]) { int v = E[e].v;
        if (!~N[v].d && E[e].c)
          q.push(v), N[v].d = N[u].d + 1;
      }
    }
    return ~N[t].d;
  }
  LL dfs(int u, int t, LL a) {
    if (u == t || !a) return a; LL flow = 0;
    for (int &p = N[u].p; p < N[u].size() ; p++) {
      auto e = N[u][p], v = E[e].v;
      if (N[u].d + 1 != N[v].d) continue;
      LL f = dfs(v, t, min(a, E[e].c));
      E[e].c -= f; E[e ^ 1].c += f; flow += f; a -= f;
      if (!a) break;
    }
    return flow;
  }
};
Dinic G;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    int m; cin >> m;
    vector<int> cap(m);
    for (auto &p : cap)
        cin >> p;
    G.init(2 * n + 2 + m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j)
                G.addEdge(2 * i + 0, 2 * j + 1, 1);
            else {
                if (data[i].S >= data[j].F)
                    G.addEdge(2 * i + 1, 2 * j + 0, 1);
            }
        }
        for (int j = 0 ; j < m ; j++) {
            if (data[i].S >= cap[j])
                G.addEdge(2 * i + 1, j + 2 * n, 1);
        }
        if (data[i].F == 0)
            G.addEdge(2 * n + m, 2 * i, 1);
    }
    for (int i = 0 ; i < m ; i++)
        G.addEdge(i + 2 * n, 2 * n + m + 1, 1);
    int f = G.maxFlow(2 * n + m, 2 * n + m + 1);
    if (f != m)
        cout << "impossible\n";
    else {
        vector<pii> edges;
        int E = G.E.size();
        for (int i = 0 ; i < E ; i += 2)
            if (G.E[i].c == 0)
                edges.push_back({G.E[i].u, G.E[i].v});
        vector<int> pa(n + m + 1, -1);
        for (auto &e : edges) {
            if (e.S == 2 * n + m + 1)
                continue;
            if (e.F / 2 == e.S / 2)
                continue;
            int u, v;
            if (e.F == 2 * n + m)
                u = 0;
            else
                u = e.F / 2 + 1;
            if (e.S < 2 * n)
                v = e.S / 2 + 1;
            else
                v = e.S - n + 1;
            pa[v] = u;
        }
        vector<vector<int> > ans(m);
        for (int i = 0 ; i < m ; i++) {
            int cur = pa[i + n + 1];
            while (cur != 0)
                ans[i].push_back(cur), cur = pa[cur];
            reverse(ans[i].begin(), ans[i].end());
            for (int j = 0 ; j < ans[i].size() ; j++)
                cout << ans[i][j] << " \n"[j + 1 == ans[i].size()];
        }
    }
}
