#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
ll del[] = {0, 1, 2, 3, 2, 1, 0};
vector<vector<ll> > val, dif;
struct SegmentTree {
    struct Node {
        int L, R;
        ll maxV, lsum, rsum, sum;
        Node *l, *r;
        Node (int L = 0, int R = 0) : L(L), R(R) {
            l = r = NULL;
            maxV = lsum = rsum = sum = 0;
        }
    }*rt, *ptr, *buf;
    SegmentTree(vector<ll> &arr) {
        rt = build(0, arr.size(), arr);
        buf = new Node[__lg(arr.size()) * 4 + 5];
    }
    ~SegmentTree() {
        delete buf;
        clear(rt);
    }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l);
        clear(u->r);
        delete u;
    }
    Node* build(int L, int R, vector<ll> &arr) {
        Node *u = new Node(L, R);
        if (u->R - u->L == 1) return u->maxV = u->lsum = u->rsum = u->sum = arr[L], u;
        int M = (R + L) >> 1;
        u->l = build(L, M, arr); u->r = build(M, R, arr);
        return pull(u);
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (u->R <= qL || qR <= u->L) return NULL;
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    Node* pull(Node *u) { return pull(u, u->l, u->r); }
    Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        u->sum = l->sum + r->sum;
        u->lsum = max({l->lsum, l->sum + r->lsum, 0LL});
        u->rsum = max({r->rsum, l->rsum + r->sum, 0LL});
        u->maxV = max({u->lsum, u->rsum, l->maxV, r->maxV, l->rsum + r->lsum, 0LL});
        return u;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    val.clear(); val.resize(n, vector<ll>(7));
    for (int i = 0 ; i < n ; i++) {
        ll v, d; cin >> v >> d;
        for (int j = 0 ; j < 7 ; j++) {
            val[i][j] = v + d * del[j];
        }
    }
    vector<ll>dif[7];
    vector<ll>rev[7];
    for (int i = 0 ; i < 7 ; i++) {
        int now = i;
        int nxt = (i+1)%7;
        // cout << "dif[" << i << "]: ";
        for(int j=0;j<n-1;j++){
            dif[i].pb(val[j+1][nxt]-val[j][now]);
            // cout << dif[i].back() << ' ';
            now++;
            now %= 7;
            nxt++;
            nxt %= 7;
        }
        // cout << '\n';
    }
    for(int i = 0 ; i < 7 ; i++){
        int now = i;
        int nxt = (i-1+7)%7;
        // cout << "rev[" << i << "]: ";
        for(int j=0;j<n-1;j++){
            rev[i].pb(-val[j+1][nxt]+val[j][now]);
            // cout << rev[i].back() << ' ';
            now--;
            now += 7;
            now %= 7;
            nxt--;
            nxt += 7;
            nxt %= 7;
        }
        // cout << '\n';
    }
    SegmentTree *sol[14];
    for (int i = 0 ; i < 7 ; i++)
        sol[i] = new SegmentTree(dif[i]);
    for (int i = 0 ; i < 7 ; i++)
        sol[i + 7] = new SegmentTree(rev[i]);
    int q; cin >> q; while (q--) {
        int l, r; cin >> l >> r;
        if (l <= r) {
            int now = l % 7;
            int idx = (7 - now + 1) % 7;
            l--; r--;
            // cout << "query: " << idx << ' ' << l << ' ' << r << '\n';
            cout << max(0LL, sol[idx]->query(l, r)->maxV) << '\n';
        } else {
            swap(l, r);
            int idx = (r - 1) % 7;
            l--; r--;
            // cout << "query: " << idx + 7 << ' ' << l << ' ' << r << '\n';
            cout << max(0LL, sol[idx + 7]->query(l, r)->maxV) << '\n';
        }
    }
}
