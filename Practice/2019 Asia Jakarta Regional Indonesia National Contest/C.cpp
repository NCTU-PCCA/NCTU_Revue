#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
typedef long long LL;
int ran() {
    static unsigned x = 20190223;
    return x = 0xdefaced * x + 1;
}
struct Node {
    Node *l, *r;
    int sz, L, R, ra; LL sum;
    Node (int L = -1, int R = -1) : L(L), R(R){
        sz = 1; ra = ran(); sum = 1LL * (R - L) * (R - L);
    }
};
int size(Node *u) {
    return u ? u->sz : 0;
}
void pull(Node *u) {
    if (!u) return ;
    u->sz = 1 + size(u->l) + size(u->r);
    u->sum = 1LL * (u->R - u->L) * (u->R - u->L);
    if (u->l) u->sum += u->l->sum;
    if (u->r) u->sum += u->r->sum;
}
Node* merge(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    if (a->ra > b->ra) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
void split(Node *o, Node *&a, Node *&b, int k) {
    if (!o) a = NULL, b = NULL;
    else if (!k) a = 0, b = o;
    else if (size(o) == k) a = o, b = 0;
    else {
        if (k <= size(o->l)) {
            b = o;
            split(o->l, a, b->l, k);
            pull(b);
        } else {
            a = o;
            split(o->r, a->r, b, k - size(o->l) - 1);
            pull(a);
        }
    }
}
int rk(Node *u, int v) {
    if (!u) return 0;
    if (u->L <= v && v < u->R)
        return 1;
    else if (v < u->L) {
        return rk(u->l, v);
    } else 
        return rk(u->r, v) + 1 + size(u->l);
}
void clear(Node *u) {
    if (!u) return ;
    clear(u->l);
    clear(u->r);
    delete u;
}
void remove(Node *u, int v) {
    int k = rk(u, v);
    Node *ta, *tb, *tc;
    split(u, ta, tc, k + 1);
    split(ta, ta, tb, k);
    Node *x = NULL, *y = NULL;
    x = new Node(tb->L, v);
    if (x->L == x->R)
        clear(x);
    y = new Node(v + 1, tb->R);
    if (y->L == y->R)
        clear(y);
    clear(tb);
    u = merge(merge(ta, x), merge(y, tc));
}
void print(Node *u) {
    if (!u) return ;
    print(u->l);
    cout << u->sz << ' ' << u->L << ' ' << u->R << ' ' << u->sum << '\n';
    print(u->r);
}
void insert(Node *&rt, int v) {
    if (size(rt) == 0) {
        rt = new Node(v, v + 1);
    } else {
        Node *ta = NULL, *tb = NULL, *tc = NULL, *td = NULL;
        int k = rk(rt, v);
        split(rt, ta, td, k);
        if (ta)
            split(ta, ta, tb, k - 1);
        if (td)
            split(td, tc, td, 1);
        Node *added = NULL;
        if (tb && tc && tb->R == v && tc->L == v + 1) {
            added = new Node(tb->L, tc->R);
            clear(tb); tb = NULL;
            clear(tc); tc = NULL;
        } else if (tb && tb->R == v) {
            added = new Node(tb->L, tb->R + 1);
            clear(tb); tb = NULL;
        } else if (tc && tc->L == v + 1) {
            added = new Node(tc->L - 1, tc->R);
            clear(tc); tc = NULL;
        } else
            added = new Node(v, v + 1);
        rt = merge(merge(ta, tb), merge(added, merge(tc, td)));
    }
}
LL query(Node *u, int l, int r) {
    cout << "l: " << l << '\n';
    cout << rk(u, l) << '\n';
    cout << "r: " << r << '\n';
    cout << rk(u, r) << '\n';
    return 0;
}
int main() {
    int m, n, q; cin >> m >> n >> q;
    Node *rt = NULL;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        insert(rt, v);
    }
    while (q--) {
        print(rt); cout << '\n';
        string op; cin >> op;
        cout << op << '\n';
        if (op[0] == 'g') {
            int l, r; cin >> l >> r;
            cout << query(rt, l, r + 1) << '\n';
        } else if (op[0] == 'r') {
            int v; cin >> v;
            insert(rt, v);
        } else if (op[0] == 'a') {
            int v; cin >> v;
            remove(rt, v);
        }
    }
}
