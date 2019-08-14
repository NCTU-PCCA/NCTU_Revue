#include <bits/stdc++.h>
using namespace std;
#define PNN pair<Node*, Node*>
#define MP make_pair
#define F first
#define S second
typedef long long LL;
struct Treap {
    struct Node {
        Node *l, *r;
        int sz;
        // data
        LL sum, v ;
        Node (LL _v) : v(_v) {
            l = r = NULL;
            sz = 1;
            sum = v;
        }
    }*rt;
    Treap() {
        rt = NULL;
    }
    ~Treap() {
        clear(rt);
    }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l);
        clear(u->r);
        delete u;
    }
    inline int size(Node *u) {
        return u ? u->sz : 0;
    }
    inline Node*& pull(Node *&u) {
        u->sz = 1 + size(push(u->l)) + size(push(u->r));
        u->sum = u->v;
        if (u->l)
            u->sum += u->l->sum;
        if (u->r)
            u->sum += u->r->sum;
        return u;
    }
    inline Node*& push(Node *&u) {
        if (!u) return u;
        return u;
    }
    PNN split(Node *T, int x) {
        if (!T) return MP((Node*)NULL, (Node*)NULL);
        if (size(push(T)->l) < x) {
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
            T1->r = merge(push(T1)->r, T2);
            return pull(T1);
        } else {
            T2->l = merge(T1, push(T2->l));
            return pull(T2);
        }
    }
    int rank(LL v, Node *u) {
        if (!u) return 0;
        return v < u->v ? rank(v, u->l) : size(u->l) + rank(v, u->r) + 1;
    }
    void insert(LL v) {
        int x = rank(v, rt);
        PNN tmp = split(rt, x);
        rt = merge(merge(tmp.F, new Node(v)), tmp.S);
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
    LL solve(LL v) {
        int x = rank(v, rt);
        PNN tmp = split(rt, x);
        LL ret = 0;
        if (tmp.F) {
            ret += abs(tmp.F->sum - size(tmp.F) * v);
        }
        if (tmp.S) {
            ret += abs(size(tmp.S) * v - tmp.S->sum);
        }
        rt = merge(tmp.F, tmp.S);
        return ret;
    }
    void erase(LL v) {
        int x = rank(v, rt);
        PNN tmp_1 = split(rt, x);
        PNN tmp_2 = split(tmp_1.F, x - 1);
        delete tmp_2.S;
        rt = merge(tmp_2.F, tmp_1.S);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> data(n);
    for (auto &v : data)
        cin >> v;
    Treap *sol[2];
    sol[0] = new Treap();
    sol[1] = new Treap();
    for (int i = 0 ; i < k ; i++)
        sol[i % 2]->insert(data[i]);
    LL ans = 0;
    if (k % 2) {
        for (int i = 0 ; i < n ; i++) {
            ans += sol[i % 2]->solve(data[i]);
            if (i + k < n)
                sol[(i + k) % 2]->insert(data[i + k]);
            if (i - k >= 0)
                sol[(i - k) % 2]->erase(data[i - k]);
        }
    } else {
        for (int i = 0 ; i < n ; i++) {
            ans += sol[(i + 1) % 2]->solve(data[i]);
            if (i + k < n)
                sol[(i + k) % 2]->insert(data[i + k]);
            if (i - k >= 0)
                sol[(i - k) % 2]->erase(data[i - k]);
        }
    }
    delete sol[0];
    delete sol[1];
    sol[0] = new Treap();
    sol[1] = new Treap();
    LL sub = 0;
    if (k % 2) {
        for (int i = 0 ; i < k - 2 ; i++)
            sol[i % 2]->insert(data[i]);
        int r = k - 3;
        for (int i = 0 ; i < r ; i++, r--) {
            sub += sol[i % 2]->solve(data[i]);
            sol[i % 2]->erase(data[i]);
            sol[i % 2]->erase(data[r]);
        }
        delete sol[0];
        delete sol[1];
        sol[0] = new Treap();
        sol[1] = new Treap();
        reverse(data.begin(), data.end());
        r = k - 3;
        for (int i = 0 ; i < k - 2 ; i++)
            sol[i % 2]->insert(data[i]);
        for (int i = 0 ; i < r ; i++, r--) {
            sub += sol[i % 2]->solve(data[i]);
            sol[i % 2]->erase(data[i]);
            sol[i % 2]->erase(data[r]);
        } 
        cout << ans / 2 - sub << '\n';
    } else {
        for (int i = 0 ; i < k - 2 ; i++)
            sol[i % 2]->insert(data[i]);
        int r = k - 3;
        for (int i = 0 ; i < r ; i++, r--) {
            sub += sol[(i + 1) % 2]->solve(data[i]);
            sol[i % 2]->erase(data[i]);
            sol[(i + 1) % 2]->erase(data[r]);
        }
        reverse(data.begin(), data.end());
        r = k - 3;
        delete sol[0];
        delete sol[1];
        sol[0] = new Treap();
        sol[1] = new Treap();
        for (int i = 0 ; i < k - 2 ; i++)
            sol[i % 2]->insert(data[i]);
        for (int i = 0 ; i < r ; i++, r--) {
            sub += sol[(i + 1) % 2]->solve(data[i]);
            sol[i % 2]->erase(data[i]);
            sol[(i + 1) % 2]->erase(data[r]);
        } 
        cout << ans / 2 - sub << '\n';

        
    }
}


