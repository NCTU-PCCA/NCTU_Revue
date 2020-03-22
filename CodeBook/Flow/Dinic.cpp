#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
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
    flow = 0; while (bfs(s, t)) flow += dfs(s,t,INF);
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
    for (int &p = N[u].p; p < N[u].size() ; p++) {
      auto e = N[u][p], v = E[e].v;
      if (N[u].d + 1 != N[v].d) continue;
      LL f = dfs(v, t, min(a, E[e].c));
      E[e].c -= f; E[e ^ 1].c += f; flow += f; a -= f;
      if (!a) break;
    }
    return flow;
  }
} solver;
// LatexEnd
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int kase = 0, n; while (cin >> n && n) {
    cout << "Network " << ++kase << '\n';
    solver.init(n);
    int s, t, m; cin >> s >> t >> m; s--, t--;
    while (m--) {
      int u, v; LL c;
      cin >> u >> v >> c;
      solver.addEdge(u - 1, v - 1, c);
      solver.addEdge(v - 1, u - 1, c);
    }
    solver.run(s, t);
    cout << "The bandwidth is " << solver.flow << ".\n\n";
  }
}
