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
#define PTR Sptr<Node>
//=====================
// LatexEnd
/*
// LatexBegin
#define PTR Node*
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
struct SegmentTree {
  struct Node { int L, R, v; PTR l; PTR r;
    Node (int L = 0, int R = 0) : v(0),
      l(NULL), r(NULL), L(L), R(R) {}
  };
//<<<<<<<<<<PRESISTENT
//=====================
// LatexEnd
/*
// LatexBegin
  PTR buf; PTR ptr;
  ~SegmentTree(){ clear(rt.back()); delete []buf; }
  void clear(Node *u){
    if (u) clear(u->l), clear(u->r), delete u;
  }
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  vector<PTR> rt; 
  SegmentTree (int n) {
    rt.resize(rt.size() + 1, NULL);
    rt.back() = build(0, n);
 //<<<<<<<<<<PRESISTENT
//=====================
// LatexEnd
/*
// LatexBegin
    buf = new Node[__lg(n) * 4 + 5];
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
  inline PTR _new(const Node &u) {
//<<<<<<<<<<PERSISTENT
    return PTR(new _ptrCntr <Node>(u));
//===================
// LatexEnd
/*
// LatexBegin
    return new Node(u.L, u.R);
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
  PTR build(int L, int R) {
    PTR u = _new(Node(L, R));
    if (u->R - u->L == 1) return u;
    int M = (R + L) >> 1;
    u->l = build(L, M); u->r = build(M, R);
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
    if (!u) u = rt.back();
//=====================
// LatexEnd
/*
// LatexBegin
    if (!u) u = rt.back(), ptr = buf;
//>>>>>>>>>>ORIGIN
    if (u->R <= qL || qR <= u->L) return NULL;
    if (qL <= u->L && u->R <= qR) return u;
    push(u);
// LatexEnd
*/
// LatexBegin
//<<<<<<<<<<PRESISTENT
    PTR ret = _new(Node(qL, qR));
    return pull(ret, query(qL, qR, u->l), query(qL, qR, u->r));
//=====================
// LatexEnd
/*
// LatexBegin
    return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
  PTR modify(int mL, int mR, int v, PTR u = NULL) {
    if (!u) u = rt.back();
    if (u->R <= mL || mR <= u->L) return u;
//<<<<<<<<<<PRESISTENT
    PTR ret = _new(*u);
    if (mL <= u->L && u->R <= mR) {
      // tag;
// LatexEnd
      ret->v += v;
// LatexBegin
      return ret;
    }
    push(u);
    ret->l = modify(mL, mR, v, u->l);
    ret->r = modify(mL, mR, v, u->r);
    return pull(ret);
//=====================
// LatexEnd
/*
// LatexBegin
    if (mL <= u->L && u->R <= mR) {
      // modify function
// LatexEnd
      u->v += v;
// LatexBegin
      return u;
    }
    push(u);
    modify(mL, mR, v, u->l); modify(mL, mR, v, u->r);
    return pull(u);
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
// LatexEnd
    int solve(Sptr<Node> &l, Sptr<Node> &r, int k){
        if (r->R - r->L == 1) return r->L;
        if (r->l->v - l->l->v < k)
            return solve(l->r, r->r, k - (r->l->v - l->l->v));
        else
            return solve(l->l, r->l, k);
    }
    void setting(int pos){
        rt.resize(rt.size() + 1, rt.back());
        rt.back() = modify(pos, pos + 1, 1, rt.back());
    }
    int solve(int qL, int qR, int k){
        return solve(rt[qL], rt[qR], k);
    }
// LatexBegin
};
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    SegmentTree *sol = new SegmentTree(n);
    vector<int> arr, arrSort;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        arr.push_back(v);
        arrSort.push_back(v);
    }
    sort(arrSort.begin(), arrSort.end());
    vector<int> target;
    target.push_back(arrSort[0]);
    for (int i = 1 ; i < n ; i++)
        if (arrSort[i] != arrSort[i-1])
            target.push_back(arrSort[i]);
    for (int i = 0 ; i < n ; i++)
        sol->setting(lower_bound(target.begin(), target.end(), arr[i]) - target.begin());
    while (q--){
        int a, b, k; cin >> a >> b >> k;
        a--;
        cout << target[sol->solve(a, b, k)] << '\n';
    }
    delete sol;
}
