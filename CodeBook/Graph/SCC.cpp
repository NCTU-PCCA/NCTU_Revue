#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
// LatexBegin
struct SCC { int stamp, scc_num;
  struct Node : vector<int> { 
    int dfn, low, scc; bool inS;
    Node() { dfn = low = scc = -1; inS = false; }
  };
  vector<Node> N; vector<int> stk;
  void init(int n) { 
    N.clear(); N.resize(n); stk.clear();
  }
  void addEdge(int u, int v) { N[u].push_back(v); }
  void Tarjan(int u) { N[u].low = N[u].dfn = stamp++;
    stk.push_back(u); N[u].inS = true;
    for (auto &v : N[u]) if (!~N[v].dfn) Tarjan(v),
      N[u].low = min(N[u].low, N[v].low);
    else if (N[v].inS)
      N[u].low = min(N[u].low, N[v].dfn);
    if (N[u].dfn == N[u].low) {
      int v; do { v = stk.back(); stk.pop_back();
        N[v].scc = scc_num; N[v].inS = false;
      } while (v != u); scc_num++;
    }
  }
  void run() { stamp = scc_num = 0;
    for (int i = 0 ; i < N.size() ; i++)
      if (!~N[i].dfn) Tarjan(i);
  }
} solver;
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; while (cin >> n >> m && n) {
    solver.init(n);
    while (m--) {
      int u, v; cin >> u >> v; u--, v--;
      solver.addEdge(u, v);
    }
    solver.run();
    if (solver.scc_num == 1)
      cout << "Yes\n";
    else 
      cout << "No\n";
  }
}
