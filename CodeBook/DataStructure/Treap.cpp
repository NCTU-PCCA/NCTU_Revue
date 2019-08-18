#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F first
#define S second
const int MAXN = 2e5 + 5;
const int MAXVER = MAXN;
template <typename T> struct _ptrCntr{
    T v; int c;
    _ptrCntr(const T& _v):v(_v){ c = 0;}
};
template <typename T>
struct Sptr{
    _ptrCntr<T> *p;
    T* operator->(){ return &p->v; }
    T& operator* (){ return  p->v; }
    operator _ptrCntr<T>*(){ return p; }
    Sptr& operator = (const Sptr<T>& t){
        if (p && !--p->c) delete p;
        (p = t.p) && ++p->c;
        return *this;
    }
    Sptr(_ptrCntr<T> *t = 0) : p(t){ p && ++p->c; }
    Sptr(const Sptr& t) : p(t.p){ p  && ++p->c; }
    ~Sptr(){ if (p && !--p->c) delete p;}
};

// LatexBegin
//<<<<<<<<<<PERSISTENT
#define PTR Sptr<Node>
//====================
// LatexEnd
int d;
/*
// LatexBegin
#define PTR Node*
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
#define PNN pair<PTR, PTR>
struct Treap {
  struct Node { PTR l; PTR r; int sz; char c;
    Node (char c = 0) : c(c), l(NULL), r(NULL) {
      sz = 1;
    }
  };
  vector<PTR> rt;
  Treap() { rt.resize(rt.size() + 1, NULL); }
//<<<<<<<<<<PRESISTENT
//====================
// LatexEnd
/*
// LatexBegin
  ~Treap() { clear(rt.back()) }
  void clear(PTR u) { 
    if (u) clear(u->l), clear(u->r), delete u;
  }
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  inline PTR _new(const Node &u) {
//<<<<<<<<<<PERSISTENT
    return PTR(new _ptrCntr<Node>(u));
//===================
// LatexEnd
/*
// LatexBegin
    return new Node(u.v);
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
  inline int size(PTR &u) { return u ? u->sz : 0; }
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
      res->r = tmp.F; return {pull(res), tmp.S};
    } else {
      PNN tmp = split(T->l, x);
      res->l = tmp.S; return {tmp.F, pull(res)};
    }
//====================
// LatexEnd
/*
// LatexBegin
    if (size(push(T)->l) < x) {
      PNN tmp = split(T->r, x - size(T->l) - 1);
      T->r = tmp.F; return {pull(T), tmp.S};
    } else {
      PNN tmp = split(T->l, x);
      T->l = tmp.S; return {tmp.F, pull(T)};
    }
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
  PTR merge(PTR &T1, PTR &T2) {
    if (!T1 || !T2) return T1 ? T1 : T2;
//<<<<<<<<<<PRESISTENT
    Sptr<Node> res;
    if (rand() % (size(T1) + size(T2)) < size(T1))
      res = _new(*T1), res->r = merge(T1->r, T2);
    else
      res = _new(*T2), res->l = merge(T1, T2->l);
    return pull(res);
//====================
// LatexEnd
/*
// LatexBegin
    if (rand() % (size(T1) + size(T2)) < size(T1))
      return T1->r = merge(push(T1)->r, T2), pull(T1);
    else
      return T2->l = merge(T1, push(T2)->l), pull(T2);
// LatexEnd
*/
// LatexBegin
//>>>>>>>>>>ORIGIN
  }
// LatexEnd
    void insert(char *s, int p){
        rt.resize(rt.size() + 1, rt.back());
        PNN tmp = split(rt.back(), p);
        for (int i = 0 ; s[i] ; i++){
            Sptr<Node> target = _new(Node(s[i]));
            tmp.F = merge(tmp.F, target);
        }
        rt.back() = merge(tmp.F, tmp.S);
    }
    void remove(int p, int c){
        rt.resize(rt.size() + 1, rt.back());
        PNN tmp_1 = split(rt.back(), p-1);
        PNN tmp_2 = split(tmp_1.S, c);
        rt.back() = merge(tmp_1.F, tmp_2.S);
    }
    void query(int v, int p, int c){
        PNN tmp_1 = split(rt[v], p-1);
        PNN tmp_2 = split(tmp_1.S, c);
        Print(tmp_2.F); cout << '\n';
    }
    void Print(PTR &u){
        if (!u) return ;
        Print(u->l);
        cout << u->c;
        if (u->c == 'c') d++;
        Print(u->r);
    }
// LatexBegin
};
// LatexEnd
const int MAXLEN = 1e6 + 5;
int main(){
    srand(time(NULL));
    d = 0;
    Treap *sol = new Treap();
    int n; cin >> n; while (n--){
        int op; cin >> op;
        char input[MAXLEN];
        int v, p, c;
        switch (op){
            case 1:
                cin >> p >> input; p -= d;
                sol->insert(input, p);
                break;
            case 2:
                cin >> p >> c; p -= d, c -= d;
                sol->remove(p, c);
                break;
            case 3:
                cin >> v >> p >> c;
                v -= d, p -= d, c -= d;
                sol->query(v, p, c);
                break;
        }
    }
    delete sol;
}
