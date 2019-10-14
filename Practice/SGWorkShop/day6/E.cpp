#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef int LL;
#define PNN pair<Node*, Node*>
#define PTR Node*
const int MAXN = 1e6 + 5;
struct Treap {
    struct Node {
        PTR l; PTR r; int sz; LL v, pre, sum;
        Node (LL v = 0) : v(v), pre(v), sum(v), l(NULL), r(NULL), sz(1) {}
    }pool[MAXN], *ptr, *rt;
    Treap() { ptr = pool; }
    inline PTR _new(const Node &u) { return new (ptr++) Node(u.v); }
    inline int size(PTR &u) { return u ? u->sz : 0; }
    inline PTR& pull(PTR &u) {
        u->sz = 1 + size(u->l) + size(u->r);
        u->sum = u->v;
        if (u->l) u->sum += u->l->sum;
        if (u->r) u->sum += u->r->sum;
        u->pre = (u->l ? u->l->sum : 0) + u->v;
        if (u->l) u->pre = max(u->pre, u->l->pre);
        if (u->r) u->pre = max(u->pre, (u->l ? u->l->sum : 0) + u->v + u->r->pre);
        return u;
    }
    PNN split(PTR &T, int x) {
        if (!T) return {(PTR)NULL, (PTR)NULL};
        if (size(T->l) < x) {
            PNN tmp = split(T->r, x - size(T->l) - 1);
            T->r = tmp.F; return {pull(T), tmp.S};
        } else {
            PNN tmp = split(T->l, x);
            T->l = tmp.S; return {tmp.F, pull(T)};
        }
    }
    PTR merge(PTR T1, PTR T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (rand() % (size(T1) + size(T2)) < size(T1))
            return T1->r = merge(T1->r, T2), pull(T1);
        else
            return T2->l = merge(T1, T2->l), pull(T2);
    }
    void insert(int x, LL v) {
        PNN tmp = split(rt, x);
        rt = merge(merge(tmp.F, new (ptr++) Node(v)), tmp.S);
    }
    void erase(int x) {
        PNN tmp_1 = split(rt, x + 1);
        PNN tmp_2 = split(tmp_1.F, x);
        rt = merge(tmp_2.F, tmp_1.S);
    }
    LL query(int L, int R) {
        PNN tmp_1 = split(rt, R);
        PNN tmp_2 = split(tmp_1.F, L);
        LL ret = tmp_2.S->pre;
        rt = merge(merge(tmp_2.F, tmp_2.S), tmp_1.S);
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    int pos = 0, cnt = 0; Treap *sol = new Treap();
    int q; cin >> q; while (q--) {
        string op; cin >> op;
        if (op[0] == 'I') {
            int v; cin >> v;
            sol->insert(pos, v);
            pos++; cnt++;
        } else if (op[0] == 'Q') {
            int k; cin >> k;
            cout << sol->query(0, k) << '\n';
        } else if (op[0] == 'D') {
            sol->erase(pos - 1);
            pos--; pos = max(0, pos); cnt--;
        } else if (op[0] == 'L') {
            pos--; pos = max(0, pos);
        } else if (op[0] == 'R') {
            pos++; pos = min(pos, cnt);
        }
    }
    delete sol;
}
