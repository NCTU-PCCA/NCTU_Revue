#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
// LatexBegin
struct VertexBCC { int stamp, bcc_num;
  struct Node : vector<int> { int dfn, bcc; bool isC;
    Node() { dfn = bcc = -1, isC = false; }
  };
  vector<Node> N; vector<pii> stk;
  vector<vector<int> > BCC;
  void init(int n) {
    BCC.clear(); N.clear(); N.resize(n);
  }
  void addEdge(int u, int v) {
    N[u].push_back(v); N[v].push_back(u);
  }
  int Tarjan(int u, int p) {
    int lowu = N[u].dfn = stamp++, son = 0;
    for (auto &v : N[u]) if (!~N[v].dfn) {
      son++, stk.push_back({u, v});
      int lowv = Tarjan(v, u); lowu = min(lowu, lowv);
      if (lowv >= N[u].dfn) { N[u].isC = true;
        BCC.push_back({}); auto &B = BCC.back();
        while (1) { auto x=stk.back(); stk.pop_back();
          if (N[x.F].bcc != bcc_num)
            B.push_back(x.F), N[x.F].bcc = bcc_num;
          if (N[x.S].bcc != bcc_num)
            B.push_back(x.S), N[x.S].bcc = bcc_num;
          if (x.F == u && x.S == v) break;
        } bcc_num++;
      }
    } else if (N[v].dfn < N[u].dfn && v != p)
      stk.push_back({u, v}), lowu = min(lowu,N[v].dfn);
    if (!~p && son == 1) N[u].isC = false; return lowu;
  }
  void run() { stamp = bcc_num = 0;
    for (int i = 0 ; i < N.size() ; i++)
      if (!~N[i].dfn) Tarjan(i, -1);
  }
} solver;
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  solver.init(n);
  while (m--) {
    int u, v; cin >> u >> v;
    solver.addEdge(u, v);
  }
  solver.run();
  auto BCC = solver.BCC;
  cout << BCC.size() << '\n';
  vector<vector<int> > ans;
  for (auto &vv : BCC) {
      ans.push_back({});
      for (auto &v : vv)
          ans.back().push_back(v);
      sort(ans.back().begin(), ans.back().end());
  }
  sort(ans.begin(), ans.end());
  for (auto &vv : ans) {
      for (int i = 0 ; i < (int)vv.size() ; i++)
          cout << vv[i] << " \n"[i + 1 == (int)vv.size()];
  }
}
