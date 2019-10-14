#include <bits/stdc++.h>
#define PTR Node*
using namespace std;
typedef long long LL;
struct SegmentTree {
    struct Node {
        int L, R;
        // data
        LL minV, maxV;
        // tag
        LL add;
        PTR l; PTR r;
        Node (int L = 0, int R = 0) : minV(0), maxV(0), l(NULL), r(NULL),
            add(0), L(L), R(R) {}
    };
    PTR buf; PTR ptr;
    ~SegmentTree() { clear(rt.back()); delete []buf; }
    void clear(PTR u) {
        if (u) clear(u->l), clear(u->r), delete u;
    }
    vector<PTR> rt;
    SegmentTree(int n) {
        rt.resize(rt.size() + 1, NULL);
        rt.back() = build(0, n);
        buf = new Node[__lg(n) * 4 + 5];
    }
    inline PTR _new(const Node &u) {
        return new Node(u.L, u.R);
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
        u->minV = min(l->minV, r->minV);
        u->maxV = max(l->maxV, r->maxV);
        return u;
    }
    PTR pull(PTR u) { return pull(u, u->l, u->r); }
    void push(PTR u) {
        if (!u) return ;
        if (u->add) {
            if (u->l) {
                u->l->add += u->add;
                u->l->minV += u->add;
                u->l->maxV += u->add;
            }
            if (u->r) {
                u->r->add += u->add;
                u->r->minV += u->add;
                u->r->maxV += u->add;
            }
            u->add = 0;
        }
        if (u->l) {
            u->l->minV = max(u->l->minV, u->minV);
            u->l->minV = min(u->l->minV, u->maxV);
            u->l->maxV = max(u->l->maxV, u->minV);
            u->l->maxV = min(u->l->maxV, u->maxV);
        }
        if (u->r) {
            u->r->minV = max(u->r->minV, u->minV);
            u->r->minV = min(u->r->minV, u->maxV);
            u->r->maxV = max(u->r->maxV, u->minV);
            u->r->maxV = min(u->r->maxV, u->maxV);
        }
    }
    PTR query(int qL, int qR, PTR u = NULL) {
        if (!u) u = rt.back(), ptr = buf;
        if (u->R <= qL || qR <= u->L) return NULL;
        push(u);
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    PTR modify(int mL, int mR, int op, LL v, PTR u = NULL) {
        if (!u) u = rt.back();
        if (u->R <= mL || mR <= u->L) return u;
        if (mL <= u->L && u->R <= mR) {
            if (op == 1) {
                u->add += v;
                u->minV += v;
                u->maxV += v;
            } else if (op == 2) {
                u->maxV = min(u->maxV, v);
                u->minV = min(u->minV, v);
            } else if (op == 3) {
                u->maxV = max(u->maxV, v);
                u->minV = max(u->minV, v);
            }
            return u;
        }
        push(u);
        modify(mL, mR, op, v, u->l);
        modify(mL, mR, op, v, u->r);
        return pull(u);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    SegmentTree *sol = new SegmentTree(n);
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        sol->modify(i, i + 1, 1, v);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 4) {
            int l, r; cin >> l >> r; l--;
            auto ret = sol->query(l, r);
            cout << ret->minV << ' ' << ret->maxV << '\n';
        } else {
            int l, r; LL v; cin >> l >> r >> v; l--;
            sol->modify(l, r, op, v);
        }
    }
    delete sol;
}
