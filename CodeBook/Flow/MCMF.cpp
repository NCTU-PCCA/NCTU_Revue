#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<LL, LL> pLL;
// LatexBegin
struct MCMF {
  struct Node : vector<int> { 
    int p; bool inq;
    LL a, d;
  };
  struct Edge { int u, v; LL c, co; };
  vector<Node> N; vector<Edge> E;
  void init(int n) { N.clear(); N.resize(n); E.clear(); }
  void addEdge(int u, int v, LL c, LL co) { int m = E.size();
    E.push_back({u, v, c, co}); N[u].push_back(m++); 
    E.push_back({v, u, 0, -co}); N[v].push_back(m++);
  }
  pLL maxFlowMinCost(int s, int t) {
    pLL res = {0, 0};
    while (SPFA(s, t)) {
      res.F += N[t].a;
      res.S += N[t].d * N[t].a;
      for (int u = t ; u != s ; u = E[N[u].p].u) {
        E[N[u].p].c -= N[t].a;
        E[N[u].p ^ 1].c += N[t].a;
      }
    }
    return res;
  }
  bool SPFA(int s, int t) {
    for (auto &v : N)
      v.d = INF, v.inq = false;
    queue<int> q; q.push(s); N[s].inq = true;
    N[s].d = 0, N[s].p = -1, N[s].a = INF;
    while (q.size()) {
      int u = q.front(); q.pop(); N[u].inq = false;
      for (auto &e : N[u]) {
        int v = E[e].v;
        if (!E[e].c || N[v].d <= N[u].d + E[e].co)
          continue;
        N[v].d = N[u].d + E[e].co;
        N[v].p = e; N[v].a = min(N[u].a, E[e].c);
        if (!N[v].inq) q.push(v), N[v].inq = true;
      }
    }
    return N[t].d != INF;
  }
};
// LatexEnd
MCMF mcmf;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, m; cin >> n >> m;
    mcmf.init(n + m + 2);
    for (int i = 1 ; i <= n ; i++) {
      mcmf.addEdge(0, i, 1, 0);
      for (int j = 1 ; j <= m ; j++) {
        LL tmp; cin >> tmp;
        if (tmp) mcmf.addEdge(i, j + n, 1, tmp);
      }
    }
    for (int i = 1 ; i <= m ; i++) {
      LL tmp; cin >> tmp;
      mcmf.addEdge(n + i, n + m + 1, tmp, 0);
    }
    pLL ans = mcmf.maxFlowMinCost(0, n + m + 1);
    if (ans.F == n) cout << ans.S << '\n';
    else cout << -1 << '\n';
  }
}
