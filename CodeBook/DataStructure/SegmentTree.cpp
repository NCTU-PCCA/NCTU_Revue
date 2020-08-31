#include <bits/stdc++.h>
using namespace std; 
using LL = long long;
// LatexBegin
template <bool P = 0> struct SegmentTree {
  #define lson L, R, N[u].l
  #define rson L, R, N[u].r
  #define OUT R <= N[u].L || N[u].R <= L
  #define IN  L <= N[u].L && N[u].R <= R
// LatexEnd
  struct Node { int L, R, l, r; LL sum, chg; };
/*
// LatexBegin
  struct Node { int L, R, l, r; };
// LatexEnd
*/
// LatexBegin
  vector<Node> N; int p, n; vector<int> rt;
  inline void init(int _n) { N.resize(_n * (P ? 40:8));
    n = _n; p = 1; rt.assign(1, build(0, n));
  }
  inline int copy(Node u) { return N[p] = u, p++; }
  int build(int L, int R) {
    int u = copy({L, R}), M = (L + R) >> 1;;
    if (R - L == 1) return u;
    return pull(u, build(L, M), build(M, R));
  }
  inline int push(int u) {
// LatexEnd
    if (N[u].chg) {
      N[u].sum = (N[u].R - N[u].L) * N[u].chg;
      N[N[u].l].chg = N[u].chg;
      N[N[u].r].chg = N[u].chg;
      N[u].chg = 0;
    } return u;
/*
// LatexBegin
    <push function>
    return u;
// LatexEnd
*/
// LatexBegin
  }
  inline int pull(int u, int l, int r) {
    if (!l || !r) return l ? l : r;
    push(N[u].l = l); push(N[u].r = r);
// LatexEnd
    N[u].sum = N[l].sum + N[r].sum;
/*
// LatexBegin
    <pull function>
// LatexEnd
*/
// LatexBegin
    return u;
  }
  int m(int L, int R, int u, LL v) {
    if (!u || OUT) return u; push(u);
    if (P) u = copy(N[u]);
// LatexEnd
    if (IN) return N[u].chg = v, u;
/*
// LatexBegin
    if (IN) return <modify function>, u;
// LatexEnd
*/
// LatexBegin
    return pull(u, m(lson, v), m(rson, v));
  }
  int q(int L, int R, int u) {
    if (!u || OUT) return 0; push(u); if (IN) return u;
    return pull(copy(N[u]), q(lson), q(rson));
  }
  inline void modify(int L, int R, int ver, LL v) {
    rt[ver] = m(L, R, rt[ver], v);
  }
  inline Node& query(int L, int R, int ver) {
    if (!P) p = 4 * n; return N[q(L, R, rt[ver])];
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  SegmentTree<1> solver; solver.init(n);
  for (int i = 0 ; i < n ; i++) {
    int v; cin >> v;
    solver.modify(i, i + 1, 0, v);
  }
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int k, x; LL v; cin >> k >> x >> v; k--, x--;
      solver.modify(x, x + 1, k, v);
    } else if (op == 2) {
      int k, l, r; cin >> k >> l >> r; k--, l--;
      cout << solver.query(l, r, k).sum << '\n';
    } else if (op == 3) {
      int k; cin >> k; k--;
      solver.rt.push_back(solver.rt[k]);
    }
  }
}
/*
template <bool P = 0> struct SegmentTree {
  #define lson L, R, N[u].l
  #define rson L, R, N[u].r
  #define OUT R <= N[u].L || N[u].R <= L
  #define IN  L <= N[u].L && N[u].R <= R
  struct Node { int L, R, l, r; };
  vector<Node> N; int p, n; vector<int> rt;
  inline void init(int _n) { N.resize(_n * (P ? 40:8));
    n = _n; p = 1; rt.assign(1, build(0, n));
  }
  inline int copy(Node u) { return N[p] = u, p++; }
  int build(int L, int R) {
    int u = copy({L, R}), M = (L + R) >> 1;;
    if (R - L == 1) return u;
    return pull(u, build(L, M), build(M, R));
  }
  inline int push(int u) {
    <push function>
    return u;
  }
  inline int pull(int u, int l, int r) {
    if (!l || !r) return l ? l : r;
    push(N[u].l = l); push(N[u].r = r);
    <pull function>
    return u;
  }
  int m(int L, int R, int u, LL v) {
    if (!u || OUT) return u; push(u);
    if (P) u = copy(N[u]);
    if (IN) return <modify function>, u;
    return pull(u, m(lson, v), m(rson, v));
  }
  int q(int L, int R, int u) {
    if (!u || OUT) return 0; push(u); if (IN) return u;
    return pull(copy(N[u]), q(lson), q(rson));
  }
  inline void modify(int L, int R, int ver, LL v) {
    rt[ver] = m(L, R, rt[ver], v);
  }
  inline Node& query(int L, int R, int ver) {
    if (!P) p = 4 * n; return N[q(L, R, rt[ver])];
  }
};
*/
