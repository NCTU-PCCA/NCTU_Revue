#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int lgN = __lg(MAXN) + 5;
typedef long long LL;
// LatexBegin
struct Tree { int V; struct Edge;
  struct Node : vector<Edge*> {
    Node *p[lgN]; LL w[lgN], dep;
  }_memN[MAXN], *node[MAXN], *rt;
  struct Edge { Node *v; LL w; }_memE[MAXN], *ptrE;
  Tree(int V) : V(V) { ptrE = _memE; rt = node[0];
    for (int i = 0 ; i < V ; i++) node[i] = _memN + i;
  }
  void addEdge(int u, int v, LL w) {
    node[u]->push_back(new (ptrE++)Edge{node[v], w});
    node[v]->push_back(new (ptrE++)Edge{node[u], w});
  }
  void run() { dfs(node[0], node[0], -1, 0); }
  void dfs(Node* u, Node* p, LL w, int dep) {
    u->p[0] = p, u->w[0] = w, u->dep = dep;
    for (int i = 1 ; i < lgN ; i++)
      u->p[i] = u->p[i - 1]->p[i - 1],
      u->w[i] = max(u->w[i-1], u->p[i-1]->w[i-1]);
    for (auto &e : *u)
      if (e->v != p) dfs(e->v, u, e->w, dep + 1);
  }
  LL query(int _u, int _v) {
    Node *u = node[_u], *v = node[_v]; LL ret = -1;
    if (u->dep < v->dep) swap(u, v);
    for (int i = lgN - 1 ; ~i ; i--)
      if (u->p[i]->dep >= v->dep)
        ret = max(ret, u->w[i]), u = u->p[i];
    if (u == v) return ret;
    for (int i = lgN - 1 ; ~i ; i--)
      if (u->p[i] != v->p[i])
        ret = max({ret, u->w[i], v->w[i]}),
        u = u->p[i], v = v->p[i];
    return ret = max({ret, u->w[0], v->w[0]});
  } 
};
// LatexEnd
struct DJS { vector<int> pa; int n;
  DJS(int n) : n(n) { pa.assign(n + 1, -1); }
  int find(int x) { return pa[x] < 0 ? x : pa[x] = find(pa[x]); }
  bool merge(int u, int v) {
    int x = find(u), y = find(v);
    if (x == y) return false;
    if (pa[x] < pa[y]) swap(x, y);
    pa[y] += pa[x], pa[x] = y;
    return true;
  }
};
struct Edge {
  int u, v; LL w; int idx; bool inT; LL ans;
  bool operator < (const Edge &rhs) {
    return w < rhs.w;
  }
};
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0 ; i < m ; i++) {
    int u, v; LL w; cin >> u >> v >> w; u--, v--;
    edges.push_back({u, v, w, i, false, 0});
  }
  sort(edges.begin(), edges.end());
  Tree *sol = new Tree(n);
  DJS *djs = new DJS(n); LL W = 0;
  for (auto &e : edges) {
    if (!djs->merge(e.u, e.v)) continue;
    W += e.w; e.inT = true;
    sol->addEdge(e.u, e.v, e.w);
  }
  sol->run();
  sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
    return a.idx < b.idx;
  });
  for (auto &e : edges) {
    if (e.inT) cout << W << '\n';
    else 
      cout << W - sol->query(e.u, e.v) + e.w << '\n';
  }
  delete djs; delete sol;
}
