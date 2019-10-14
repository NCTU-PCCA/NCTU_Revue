#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = (MAXN * MAXN) / 2;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
struct Graph{ struct Edge; int V;
  struct Node : vector<Edge*>{
    iterator cur; int d; Node(){ clear(); }
  }_memN[MAXN], *node[MAXN], *s, *t;
  struct Edge{ Node *u, *v; Edge *rev; LL c, f;
    Edge(Node *u, Node *v, LL c, Edge *rev)
        : u(u), v(v), c(c), f(0), rev(rev){} Edge(){}
  }_memE[MAXM], *ptrE;
  Graph(int _V) : V(_V) { ptrE = _memE;
    for (int i = 0 ; i < V ; i++) node[i] = _memN + i;
  }
  void addEdge(int _u, int _v, LL _c){
    *ptrE = Edge(node[_u], node[_v], _c, ptrE + 1);
    node[_u]->push_back(ptrE++);
    *ptrE = Edge(node[_v], node[_u],  0, ptrE - 1);
    node[_v]->push_back(ptrE++);
  }
  LL maxFlow(int _s, int _t){
    s = node[_s], t = node[_t]; LL flow = 0;
    while (bfs()) {
      for (int i = 0 ; i < V ; i++)
        node[i]->cur = node[i]->begin();
      flow += dfs(s, INF);
    }
    return flow;
  }
  bool bfs(){
    for (int i = 0 ; i < V ; i++) node[i]->d = -1;
    queue<Node*> q; q.push(s); s->d = 0;
    while (q.size()) { Node *u = q.front(); q.pop();
      for (auto e : *u) { Node *v = e->v;
        if (!~v->d && e->c > e->f)
          q.push(v), v->d = u->d + 1;
      }
    }
    return ~t->d;
  }
  LL dfs(Node *u, LL a){
    if (u == t || !a) return a; LL flow = 0, f;
    for (; u->cur != u->end() ; u->cur++) {
      auto &e = *u->cur; Node *v = e->v;
      if (u->d + 1 == v->d
        && (f = dfs(v, min(a, e->c - e->f))) > 0) {
        e->f += f; e->rev->f -= f; flow += f; a -= f;
        if (!a) break;
      }
    }
    return flow;
  }
};
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        Graph *sol = new Graph(n + m + 2);
        int P = 0;
        for (int i = 0 ; i < n ; i++) {
            int c; cin >> c;
            sol->addEdge(0, i + 1, c);
        }
        for (int i = 0 ; i < m ; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            sol->addEdge(u, 1 + n + i, INF);
            sol->addEdge(v, 1 + n + i, INF);
            sol->addEdge(1 + n + i, 1 + n + m, p);
            P += p;
        }
        cout << P - sol->maxFlow(0, 1 + n + m) << '\n';
        delete sol;
    }
}
