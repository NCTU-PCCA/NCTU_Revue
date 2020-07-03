#include <bits/stdc++.h>
#define PB push_back
using namespace std;
// LatexBegin
struct DominatorTree {
  struct Node : vector<int> {
    int dfn, p, sdom, idom, mom, mn; vector<int> P, C;
    Node () { dfn = p = idom = -1; }
  };
  vector<Node> N; int ts; vector<int> nfd;
  void init(int n){N.assign(n, Node());nfd.clear();}
  void addEdge(int u,int v){N[u].PB(v);N[v].P.PB(u);}
  void dfs(int u) { N[u].dfn = ts++; nfd.PB(u);
    for (auto &v:N[u]) if(!~N[v].dfn) N[v].p=u, dfs(v);
  }
  bool cmp(int u, int v) { return N[u].dfn<N[v].dfn; }
  int eval(int u) { if (N[u].mom == u) return u;
    int res = eval(N[u].mom);
    if (cmp(N[N[N[u].mom].mn].sdom, N[N[u].mn].sdom))
      N[u].mn = N[N[u].mom].mn; return N[u].mom = res;
  }
  void run(int s) { ts = 0; dfs(s);
    for (int i = 0 ; i < N.size() ; i++) 
      N[i].sdom = N[i].mom = N[i].mn = i;
    for (int i = ts - 1 ; i ; i--) {
      int u = nfd[i]; if (!u) continue;
      for (auto &v : N[u].P) if (~N[v].dfn) { eval(v);
        if (cmp(N[N[v].mn].sdom, N[u].sdom))
          N[u].sdom = N[N[v].mn].sdom;
      }
      N[N[u].sdom].C.PB(u); N[u].mom = N[u].p;
      for (auto &v : N[N[u].p].C) eval(v), N[v].idom
        = cmp(N[N[v].mn].sdom,N[u].p) ? N[v].mn:N[u].p;
      N[N[u].p].C.clear();
    }
    for (int i = 1 ; i < ts ; i++) { int u = nfd[i]; 
      if (!u || N[u].idom == N[u].sdom) continue;
      N[u].idom = N[N[u].idom].idom;
    }
  }
} solver;
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  solver.init(n);
  while (m--) {
    int u, v; cin >> u >> v; u--, v--;
    solver.addEdge(u, v);
  }
  solver.run(0);
  int u = n - 1; vector<int> ans;
  while (~u) {
    ans.push_back(u + 1);
    u = solver.N[u].idom;
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto &v : ans)
    cout << v << ' ';
  cout << '\n';
}
