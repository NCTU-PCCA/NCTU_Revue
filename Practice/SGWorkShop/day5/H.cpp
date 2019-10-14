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
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
#define PTR Node*
const LL MOD = 998244353;
struct SegmentTree {
    struct Node {
        int L, R; LL sum, minV;
        PTR l; PTR r;
        Node (int L = 0, int R = 0) : l(NULL), r(NULL), L(L), R(R), sum(0), minV(0) {}
    };
    PTR buf; PTR ptr;
    ~SegmentTree() {
        clear(rt.back()); delete []buf;
    }
    void clear(PTR u) {
        if (u) clear(u->l), clear(u->r), delete u;
    }
    vector<PTR> rt;
    SegmentTree (int n) {
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
        u->sum = (l->sum + r->sum) % MOD;
        u->minV = min(l->minV, r->minV);
        return u;
    }
    PTR pull(PTR u) { return pull(u, u->l, u->r); }
    PTR query(int qL, int qR, PTR u) {
        if (u->R <= qL || qR <= u->L) return NULL;
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    PTR modify(int mL, int mR, LL v, PTR u) {
        if (u->R <= mL || mR <= u->L) return u;
        if (mL <= u->L && u->R <= mR) {
            u->sum = u->minV = v;
            return u;
        }
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        return pull(u);
    }
    PTR query(int qL, int qR) {
        ptr = buf;
        return query(qL - 1, qR, rt.back());
    }
    PTR modify(int x, LL v) {
        return modify(x - 1, x, v, rt.back());
    }
};
int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<LL> data(n + 1);
        vector<int> cnt(n + 2, 0);
        for (int i = 1 ; i <= n ; i++)
            cin >> data[i], data[i]++, cnt[data[i]]++;
        int mex = -1;
        for (int i = 1 ;; i++) {
            if (cnt[i])
                continue;
            mex = i - 1;
            break;
        }
        if (mex == 0) {
            LL ret = 1;
            for (int i = 0 ; i < n - 1 ;i++)
                ret *= 2, ret %= MOD;
            cout << ret << '\n';
            continue;
        }
        SegmentTree *idx = new SegmentTree(n);
        SegmentTree *sum = new SegmentTree(n);
        for (int i = 1 ; i <= n ; i++) {
            idx->modify(data[i], i);
            auto u = idx->query(1, mex);
            LL tar = u->minV;
            if (tar == 0)
                continue;
            tar--;
            if (tar == 0) {
                sum->modify(i, 1);
            } else {
                LL chg = sum->query(1, tar)->sum + 1;
                sum->modify(i, chg);
            }
        }
        cout << sum->query(n, n)->sum << '\n';
        delete idx;
        delete sum;
    }
}
