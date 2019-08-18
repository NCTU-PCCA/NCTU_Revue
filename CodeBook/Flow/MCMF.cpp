#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long LL;
typedef pair<LL, LL> pLL;
const int MAXN = 300;
const int MAXM = MAXN * MAXN * 2;
const LL INF = 0x3f3f3f3f3f3f3f3f;
// LatexBegin
struct Graph {
  struct Node; struct Edge; int V;
  struct Node : vector<Edge*> {
    bool inq; Edge *pa; LL a, d;
    Node() { clear(); }
  }_memN[MAXN], *node[MAXN];
  struct Edge{
    Node *u, *v; Edge *rev;
    LL c, f, _c; Edge() {}
    Edge(Node *u, Node *v, LL c, LL _c, Edge *rev) 
      : u(u), v(v), c(c), f(0), _c(_c), rev(rev) {}
  }_memE[MAXM], *ptrE;
  Graph(int _V) : V(_V) {
    for (int i = 0 ; i < V ; i++)
      node[i] = _memN + i;
    ptrE = _memE;
  }
  void addEdge(int u, int v, LL c, LL _c) {
    *ptrE = Edge(node[u], node[v], c, _c, ptrE + 1);
    node[u]->push_back(ptrE++);
    *ptrE = Edge(node[v], node[u], 0, -_c, ptrE - 1);
    node[v]->push_back(ptrE++);
  }
  Node *s, *t;
  bool SPFA() {
    for (int i = 0 ; i < V ; i++) 
      node[i]->d = INF, node[i]->inq = false;
    queue<Node*> q; q.push(s); s->inq = true;
    s->d = 0, s->pa = NULL, s->a = INF;
    while (q.size()) {
      Node *u = q.front(); q.pop(); u->inq = false;
      for (auto &e : *u) {
        Node *v = e->v;
        if (e->c > e->f && v->d > u->d + e->_c) {
          v->d = u->d + e->_c;
          v->pa = e; v->a = min(u->a, e->c - e->f);
          if (!v->inq) q.push(v), v->inq = true;
        }
      }
    }
    return t->d != INF;
  }
  pLL maxFlowMinCost(int _s, int _t) {
    s = node[_s], t = node[_t];
    pLL res = {0, 0};
    while (SPFA()) {
      res.F += t->a;
      res.S += t->d * t->a;
      for (Node *u = t ; u != s ; u = u->pa->u) {
        u->pa->f += t->a;
        u->pa->rev->f -= t->a;
      }
    }
    return res;
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, m; cin >> n >> m;
    Graph *G = new Graph(n + m + 2);
    for (int i = 1 ; i <= n ; i++) {
      G->addEdge(0, i, 1, 0);
      for (int j = 1 ; j <= m ; j++) {
        LL tmp; cin >> tmp;
        if (tmp) G->addEdge(i, j + n, 1, tmp);
      }
    }
    for (int i = 1 ; i <= m ; i++) {
      LL tmp; cin >> tmp;
      G->addEdge(n + i, n + m + 1, tmp, 0);
    }
    pLL ans = G->maxFlowMinCost(0, n + m + 1);
    if (ans.F == n) cout << ans.S << '\n';
    else cout << -1 << '\n';
    delete G;
  }
}

