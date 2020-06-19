#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
};
// LatexBegin
struct _2Sat : SCC {
  void init(int n) { SCC::init(2 * n); }
  /* addCond(0, 0, 1, 1) -> v0 or !v1*/
  void addCond(int o1, int v1, int o2, int v2) {
    addEdge((v1 << 1) | (o1 ^ 1), (v2 << 1) | o2);
    addEdge((v2 << 1) | (o2 ^ 1), (v1 << 1) | o1);
  }
  bool check() {
    for (int i = 0 ; i < N.size() ; i += 2)
      if (N[i].scc == N[i ^ 1].scc) return false;
    return true;
  }
  vector<int> construct() { vector<int> ret;
    for (int i = 0 ; i < N.size() ; i += 2)
      ret.push_back(N[i].scc < N[i ^ 1].scc);
    return assert(check()), ret;
  }
} solver;
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> m >> n;
    solver.init(n);
    while (m--) {
        string n1, n2; int v1, v2;
        cin >> n1 >> v1 >> n2 >> v2; v1--, v2--;
        solver.addCond(n1 != "+", v1, n2 != "+", v2);
    }
    solver.run();
    if (solver.check()) {
        for (auto &v : solver.construct())
            cout << "-+"[v] << ' ';
        cout << '\n';
    } else
        cout << "IMPOSSIBLE\n";
}
