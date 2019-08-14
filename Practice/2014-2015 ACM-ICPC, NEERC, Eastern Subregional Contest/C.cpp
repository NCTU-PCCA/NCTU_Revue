#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
struct SegmentTree {
    struct Node { int L, R; Node *l, *r;
        LL v, minV, add;
        Node (int L = 0, int R = 0) : L(L), R(R) {
            l = r = NULL;
            add = 0;
        }
    }*rt, *buf, *ptr;
    SegmentTree (int n) {
        rt = build(0, n);
        buf = new Node[__lg(n) * 4 + 5];
    }
    Node* build(int L, int R) {
        Node *u = new Node(L, R); int M = (L + R) >> 1;
        if (R - L == 1) return u->v = u->minV = 0, u;
        return u->l = build(L, M), u->r = build(M, R), pull(u);
    }
    Node* pull(Node *u) { return pull(u, u->l, u->r); }
    Node* pull(Node *u, Node *l, Node *r) {
        push(l); push(r);
        if (!l || !r) return l ? l : r;
        u->minV = min(l->minV, r->minV);
        return u;
    }
    void push(Node *u) {
        if (!u) return ;
        if (u->add) {
            u->minV += u->add;
            if (u->l)
                u->l->add += u->add;
            if (u->r)
                u->r->add += u->add;
            u->add = 0;
        }
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        push(u);
        if (qR <= u->L || u->R <= qL) 
            return (Node*)NULL;
        if (qL <= u->L && u->R <= qR)
            return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, LL v, Node *u = NULL) {
        if (!u) u = rt; push(u);
        if (mR <= u->L || u->R <= mL)
            return ;
        if (mL <= u->L && u->R <= mR)
            return u->add += v, void();
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        return pull(u), void();
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; 
    SegmentTree *sol = new SegmentTree(n);
    vector<pii> Q; vector<int> pos;
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        char tmp;
        LL d, mo, h, mi;
        cin >> d >> tmp >> mo >> h >> tmp >> mi;
        LL timing = 0;
        timing += mo; timing *= 35;
        timing += d ; timing *= 24;
        timing += h ; timing *= 60;
        timing += mi;
        Q.push_back({v, timing});
        pos.push_back(timing);
    }
    sort(pos.begin(), pos.end());
    for (auto &p : Q)
        p.second = lower_bound(pos.begin(), pos.end(), p.second) - pos.begin();
    for (auto &p : Q) {
        sol->modify(p.second, n, p.first);
        cout << min(0LL, sol->query(0, n)->minV) << '\n';
    }
    delete sol;
}
