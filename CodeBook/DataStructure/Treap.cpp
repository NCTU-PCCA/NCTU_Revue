#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
// LatexBegin
struct Treap {
  struct Node { Node *l, *r; int sz; char v; bool rev;
    Node (char v = 0) : v(v), sz(1), l(NULL),
      r(NULL), rev(false) {}
  } mem[MAXN * 80], *r, *ptr;
  void init(string s) { r = NULL; ptr = mem;
    for (auto &c : s) r = merge(r,new (ptr++) Node(c));
  }
  int size(Node *u) { return u ? u->sz : 0; }
  Node* merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b; Node *t;
    if (rand() % (size(a) + size(b)) < size(a))
      // t = push(a),
      t = new (ptr++) Node(*push(a)),
      t->r = merge(a->r, b);
    else
      // t = push(b),
      t = new (ptr++) Node(*push(b)),
      t->l = merge(a, b->l);
    return pull(t);
  }
  void split(Node *t, int k, Node *&a, Node *&b) {
    if (!t) a = b = NULL;
    else if (size(push(t)->l) < k)
      // a = t,
      a = new (ptr++) Node(*t),
      split(t->r, k - size(t->l) - 1, a->r, b),pull(a);
    else
      // b = t,
      b = new (ptr++) Node(*t),
      split(t->l, k, a, b->l), pull(b);
  }
  Node* push(Node *&u) { if (!u) return u;
    if (u->rev) { swap(u->l, u->r); u->rev = false;
      if (u->l)
        (u->l = new (ptr++) Node(*(u->l)))->rev ^= 1;
      if (u->r)
        (u->r = new (ptr++) Node(*(u->r)))->rev ^= 1;
    }
    return u;
  }
  Node* pull(Node *&u) { if (!u) return u;
    u->sz = 1 + size(push(u->l)) + size(push(u->r));
    return u;
  }
  void print(Node *u) { if (!push(u)) return ;
    print(u->l); cout << u->v; print(u->r);
  }
  void print(int L, int R) { Node *a, *b, *c;
    split(r, R, a, c); split(a, L, a, b);
    print(b); cout << '\n'; r = merge(merge(a, b), c);
  }
  void copy(int L, int R) { Node *a, *b, *c;
    split(r, R, a, c); split(a, L, a, b);
    r = merge(merge(a, b), merge(b, c));
  }
  void reverse(int L, int R) { Node *a, *b, *c;
    split(r, R, a, c); split(a, L, a, b);
    b->rev ^= 1; r = merge(merge(a, b), c);
  }
} sol;
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    sol.init(s);
    while (q--) {
      int op, l, r; cin >> op >> l >> r; l--;
      if (op == 1)
        sol.print(l, r);
      else if (op == 2)
        sol.copy(l, r);
      else 
        sol.reverse(l, r);
    }
  }
}
