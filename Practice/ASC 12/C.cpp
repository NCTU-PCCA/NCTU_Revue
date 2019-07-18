#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct SegmentTree {
    struct Node {
        int L, R;
        LL sum;
        Node *l, *r;
        bool isChg;
        LL chg;
        Node (int L = 0, int R = 0) : L(L), R(R) {
            l = r = NULL;
            isChg = false;
            chg = 0;
        }
    }*rt, *buf, *ptr;
    SegmentTree (vector<LL> &arr) {
        rt = build(0, arr.size(), arr);
        buf = new Node[__lg(arr.size()) * 4 + 5];
    }
    Node* build(int L, int R, vector<LL> &arr) {
        Node *u = new Node(L, R);
        int M = (L + R) >> 1;
        if (R - L == 1)
            return u->sum = arr[L], u;
        return u->l = build(L, M, arr), u->r = build(M, R, arr), pull(u);
    }
    Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    Node* pull(Node *u, Node *l, Node *r) {
        push(l); push(r);
        if (!l || !r) return l ? l : r;
        u->sum = l->sum + r->sum;
        return u;
    }
    void push(Node *u) {
        if (!u) return ;
        if (u->isChg) {
            u->isChg = false;
            u->sum = u->chg * (u->R - u->L);
            if (u->l)
                u->l->isChg = true, u->l->chg = u->chg;
            if (u->r)
                u->r->isChg = true, u->r->chg = u->chg;
            u->chg = 0;
        }
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        push(u);
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, LL v, Node *u = NULL) {
        if (!u) u = rt;
        push(u);
        if (mR <= u->L || u->R <= mL) return ;
        if (mL <= u->L && u->R <= mR) 
            return u->isChg = true, u->chg = v, void();
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        return pull(u), void();
    }
    ~SegmentTree() {
        clear(rt);
        delete []buf;
    }
    void clear(Node *u) {
        if (u) clear(u->l), clear(u->r), delete u; 
    }
    
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("death.in");
    ofstream out("death.out");
    int n, q; in >> n >> q;
    vector<LL> data(n); LL sum = 0;
    for (auto &v : data)
        in >> v, sum += v;
    SegmentTree *sol = new SegmentTree(data);
    while (q--) {
        int l, r; in >> l >> r; l--;
        LL total = sol->query(0, n)->sum;
        LL cur = sol->query(l, r)->sum;
        if (total <= sum) {
            if (cur > 0)
                sol->modify(l, r, (cur - 1) / (r - l) + 1);
            else
                sol->modify(l, r, cur / (r - l));
        } else {
            if (cur > 0)
                sol->modify(l, r, cur / (r - l));
            else
                sol->modify(l, r, (cur + 1) / (r - l) - 1);
        }
    }
    for (int i = 0 ; i < n ; i++)
        out << sol->query(i, i + 1)->sum << " \n"[i + 1 == n];
    delete sol;
}
