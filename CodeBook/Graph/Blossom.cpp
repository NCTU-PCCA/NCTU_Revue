#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250;
const int MAXM = MAXN * MAXN;
// LatexBegin
struct Graph { struct Edge; int V;
  struct Node : vector<Edge*> {
    Node *p, *s, *m; int S, v;
    Node() : S(-1), v(-1) { p = s = m = NULL; }
  }_memN[MAXN], *node[MAXN];
  struct Edge { Node *v;
    Edge(Node *v = NULL) : v(v) {}
  }_memE[MAXM], *ptrE;
  Graph (int V) : V(V) { ptrE = _memE;
    for (int i = 0 ; i < V ; i++) node[i] = _memN + i;
  }
  void addEdge(int u, int v) {
    node[u]->push_back(new (ptrE++) Edge(node[v]));
    node[v]->push_back(new (ptrE++) Edge(node[u]));
  }
  inline int maxMatch() { int ans = 0;
    for (int i = 0 ; i < V ; i++)
      if (!node[i]->m && bfs(node[i])) ans++;
    return ans;
  }
  inline bool bfs(Node *u) {
    for (int i = 0 ; i < V ; i++)
      node[i]->s = node[i], node[i]->S = -1;
    queue<Node*> q; q.push(u), u->S = 0;
    while (q.size()) { u = q.front(); q.pop();
      for (auto &e : *u) { Node *v = e->v;
        if (!~v->S) { v->p = u; v->S = 1;
          if (!v->m) return augment(u, v);
          q.push(v->m); v->m->S = 0;
        } else if (!v->S && v->s != u->s) {
          Node *l = LCA(v->s, u->s);
          flower(v, u, l, q); flower(u, v, l, q);
        }
      }
    }
    return false;
  }
  inline bool augment(Node *u, Node *v) {
    for (Node *l; u; v = l, u = v ? v->p : NULL) 
      l = u->m, u->m = v, v->m = u;
    return true;
  }
  inline Node* LCA(Node *u, Node *v) {
    static int t = 0;
    for (++t ; ; swap(u, v)) {
      if (!u) continue; if (u->v == t) return u;
      u->v = t; u = u->m; if (!u) continue;
      u = u->p; if (!u) continue; u = u->s;
    }
  }
  inline void flower(Node *u, Node *v, Node *l, queue<Node*> &q) {
    while (u->s != l) { u->p = v; v = u->m;
      if (v->S == 1) q.push(v), v->S = 0;
      u->s = v->s = l; u = v->p;
    }
  }
// LatexEnd
  void Print() {
    for (int i = 0 ; i < V ; i++) {
      if (!node[i]->m) continue;
      if (node[i]->m - _memN >= i)
        cout << i + 1 << ' ' << node[i]->m - _memN + 1 << '\n';
    }
  }
// LatexBegin
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  Graph *G = new Graph(n);
  int u, v; while (cin >> u >> v) G->addEdge(u - 1, v - 1);
  cout << G->maxMatch() * 2 << '\n';
  G->Print();
  delete G;
}
