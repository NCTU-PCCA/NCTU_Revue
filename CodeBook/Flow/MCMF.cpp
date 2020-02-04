#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
struct MCMF {
  struct Node : vector<int> { int inq, p; LL a, d; };
  struct Edge { int u, v; LL c, co; };
  vector<Node> N; vector<Edge> E;
  void init(int n) {
    E.clear(); N.clear(); N.resize(n);
  }
  void addEdge(int u, int v, LL c, LL co) {
    int m = E.size();
    N[u].push_back(m++); E.push_back({u, v, c, co});
    N[v].push_back(m++); E.push_back({v, u, 0, -co});
  }
  pLL maxFlowMinCost(int s, int t) {
    pLL fc = {0, 0}; while (SPFA(s, t)) {
      LL f; update(s, t, f = N[t].a);
      fc.F += f; fc.S += f * N[t].d;
    }
    return fc;
  }
  bool SPFA(int s, int t) {
    for (auto &v : N) v.d = INF, v.inq = false;
    queue<int> q; q.push(s);  N[s].inq = 1; 
    N[s].d = 0; N[s].p = -1; N[s].a = INF;
    while (q.size()) {
      int u = q.front(); q.pop(); N[u].inq = 0;
      for (auto &e : N[u]) { int v = E[e].v; 
        LL d = N[u].d+E[e].co, a = min(N[u].a,E[e].c);
        if (!E[e].c || N[v].d <= d) continue;
        N[v].p = e; N[v].a = a; N[v].d = d;
        if (!N[v].inq) q.push(v), N[v].inq = 1;
      }
    }
    return N[t].d != INF;
  }
  void update(int s, int t, LL f) {
    for (int u = t ; u != s ; u = E[N[u].p].u)
      E[N[u].p].c -= f, E[N[u].p ^ 1].c += f;
  }
};
// LatexEnd
MCMF G;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, m; cin >> n >> m;
    G.init(n + m + 2);
    for (int i = 1 ; i <= n ; i++) {
      G.addEdge(0, i, 1, 0);
      for (int j = 1 ; j <= m ; j++) {
        LL tmp; cin >> tmp;
        if (tmp) G.addEdge(i, j + n, 1, tmp);
      }
    }
    for (int i = 1 ; i <= m ; i++) {
      LL tmp; cin >> tmp;
      G.addEdge(n + i, n + m + 1, tmp, 0);
    }
    pLL ans = G.maxFlowMinCost(0, n + m + 1);
    if (ans.F == n) cout << ans.S << '\n';
    else cout << -1 << '\n';
  }
}
