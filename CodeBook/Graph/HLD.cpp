#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const int lgN = __lg(MAXN) + 5;
struct SegmentTree {
  struct Node {
    int L, R;
    Node *l, *r;
    int v; int add;
    Node (int _L = 0, int _R = 0) {
      L = _L, R = _R;
      l = r = NULL;
      v = add = 0;
    }
  }*rt, buf[lgN << 1], *ptr;
  int *arr, n;
  SegmentTree (int *_arr, int _n) {
    arr = _arr, n = _n;
    rt = build(0, n);
  }
  ~SegmentTree() {
    remove(rt);
  }
  void remove(Node *u) {
    if (!u) return ;
    remove(u->l); remove(u->r);
    delete u;
  }
  Node* build(int L, int R) {
    Node *u = new Node(L, R);
    if (R - L == 1) {
      u->v = arr[L];
      return u;
    }
    int M = (R + L) >> 1;
    u->l = build(L, M);
    u->r = build(M, R);
    return pull(u);
  }
  inline Node* pull(Node *u) {
    return pull(u, u->l, u->r);
  }
  inline Node* pull(Node *u, Node *l, Node *r) {
    if (!l || !r) return l ? l : r;
    push(l), push(r);
    return u;
  }
  inline Node* push(Node *u) {
    if (!u) return u;
    if (u->add) {
      u->v += u->add;
      if (u->l) u->l->add += u->add;
      if (u->r) u->r->add += u->add;
      u->add = 0;
    }
    return u;
  }
  inline void modify(int mL, int mR, int v) {
    return modify(mL, mR, v, rt);
  }
  void modify(int mL, int mR, int v, Node *u) {
    if (u->R <= mL || mR <= u->L) return ;
    if (mL <= u->L && u->R <= mR) {
      u->add += v;
      return ;
    }
    push(u);
    modify(mL, mR, v, u->l);
    modify(mL, mR, v, u->r);
    pull(u);
  }
  inline Node* query(int qPos) {
    ptr = buf;
    return query(qPos, rt);
  }
  Node* query(int qPos, Node *u) {
    if (u->R <= qPos || qPos + 1 <= u->L) return (Node*)NULL;
    push(u);
    if (qPos <= u->L && u->R <= qPos + 1) return u;
    return pull(ptr++, query(qPos, u->l), query(qPos, u->r));
  }
};
// LatexBegin
struct Tree {
  int V;
  struct Node : vector<Node*> {
    int sz, dep, dfn;
    Node *pa, *top, *hc;
  }_memN[MAXN], *node[MAXN], *rt;
  Tree(int _V) : V(_V) {
    for (int i = 0 ; i < V ; i++)
      node[i] = _memN + i;
    rt = node[0];
  }
  inline void addEdge(int u, int v) {
    node[u]->push_back(node[v]);
    node[v]->push_back(node[u]);
  }
  int stamp;
  inline void HLD() {
    stamp = 0;
    dfs_size(rt);
    dfs_link(rt, rt);
  }
  void dfs_size(Node *u) {
    u->sz = 1; u->hc = NULL;
    for (auto v : *u) {
      if (v == u->pa) continue;
      v->pa = u;
      v->dep = u->dep + 1;
      dfs_size(v);
      if (!u->hc || v->sz > u->hc->sz)
        u->hc = v;
      u->sz += v->sz;
    }
  }
  void dfs_link(Node *u, Node *_top) {
    u->dfn = stamp++;
    u->top = _top;
    if (!u->hc) return ;
    dfs_link(u->hc, _top);
    for (auto v : *u) {
      if (v == u->hc || v == u->pa) continue;
      dfs_link(v, v);
    }
  }
  SegmentTree *seg;
  inline void modify(int _u, int _v, int add) {
    Node *u = node[_u], *v = node[_v];
    Node *uTop = u->top, *vTop = v->top;
    while (uTop != vTop) {
      if (uTop->dep < vTop->dep)
        swap(u, v), swap(uTop, vTop);
      seg->modify(uTop->dfn, u->dfn + 1, add);
      uTop = (u = uTop->pa)->top;
    }
    if (u->dep > v->dep) swap(u, v);
    seg->modify(u->dfn, v->dfn + 1, add);
    return ;
  }
  inline int query(int qPos) {
    return seg->query(node[qPos]->dfn)->v;
  }
};
// LatexEnd
int main() { ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m, q; while (cin >> n >> m >> q) {
    int a[MAXN];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    Tree *G = new Tree(n);
    for (int i = 0 ; i < n - 1 ; i++) {
      int u, v; cin >> u >> v; u--, v--;
      G->addEdge(u, v);
    }
    G->HLD();
    int arr[MAXN];
    for (int i = 0 ; i < n ; i++)
      arr[G->node[i]->dfn] = a[i];
    SegmentTree *seg = new SegmentTree(arr, n);
    G->seg = seg;
    while (q--) {
      char op; cin >> op;
      if (op == 'I') {
        int u, v, k; cin >> u >> v >> k;
        u--, v--;
        G->modify(u, v, k);
      }
      if (op == 'D') {
        int u, v, k; cin >> u >> v >> k;
        u--, v--;
        G->modify(u, v, -k);
      }
      if (op == 'Q') {
        int pos; cin >> pos;
        pos--;
        cout << G->query(pos) << '\n';
      }
    }
    delete seg;
    delete G;
  }
}
