#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
#define PNN pair<Node*, Node*>
#define PTR Node*
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Treap {
    int ran() {
        static unsigned x = 20190223;
        return x = 0xdefaced * x + 1;
    }
    struct Node {
        PTR l; PTR r; int sz; LL v, pre, sum;
        Node (LL v) : v(v), pre(v), sum(v), l(NULL), r(NULL), sz(1) {}
    };
    vector<PTR> rt;
    Treap() { rt.resize(rt.size() + 1, NULL); }
    ~Treap() { clear(rt.back()); }
    void clear(PTR u) {
        if (u) clear(u->l), clear(u->r), delete u;
    }
    inline PTR _new(const Node &u) {
        return new Node(u.v);
    }
    inline int size(PTR &u) { return u ? u->sz : 0; }
    inline PTR& pull(PTR &u) {
        u->sz = 1 + size(push(u->l)) + size(push(u->r));
        u->sum = u->v;
        if (u->l) u->sum += u->l->sum;
        if (u->r) u->sum += u->r->sum;

        u->pre = (u->l ? u->l->sum : 0) + u->v;
        if (u->l) u->pre = max(u->pre, u->l->pre);
        if (u->r) u->pre = max(u->pre, (u->l ? u->l->sum : 0) + u->v + u->r->pre);

        return u;
    }
    inline PTR& push(PTR &u) {
        if (!u) return u;
        return u;
    }
    void split(PTR T, PTR &a, PTR &b, int x) {
        if (!x) a = 0, b = T;
        else if (size(T) == x)
            a = T, b = 0;
        else if (x <= size(push(T)->l)) {
            b = T;
            split(T->l, a, b->l, x);
            pull(b);
        } else {
            a = T;
            split(T->r, a->r, b, x - size(T->l) - 1);
            pull(a);
        }
    }
    PTR merge(PTR T1, PTR T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (ran() % (size(T1) + size(T2)) < size(T1))
            return T1->r = merge(push(T1)->r, T2), pull(T1);
        else
            return T2->l = merge(T1, push(T2)->l), pull(T2);
    }
    void insert(int x, LL v) {
        PTR ta; PTR tb;
        split(rt.back(), ta, tb, x);
        rt.back() = merge(merge(ta, new Node(v)), tb);
    }
    void erase(int x) {
        PTR ta; PTR tb; PTR tc;
        split(rt.back(), ta, tc, x + 1);
        split(ta, ta, tb, x);
        delete tb;
        rt.back() = merge(ta, tc);
    }
    LL query(int L, int R) {
        PTR ta; PTR tb; PTR tc;
        split(rt.back(), ta, tc, R);
        split(ta, ta, tb, L);
        LL ret = tb->pre;
        rt.back() = merge(merge(ta, tb), tc);
        return ret;
    }
    void print() {
        cout << '\n';
        print(rt.back());
        cout << '\n';
    }
    void print(Node *u) {
        if (!u) return ;
        print(u->l);
        cout << u->v << ' ';
        print(u->r);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Treap *sol = new Treap();
    int pos = 0;
    int q; cin >> q; while (q--) {
        string op; cin >> op;
        if (op[0] == 'I') {
            LL v; cin >> v;
            sol->insert(pos, v);
            pos++;
        } else if (op[0] == 'Q') {
            int k; cin >> k;
            cout << sol->query(0, k) << '\n';
        } else if (op[0] == 'D') {
            sol->erase(pos - 1);
            pos--; pos = max(0, pos);
        } else if (op[0] == 'L') {
            pos--; pos = max(0, pos);
        } else if (op[0] == 'R') {
            pos++; pos = min(pos, sol->size(sol->rt.back()));
        }
    }
}
