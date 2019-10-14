#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
int ran() {
    static unsigned x = 20190223;
    return x = 0xdefaced * x + 1;
}
struct Treap {
    Treap *l, *r;
    int sz, v, ra, pre, sum;
    Treap (int v) : v(v), l(0), r(0), sz(1), pre(v), sum(v) {
        ra = ran();
    }
};
int size(Treap *u) { return u ? u->sz : 0; }
void pull(Treap *u) {
    if (!u) return ;
    u->sz = 1 + size(u->l) + size(u->r);
    u->sum = u->v;
    if (u->l) u->sum += u->l->sum;
    if (u->r) u->sum += u->r->sum;
    u->pre = (u->l ? u->l->sum : 0) + u->v;
    if (u->l) u->pre = max(u->pre, u->l->pre);
    if (u->r) u->pre = max(u->pre, (u->l ? u->l->sum : 0) + u->v + u->r->pre);
}
Treap* merge(Treap *a, Treap *b) {
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
void split(Treap *o, Treap *&a, Treap *&b, int k) {
    if (!k) a = 0, b = o;
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
void print(Treap *u) {
    if (!u) return ;
    print(u->l);
    cout << u->v << ' ' << u->sz << ' ' << u->pre << '\n';
    print(u->r);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Treap *rt = NULL;
    int pos = 0, cnt = 0;
    int q; cin >> q; while (q--) {
        string op; cin >> op;
        if (op[0] == 'I') {
            int v; cin >> v;
            Treap *u = new Treap(v);
            Treap *a, *b;
            split(rt, a, b, pos);
            rt = merge(merge(a, u), b);
            pos++; cnt++;
        } else if (op[0] == 'Q') {
            int v; cin >> v;
            Treap *a, *b;
            split(rt, a, b, v);
            cout << a->pre << '\n';
            rt = merge(a, b);
        } else if (op[0] == 'L') {
            pos--, pos = max(0, pos);
        } else if (op[0] == 'R') {
            pos++, pos = min(pos, cnt);
        } else if (op[0] == 'D') {
            Treap *ta, *tb, *tc;
            split(rt, ta, tc, pos - 1);
            split(tc, tb, tc, 1);
            delete tb;
            rt = merge(ta, tc);
            pos--, cnt--;
        }
    }
}
