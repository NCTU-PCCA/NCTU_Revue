#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = (MAXN * MAXN) / 2;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
struct Graph { int n; struct Edge;
  struct Node : vector<Edge*> { int d;
  }_memN[MAXN], *node[MAXN], *s, *t;
  struct Edge { Node *v; Edge *r; LL c; Edge() {}
    Edge(Node *v, Edge *r, LL c) : v(v), r(r), c(c) {}
  }_memE[MAXM], *ptrE;
  inline void addEdge(int u, int v, LL c) {
    Edge *pos = ptrE;
    node[u]->emplace_back(new (ptrE++) Edge(node[v], pos + 1, c));
    node[v]->emplace_back(new (ptrE++) Edge(node[u], pos, c));
  }
  Graph (int n) : n(n) { ptrE = _memE;
    for (int i = 0 ; i < n ; i++)
      node[i] = _memN + i;
  }
  inline LL maxFlow(int _s, int _t) {
    s = node[_s]; t = node[_t]; LL flow = 0;
    while (bfs()) flow += dfs(s, INF);
    return flow;
  }
  inline bool bfs() {
    for (int i = 0 ; i < n ; i++)
      node[i]->d = -1;
    queue<Node*> q; q.push(s); s->d = 0;
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (auto &e : *u) {
        if (!e->c || ~e->v->d) continue;
        e->v->d = u->d + 1; q.push(e->v);
      }
    }
    return ~t->d;
  }
  LL dfs(Node *u, LL a) {
    if (u == t || !a) return a; LL flow = 0;
    for (auto &e : *u) {
      if (u->d + 1 != e->v->d) continue;
      LL f = dfs(e->v, min(e->c, a));
      e->c -= f; e->r->c += f;
      flow += f; a -= f;
    }
    return flow;
  }
};
// LatexEnd
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int kase = 0, n; while (cin >> n && n) {
    cout << "Network " << ++kase << '\n';
    Graph *G = new Graph(n);
    int s, t, m; cin >> s >> t >> m;
    while (m--) {
      int u, v; LL c;
      cin >> u >> v >> c;
      G->addEdge(u - 1, v - 1, c);
    }
    cout << "The bandwidth is " << G->maxFlow(s - 1, t - 1) << ".\n\n";
  }
}
