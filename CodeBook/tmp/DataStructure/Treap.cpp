//<<<<<<<<<<PERSISTENT
#define PTR Sptr<Node>
//====================
#define PTR Node*
//>>>>>>>>>>ORIGIN
#define PNN pair<PTR, PTR>
struct Treap {
  struct Node {
    PTR l; PTR r;
    int sz; char c;
    Node (char c = 0) : c(c), l(NULL), r(NULL) {
      sz = 1;
    }
  };
  vector<PTR> rt;
  Treap() { rt.resize(rt.size() + 1, NULL); }
//<<<<<<<<<<PRESISTENT
//====================
  ~Treap() { clear(rt.back()) }
  void clear(PTR u) { 
    if (u) clear(u->l), clear(u->r), delete u;
  }
//>>>>>>>>>>ORIGIN
  inline PTR _new(const Node &u) {
//<<<<<<<<<<PERSISTENT
    return PTR(new _ptrCntr<Node>(u));
//===================
    return new Node(u.v);
//>>>>>>>>>>ORIGIN
  }
  inline int size(PTR &u) {
    return u ? u->sz : 0;
  }
  inline PTR& pull(PTR &u) {
    u->sz = 1 + size(push(u->l)) + size(push(u->r));
    // pull function
    return u;
  }
  inline PTR& push(PTR &u) {
    if (!u) return u;
    // push function
    return u;
  }
  PNN split(PTR &T, int x) {
    if (!T) return {(PTR)NULL, (PTR)NULL};
//<<<<<<<<<<PRESISTENT
    Sptr<Node> res = _new(*T);
    if (size(T->l) < x){
      PNN tmp = split(T->r, x - 1 - size(T->l));
      res->r = tmp.F;
      return {pull(res), tmp.S};
    } else {
      PNN tmp = split(T->l, x);
      res->l = tmp.S;
      return {tmp.F, pull(res)};
    }
//====================
    if (size(push(T)->l) < x) {
      PNN tmp = split(T->r, x - size(T->l) - 1);
      T->r = tmp.F;
      return {pull(T), tmp.S};
    } else {
      PNN tmp = split(T->l, x);
      T->l = tmp.S;
      return {tmp.F, pull(T)};
    }
//>>>>>>>>>>ORIGIN
  }
  PTR merge(PTR &T1, PTR &T2) {
    if (!T1 || !T2) return T1 ? T1 : T2;
//<<<<<<<<<<PRESISTENT
    Sptr<Node> res;
    if (rand() % (size(T1) + size(T2)) < size(T1)){
      res = _new(*T1);
      res->r = merge(T1->r, T2);
    } else {
      res = _new(*T2);
      res->l = merge(T1, T2->l);
    }
    return pull(res);
//====================
    if (rand() % (size(T1) + size(T2)) < size(T1)) {
      T1->r = merge(push(T1)->r, T2);
      return pull(T1);
    } else {
      T2->l = merge(T1, push(T2)->l);
      return pull(T2);
    }
//>>>>>>>>>>ORIGIN
  }
};
