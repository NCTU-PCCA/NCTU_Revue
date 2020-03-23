#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int lgN = __lg(MAXN);
const int INF = 0x3f3f3f3f;
struct Seg {
    struct Node {
        Node *l, *r; int v;
        int L, R;
        Node (int L = 0, int R = 0) : l(NULL), r(NULL), L(L), R(R) {}
    }buf[lgN << 2], *ptr, *rt, memN[MAXN << 2], *nodePtr;
    Seg(int n) {
        nodePtr = memN;
        rt = build(0, n);
    }
    Node* build(int L, int R) {
        Node *u = new (nodePtr++) Node(L, R);
        int M = (L + R) >> 1;
        if (R - L == 1) return u->v = 0, u;
        return u->l = build(L, M), u->r = build(M, R), pull(u);
    }
    Node* pull(Node *u) { return pull(u, u->l, u->r); }
    Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        u->v = min(l->v, r->v);
        return u;
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, int v, Node *u = NULL) {
        if (!u) u = rt; 
        if (mR <= u->L || u->R <= mL) return ;
        if (mL <= u->L && u->R <= mR)
            return u->v = v, void();
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        pull(u);
    }
    ~Seg() { clear(rt); }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l);
        clear(u->r);
        delete u;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<char> > G(n, vector<char>(n));
    vector<Seg*> row(n), col(n);
    for (int i = 0 ; i < n ; i++)
        row[i] = new Seg(n),
        col[i] = new Seg(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> G[i][j];
            if (G[i][j] == '#')
                row[i]->modify(j, j + 1, INF),
                col[j]->modify(i, i + 1, INF);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (G[i][j] == '#')
                continue;
            if (i == 0 && j == 0) continue;
            int minV = INF;
            if (i != 0) { // ver
                minV = min(minV, col[j]->query(max(0, i - k), i)->v);
            }
            if (j != 0) { // hor
                minV = min(minV, row[i]->query(max(0, j - k), j)->v);
            }
            row[i]->modify(j, j + 1, minV + 1);
            col[j]->modify(i, i + 1, minV + 1);
        }
    }
    int ans = row[n - 1]->query(n - 1, n)->v;
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
