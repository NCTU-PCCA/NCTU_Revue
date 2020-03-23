#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
struct SegmentTree {
    struct Node { int L, R; Node *l, *r;
        int v, add;
        Node (int L = 0, int R = 0) : L(L), R(R), v(0), add(0) { l = r = NULL; }
    }*rt, *buf, *ptr;
    SegmentTree (int n) { rt = build(0, n);
        buf = new Node[__lg(n) * 4 + 5];
    }
    Node* build(int L, int R) {
        Node *u = new Node(L, R); int M = (L + R) >> 1;
        if (R - L == 1) return u;
        return u->l = build(L, M), u->r = build(M, R), pull(u);
    }
    Node* pull(Node *u) { return pull(u, u->l, u->r); }
    Node* pull(Node *u, Node *l, Node *r) {
        push(l); push(r); if (!l || !r) return l ? l : r;
        u->v = max(l->v, r->v);
        return u;
    }
    void push(Node *u) {
        if (!u) return ;
        if (u->add) {
            if (u->l) u->l->add += u->add;
            if (u->r) u->r->add += u->add;
            u->v += u->add;
            u->add = 0;
        }
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        push(u); if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, int v, Node *u = NULL) {
        if (!u) u = rt; push(u); if (mR <= u->L || u->R <= mL) return ;
        if (mL <= u->L && u->R <= mR) 
            return u->add += v, void();
        modify(mL, mR, v, u->l); modify(mL, mR, v, u->r);
        return pull(u), void();
    }
    ~SegmentTree() { clear(rt); delete []buf; }
    void clear(Node *u) { if (u) clear(u->l), clear(u->r), delete u; }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int> > data(n);
    vector<int> pool;
    for (auto &p : data) {
        int tmp;
        cin >> tmp >> p.S >> tmp >> p.F;
        p.S++;
        pool.push_back(p.F);
        pool.push_back(p.S);
    }
    sort(pool.begin(), pool.end());
    pool.erase(unique(pool.begin(), pool.end()), pool.end());
    SegmentTree *all = new SegmentTree(pool.size());
    SegmentTree *left = new SegmentTree(pool.size());
    vector<vector<int> > classify(pool.size());
    for (auto &p : data) {
        p.F = lower_bound(pool.begin(), pool.end(), p.F) - pool.begin();
        p.S = lower_bound(pool.begin(), pool.end(), p.S) - pool.begin();
        all->modify(p.F, p.S, 1);
        left->modify(p.F, p.S, 1);
        classify[p.F].push_back(p.S);
    }
    int ans = 0;
    for (int i = 0 ; i < classify.size() ; i++) {
        for (auto &v : classify[i])
            left->modify(i, v, -1);
        ans = max(ans, all->query(i, i + 1)->v + left->query(0, pool.size())->v);
    }
    cout << ans << '\n';
}
