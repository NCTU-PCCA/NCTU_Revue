#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int lgN = __lg(MAXN) + 5;
const int INF = 0x3f3f3f3f;
struct SegTree {
    struct Node {
        int L, R;
        Node *l, *r;
        int maxV, minV, tag;
        int sum;
        Node (int _L = 0, int _R = 0) {
            L = _L, R = _R;
            l = r = NULL;
            maxV = minV = tag = 0;
        }
    }*rt, buf[lgN << 1], *ptr;
    int n;
    SegTree(int _n) { n = _n;
        rt = build(0, n);
    }
    Node* build(int L, int R) {
        Node *u = new Node(L, R);
        if (R - L == 1) {
            u->maxV = u->minV = u->tag = 0;
            u->sum = 1;
            return u;
        }
        int M = (L + R) >> 1;
        u->l = build(L, M);
        u->r = build(M, R);
        return pull(u);
    }
    inline Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    inline Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        push(l); push(r);
        u->maxV = max(l->maxV, r->maxV);
        u->minV = min(l->minV, r->minV);
        u->sum = l->sum + r->sum;
        return u;
    }
    inline Node* push(Node *u) {
        if (!u) return u;
        if (u->tag) {
            u->maxV = u->minV = u->tag;
            if (u->l) u->l->tag = u->tag;
            if (u->r) u->r->tag = u->tag;
            u->tag = 0;
        }
        return u;
    }
    inline void modify(int L, int R, int v) {
        return modify(L, R, v, rt);
    }
    void modify(int L, int R, int v, Node *u) {
        if (u->R <= L || R <= u->L) return ;
        push(u);
        if (L <= u->L && u->R <= R) {
            u->tag = v;
            return ;
        }
        modify(L, R, v, u->l);
        modify(L, R, v, u->r);
        pull(u);
    }
    inline Node* query(int L, int R) {
        ptr = buf;
        return query(L, R, rt);
    }
    inline Node* query(int L, int R, Node *u) {
        if (u->R <= L || R <= u->L) return NULL;
        push(u);
        if (L <= u->L && u->R <= R) return u;
        return pull(ptr++, query(L, R, u->l), query(L, R, u->r));
    }
    void print(Node *u) {
        if (!u) return ;
        print (u->l);
        cout << u->L << ' ' << u->R << ' ' << u->sum << '\n';
        print (u->r);
    }
};
struct Tree {
    int V;
    struct Node : vector<Node*> {
        int sz, dep, dfn;
        Node *pa, *top, *hc;
    }_memN[MAXN], *node[MAXN], *rt;
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
    SegTree *seg;
    inline void modify(int _u, int _v, int chg) {
        Node *u = node[_u], *v = node[_v];
        Node *uTop = u->top, *vTop = v->top;
        while (uTop != vTop) {
            if (uTop->dep < vTop->dep)
                swap(u, v), swap(uTop, vTop);
            if (uTop->dfn != u->dfn + 1)
                seg->modify(uTop->dfn, u->dfn + 1, chg);
            uTop = (u = uTop->pa)->top;
        }
        if (u->dep > v->dep) swap(u, v);
        if (u->dfn != v->dfn + 1)
            seg->modify(u->dfn, v->dfn + 1, chg);
        return ;
    }
    inline pair<pair<int, int>, int> query(int _u, int _v) {
        Node *u = node[_u], *v = node[_v];
        Node *uTop = u->top, *vTop = v->top;
        int minV = INF, maxV = 0, sum = 0;
        while (uTop != vTop) {
            if (uTop->dep < vTop->dep)
                swap(u, v), swap(uTop, vTop);
            if (uTop->dfn != u->dfn + 1) {
//                cout << "query " << uTop->dfn << ' ' << u->dfn + 1 << '\n';
                auto res = seg->query(uTop->dfn, u->dfn + 1);
                minV = min(minV, res->minV);
                maxV = max(maxV, res->maxV);
                sum += res->sum;
            }
            uTop = (u = uTop->pa)->top;
        }
        if (u->dep > v->dep) swap(u, v);
        if (u->dfn != v->dfn + 1) {
            auto res = seg->query(u->dfn, v->dfn + 1);
            minV = min(minV, res->minV);
            maxV = max(maxV, res->maxV);
//            cout << "query " << u->dfn << ' ' << v->dfn + 1 << '\n';
            sum += res->sum;
        }
        return {{minV, maxV}, sum};
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    Tree *tree = new Tree(n);
    for (int i = 1 ; i < n ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree->addEdge(u, v);
    }
    tree->HLD();
//    for (int i = 0 ; i < n ; i++) {
//        cout << "node " << i + 1 << ": " << tree->node[i]->dfn << '\n';
//    }
    vector<pair<int, pair<int, int>> > pool(m);
    tree->seg = new SegTree(n);
//    tree->seg->print(tree->seg->rt);
    for (auto &p : pool) {
        cin >> p.S.F >> p.S.S; p.S.F--, p.S.S--;
//        cout << "raw input: " << p.S.F << ' ' << p.S.S << '\n';
//        p.S.F = tree->node[p.S.F]->dfn;
//        p.S.S = tree->node[p.S.S]->dfn;
//        cout << "input: " << p.S.F << ' ' << p.S.S << '\n';
        p.F = tree->query(p.S.F, p.S.S).S;
    }
    sort(pool.begin(), pool.end());
    reverse(pool.begin(), pool.end());
    int stamp = 1;
    for (auto &_p : pool) {
        pair<int, int> p = _p.S;
//        cout << _p.F << ' ' << p.F << ' ' << p.S << '\n';
        auto res = tree->query(p.F, p.S);
        if (res.F.F != res.F.S) {
            cout << "No\n";
            return 0;
        }
        tree->modify(p.F, p.S, stamp++);
    }
    cout << "Yes\n";
}
