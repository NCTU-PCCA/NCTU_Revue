// NCTU_Revue
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
const int MAXN = 5e5 + 5;
const int lgN  = __lg(MAXN) + 5;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct SegmentTree {
    struct Node {
        int L, R;
        Node *l, *r;
        LL minV, add;
        Node (int _L = 0, int _R = 0) {
            L = _L, R = _R;
            l = r = NULL;
            minV = INF; add = 0;
        }
    }*rt, buf[lgN << 1], *ptr;
    SegmentTree(vector<LL> &arr) {
        rt = build(0, arr.size(), arr);
    }
    ~SegmentTree() { remove(rt); }
    void remove(Node *u) {
        if (!u) return ;
        remove(u->l); remove(u->r);
        delete u;
    }
    Node* build(int L, int R, vector<LL> &arr) {
        Node *u = new Node(L, R);
        if (R - L == 1) {
            u->minV = arr[L];
            return u;
        }
        int M = (R + L) >> 1;
        u->l = build(L, M, arr);
        u->r = build(M, R, arr);
        return pull(u);
    }
    inline Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    inline Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        push(l); push(r);
        u->minV = min(l->minV, r->minV);
        return u;
    }
    inline Node* push(Node *u) {
        if (!u) return u;
        if (u->add) {
            u->minV += u->add;
            if (u->l) u->l->add += u->add;
            if (u->r) u->r->add += u->add;
            u->add = 0;
        }
        return u;
    }
    void modify(int mL, int mR, LL v, Node *u = NULL) {
        if (!u) u = rt; push(u);
        if (mR <= u->L || u->R <= mL) return ;
        if (mL <= u->L && u->R <= mR) {
            u->add += v;
            return ;
        }
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        pull(u);
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        push(u);
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void print() {
        print(rt);
        cout << '\n';
    }
    void print(Node *u) {
        if (!u) return ;
        cout << u->L << ' ' << u->R << ' ' << u->minV << '\n';
        print(u->l);
        print(u->r);
    }
};
struct Tree { int V;
    struct Node : vector<Node*> {
        int sz, dep, dfn;
        Node *pa, *top, *hc;
    }_memN[MAXN], *node[MAXN], *rt;
    SegmentTree *seg;
    Tree(int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
        rt = node[0];
    }
    inline void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
        node[v]->push_back(node[u]);
    }
    int stamp;
    inline void HLD() {
        stamp = 0;
        dfs_size(rt);
        dfs_link(rt, rt);
    }
    void dfs_size(Node *u) {
        u->sz = 1; u->hc = NULL;
        for (auto &v : *u) {
            if (v == u->pa) continue;
            v->pa = u;
            v->dep = u->dep + 1;
            dfs_size(v);
            if (!u->hc || v->sz > u->hc->sz)
                u->hc = v;
            u->sz += v->sz;
        }
    }
    void dfs_link(Node *u, Node *_top) {
        u->dfn = stamp++;
        u->top = _top;
        if (!u->hc) return ;
        dfs_link(u->hc, _top);
        for (auto &v : *u) {
            if (v == u->hc || v == u->pa) continue;
            dfs_link(v, v);
        }
    }
    inline void modify(int _u, int _v, LL add) {
        Node *u = node[_u], *v = node[_v];
        Node *uTop = u->top, *vTop = v->top;
        while (uTop != vTop) {
            if (uTop->dep < vTop->dep)
                swap(u, v), swap(uTop, vTop);
            seg->modify(uTop->dfn, u->dfn + 1, add);
            uTop = (u = uTop->pa)->top;
        }
        if (u->dep > v->dep) swap(u, v);
        seg->modify(u->dfn, v->dfn + 1, add);
        return ;
    }
    inline LL query(int _u, int _v) {
        Node *u = node[_u], *v = node[_v];
        Node *uTop = u->top, *vTop = v->top;
        LL ans = INF;
        while (uTop != vTop) {
            if (uTop->dep < vTop->dep)
                swap(u, v), swap(uTop, vTop);
            ans = min(ans, seg->query(uTop->dfn, u->dfn + 1)->minV);
            uTop = (u = uTop->pa)->top;
        }
        if (u == v) return ans;
        if (u->dep > v->dep) swap(u, v);
        return min(ans, seg->query(u->dfn + 1, v->dfn + 1)->minV);
    }
};
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL t; cin >> n >> t;
    vector<LL> d(n + 1), w(n + 1); 
    d[0] = 0, w[0] = INF;
    Tree *sol = new Tree(n + 1);
    vector<pii> pool;
    for (int i = 1 ; i <= n ; i++) {
        int p; cin >> d[i] >> p >> w[i];
        sol->addEdge(i, p);
        pool.push_back({-d[i], i});
    }
    sol->HLD();
    vector<LL> segW(n + 1);
    for (int i = 0 ; i <= n ; i++) {
        segW[sol->node[i]->dfn] = w[i];
    }
    sol->seg = new SegmentTree(segW);
    sort(pool.begin(), pool.end());
    LL ans = 0;
    for (int i = 0 ; i < n ; i++) {
        LL minV =  min(t, sol->query(0, pool[i].second));
        ans += minV * -pool[i].first;
        t -= minV;
        sol->modify(0, pool[i].second, -minV);
    }
    cout << ans << '\n';
    delete sol->seg;
    delete sol;
}
