#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct _ptrCntr{
  T v; int cnt;
  _ptrCntr(const T& _v) : v(_v), cnt(0){}
};
template <typename T>
struct Sptr{
  _ptrCntr<T> *p;
  T* operator->(){ return &p->v; }
  T& operator* (){ return p->v; }
  operator _ptrCntr<T>*(){ return p;}
  Sptr& operator = (const Sptr& t){
    if (p && !--p->cnt) delete p;
    (p = t.p) && ++p->cnt;
    return *this;
  }
  Sptr(_ptrCntr<T> *t = NULL) : p(t) {
    p && ++p->cnt;
  }
  Sptr(const Sptr& t) : p(t.p) {p && ++p->cnt; }
  ~Sptr() {
    if (p && !--p->cnt)
      delete p;
  }
};
// LatexBegin
//<<<<<<<<<<PRESISTENT
// LatexEnd
/*
// LatexBegin
#define PTR Sptr<Node>
// LatexEnd
*/
// LatexBegin
//=====================
#define PTR Node*
//>>>>>>>>>>ORIGIN
struct SegmentTree {
  struct Node {
    int L, R, v; PTR l; PTR r;
    Node (int L = 0, int R = 0) : v(0),
      l(NULL), r(NULL), L(L), R(R) {}
  };
//<<<<<<<<<<PRESISTENT
//=====================
  PTR buf; PTR ptr;
  ~SegmentTree(){ clear(rt.back()); delete []buf; }
  void clear(Node *u){
    if (u) clear(u->l), clear(u->r), delete u;
  }
//>>>>>>>>>>ORIGIN
  vector<PTR> rt; 
  SegmentTree (int n) {
    rt.resize(rt.size() + 1, NULL);
    rt.back() = build(0, n);
 //<<<<<<<<<<PRESISTENT
//=====================
    buf = new Node[__lg(n) * 4 + 5];
//>>>>>>>>>>ORIGIN
  }
  inline PTR _new(const Node &u) {
//<<<<<<<<<<PERSISTENT
// LatexEnd
/*
// LatexBegin
    return PTR(new _ptrCntr <Node>(u));
// LatexEnd
*/
// LatexBegin
//===================
    return new Node(u.L, u.R);
//>>>>>>>>>>ORIGIN
  }
  PTR build(int L, int R) {
    PTR u = _new(Node(L, R));
    if (u->R - u->L == 1)
      return u;
    int M = (R + L) >> 1;
    u->l = build(L, M);
    u->r = build(M, R);
    return pull(u);
  }
  PTR pull(PTR u, PTR l, PTR r) {
    if (!l || !r) return l ? l : r;
    push(l); push(r);
    // pull function
// LatexEnd
    u->v = l->v + r->v;
// LatexBegin
    return u;
  }
  PTR pull(PTR u) { return pull(u, u->l, u->r); }
  void push(PTR u) {
    if (!u) return ;
    // push function
  }
  PTR query(int qL, int qR, PTR u = NULL) {
//<<<<<<<<<<PRESISTENT
// LatexEnd
/*
// LatexBegin
    if (!u) u = rt.back();
// LatexEnd
*/
// LatexBegin
//=====================
    if (!u) u = rt.back(), ptr = buf;
//>>>>>>>>>>ORIGIN
    if (u->R <= qL || qR <= u->L) return NULL;
    if (qL <= u->L && u->R <= qR) return u;
    push(u);
//<<<<<<<<<<PRESISTENT
// LatexEnd
/*
// LatexBegin
    PTR ret = _new(Node(qL, qR));
    return pull(ret, query(qL, qR, u->l), query(qL, qR, u->r));
// LatexEnd
*/
// LatexBegin
//=====================
    return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
//>>>>>>>>>>ORIGIN
  }
  PTR modify(int mL, int mR, int v, PTR u = NULL) {
    if (!u) u = rt.back();
    if (u->R <= mL || mR <= u->L) return u;
//<<<<<<<<<<PRESISTENT
// LatexEnd
/*
// LatexBegin
    PTR ret = _new(*u);
    if (mL <= u->L && u->R <= mR) {
      // tag;
      return ret;
    }
    push(u);
    _u->l = modify(mL, mR, v, u->l);
    _u->r = modify(mL, mR, v, u->r);
    return pull(_u);
// LatexEnd
*/
// LatexBegin
//=====================
    if (mL <= u->L && u->R <= mR) {
      // modify function
// LatexEnd
      u->v += v;
// LatexBegin
      return u;
    }
    push(u);
    modify(mL, mR, v, u->l);
    modify(mL, mR, v, u->r);
    return pull(u);
//>>>>>>>>>>ORIGIN
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t, kase = 0; cin >> t; while (t--){
    cout << "Case " << ++kase << ":\n";
    int n; cin >> n;
    SegmentTree *sol = new SegmentTree(n);
    for (int i = 0 ; i < n ; i++) {
      int v; cin >> v;
      sol->modify(i, i + 1, v);
    }
    char op[8];
    while (cin >> op){
      if (op[0] == 'E') break;
      int a, b, v;
      if (op[0] == 'A'){
        cin >> a >> v;
        sol->modify(a-1, a, v);
      }
      if (op[0] == 'S'){
        cin >> a >> v;
        sol->modify(a-1, a, -v);
      }
      if (op[0] == 'Q'){
        cin >> a >> b;
        cout << sol->query(a-1, b)->v << '\n';
      }
    }
    delete sol;
  }
}
