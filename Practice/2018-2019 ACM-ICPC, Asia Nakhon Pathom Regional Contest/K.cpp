#include <bits/stdc++.h>
#define PNN pair<Node*, Node*>
#define MP make_pair
#define F first
#define S second
using namespace std;
struct E {
    int op; int v, t;
    bool operator < (const E &rhs) const {
        if (t == rhs.t)
            return op > rhs.op;
        return t < rhs.t;
    }
};
struct Treap {
    struct Node {
        Node *l, *r;
        int sz, v;
        Node (int _v) : v(_v) {
            l = r = NULL;
            sz = 1;
        }
    }*rt;
    Treap() { rt = NULL; }
    ~Treap() { clear(rt); }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l); clear(u->r);
        delete u;
    }
    inline int size(Node *u) {
        return u ? u->sz : 0;
    }
    inline Node*& pull(Node *&u) {
        u->sz = 1 + size(u->l) + size(u->r);
        return u;
    }
    PNN split(Node *T, int x) {
        if (!T) return MP((Node*)NULL, (Node*)NULL);
        if (size(T->l) < x) {
            PNN tmp = split(T->r, x - size(T->l) - 1);
            T->r = tmp.F;
            return MP(pull(T), tmp.S);
        } else {
            PNN tmp = split(T->l, x);
            T->l = tmp.S;
            return MP(tmp.F, pull(T));
        }
    }
    Node* merge(Node *T1, Node *T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (rand() % (size(T1) + size(T2)) < size(T1)) {
            T1->r = merge(T1->r, T2);
            return pull(T1);
        } else {
            T2->l = merge(T1, T2->l);
            return pull(T2);
        }
    }
    int rank(int v, Node *u) {
        if (!u) return 0;
        return v < u->v ? rank(v, u->l) : size(u->l) + rank(v, u->r) + 1;
    }
    void insert(int v) {
        int rk = rank(v, rt);
        PNN tmp = split(rt, rk);
        rt = merge(tmp.F, merge(new Node(v), tmp.S));
    }
    void erase(int v) {
        int rk = rank(v, rt) - 1;
        PNN tmp = split(rt, rk);
        PNN tmp_2 = split(tmp.S, 1);
        rt = merge(tmp.F, tmp_2.S);
        delete tmp_2.F;
    }
    int get(int rk) {
        PNN tmp = split(rt, rk);
        PNN tmp_2 = split(tmp.S, 1);
        int ret = tmp_2.F->v;
        rt = merge(tmp.F, merge(tmp_2.F, tmp_2.S));
        return ret;
    }
    void print(Node *u) {
        if (!u) return ;
        print(u->l);
        cout << u->v << ' ';
        print(u->r);
    }
    void print() {
        print(rt);
        cout << '\n';
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ":\n";
        int m; cin >> m;
        vector<E> events;
        while (m--) {
            int op; cin >> op;
            if (op == 1) {
                int l, r, v; cin >> l >> v >> r;
                events.push_back({1, v, l});
                events.push_back({-1, v, r});
            } else {
                int l, v; cin >> l >> v;
                events.push_back({2, v, l});
            }
        }
        sort(events.begin(), events.end());
        Treap *sol = new Treap();
        for (auto &e : events) {
            if (e.op == 1) {
                sol->insert(e.v);
            } else if (e.op == -1) {
                sol->erase(e.v);
            } else {
                if (e.v > sol->size(sol->rt))
                    cout << -1 << '\n';
                else {
                    cout << sol->get(e.v - 1) << '\n';
                }
            }
        }
        delete sol;
    }
}
