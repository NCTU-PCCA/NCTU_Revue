#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 1e5 + 5;
// LatexBegin
struct Graph { struct Node : vector<Node*> {
    int dfn, bcc; bool isC;
    Node() { dfn = bcc = -1; isC = false; }
  }_memN[MAXN], *node[MAXN]; int V, stamp, bcc_num;
  stack<pair<Node*, Node*> > stk;
  vector<vector<Node*> > BCC;
  Graph(int V) : V(V) {
    for (int i = 0 ; i < V ; i++) node[i] = _memN + i;
  }
  void addEdge(int u, int v) {
    node[u]->push_back(node[v]);
    node[v]->push_back(node[u]);
  }
  int Tarjan(Node *u, Node *pa) {
    int lowu = u->dfn = stamp++, son = 0;
    for (auto &v : *u) { 
      if (!~v->dfn) { son++; stk.push({u, v});
        int lowv = Tarjan(v, u); lowu = min(lowu,lowv);
        if (lowv >= u->dfn) { u->isC = true; 
          BCC.push_back({}); auto &it = BCC.back(); 
          while (1) { auto x = stk.top(); stk.pop();
            if (x.F->bcc != bcc_num)
              it.push_back(x.F), x.F->bcc = bcc_num;
            if (x.S->bcc != bcc_num)
              it.push_back(x.S), x.S->bcc = bcc_num;
            if (x.F == u && x.S == v) break;
          } bcc_num++;
        }
      } else if (v->dfn < u->dfn && v != pa)
        stk.push({u, v}), lowu = min(lowu, v->dfn);
    }
    if (!pa && son == 1) u->isC = false; return lowu;
  }
  int findBCC() { stamp = bcc_num = 0;
    for (int i = 0 ; i < V ; i++)
      if (!~node[i]->dfn)
        Tarjan(node[i], NULL);
    return bcc_num;
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  Graph *sol = new Graph(n);
  while (m--) {
    int u, v; cin >> u >> v;
    sol->addEdge(u, v);
  }
  sol->findBCC();
  auto BCC = sol->BCC;
  cout << BCC.size() << '\n';
  vector<vector<int> > ans;
  for (auto &vv : BCC) {
      ans.push_back({});
      for (auto &v : vv)
          ans.back().push_back(v - sol->_memN);
      sort(ans.back().begin(), ans.back().end());
  }
  sort(ans.begin(), ans.end());
  for (auto &vv : ans) {
      for (int i = 0 ; i < (int)vv.size() ; i++)
          cout << vv[i] << " \n"[i + 1 == (int)vv.size()];
  }
  delete sol;
}
