//<<<<<<<<<<PRESISTENT
#define PTR Sptr<Node>
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
    return PTR(new _ptrCntr <Node>(u));
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
    if (!u) u = rt.back(), ptr = buf;
//>>>>>>>>>>ORIGIN
    if (u->R <= qL || qR <= u->L) return NULL;
    if (qL <= u->L && u->R <= qR) return u;
    push(u);
//<<<<<<<<<<PRESISTENT
    PTR ret = _new(Node(qL, qR));
    return pull(ret, query(qL, qR, u->l), query(qL, qR, u->r));
//=====================
    return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
//>>>>>>>>>>ORIGIN
  }
  PTR modify(int mL, int mR, int v, PTR u = NULL) {
    if (!u) u = rt.back();
    if (u->R <= mL || mR <= u->L) return u;
//<<<<<<<<<<PRESISTENT
    PTR ret = _new(*u);
    if (mL <= u->L && u->R <= mR) {
      // tag;
      return ret;
    }
    push(u);
    ret->l = modify(mL, mR, v, u->l);
    ret->r = modify(mL, mR, v, u->r);
    return pull(ret);
//=====================
    if (mL <= u->L && u->R <= mR) {
      // modify function
      return u;
    }
    push(u);
    modify(mL, mR, v, u->l);
    modify(mL, mR, v, u->r);
    return pull(u);
//>>>>>>>>>>ORIGIN
  }
};
