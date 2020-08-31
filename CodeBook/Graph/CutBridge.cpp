#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
// LatexBegin
struct Graph { int st, n;
  struct Node : vector<int> { int low, dfn, p; };
  vector<Node> N;
  void init(int _n) { N.assign(n = _n, {});}
  void addEdge(int u, int v) {N[u].PB(v);N[v].PB(u);}
  void Tarjan(int u, int p) {
    N[u].p = p; N[u].dfn = N[u].low = ++st;
    for (auto &v : N[u]) if (!N[v].dfn) Tarjan(v, u),
      N[u].low = min(N[u].low, N[v].low);
    else if (p != v) N[u].low = min(N[u].low,N[v].dfn);
  }
  void run() { for (int i = 0, st = 0 ; i < n ; i++)
      if (!N[i].dfn) Tarjan(i, i);
  }
  set<int> cuts() { set<int> ret; map<int, int> rt;
    for (int i = n - 1 ; ~i ; i--) { int p = N[i].p;
      if (p == i) { if (rt[i] > 1) ret.insert(i); 
      } else if (p == N[p].p) rt[p]++;
      else if (N[i].low >= N[p].dfn) ret.insert(p);
    }
    return ret;
  }
  set<pii> bridges() { set<pii> ret;
    for (int i = 0, p ; i < n ; i++)
      if ((p = N[i].p) != i && N[i].low > N[p].dfn)
        ret.insert({min(p, i), max(p, i)});
    return ret;
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; while (cin >> n >> m && n) {
    Graph solver; solver.init(n);
    while (m--) {
      int u, v; cin >> u >> v;
      solver.addEdge(u, v);
    }
    solver.run();

    auto cut = solver.cuts();
    cout << cut.size();
    for (auto &v : cut)
      cout << ' ' << v;
    cout << '\n';

    auto bridge = solver.bridges();
    cout << bridge.size();
    for (auto &p : bridge)
      cout << ' ' << p.F << ' ' << p.S;
    cout << '\n';
  }
}
