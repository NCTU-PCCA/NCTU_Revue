#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
struct BST {
    struct Node {
        int v;
        Node *l, *r;
        Node(int v = 0) : v(v) {
            l = r = NULL;
        }
    }*rt;
    void insert(int v) {
        Node *u = rt;
        if (!u)
            rt = new Node(v);
        while (u) {
            if (v < u->v) {
                if (u->l == NULL) {
                    u->l = new Node(v);
                    break;
                } else
                    u = u->l;
            } else {
                if (u->r == NULL) {
                    u->r = new Node(v);
                    break;
                } else
                    u = u->r;
            }
        }
    }
    LL find(int v) {
        LL ret = 0;
        Node *u = rt;
        while (u) {
            ret += u->v;
            if (v < u->v)
                u = u->l;
            else if (v == u->v)
                break;
            else
                u = u->r;
        }
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<BST> bst(n);
    while (q--) {
        int op; cin>> op;
        if (op == 1) {
            int l, r, w; cin >> l >> r >> w;
            l--, r--;
            for (int i = l ; i <= r ; i++)
                bst[i].insert(w);
        } else {
            int x, a; cin >> x >> a;
            x--;
            cout << bst[x].find(a) << '\n';
        }
    }
}
