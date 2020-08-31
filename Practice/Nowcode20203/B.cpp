#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 5e5 + 50;
typedef pair<int, int> pii;
struct Treap {
    struct Node {
        int l, r, sz; char c; int pri;
        Node (char c = '\0') : c(c), sz(1) { pri = rand(); }
    } N[MAXN];
    int ptr, rt;
    inline void init() { ptr = 1; rt = 0; }
    inline int size(int u) { return u ? N[u].sz : 0; }
    inline int newNode(char v) { return N[ptr] = Node(v), ptr++; }
    int merge(int T1, int T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (N[T1].pri > N[T2].pri) {
            N[T1].r = merge(N[push(T1)].r, T2);
            return pull(T1);
        } else {
            N[T2].l = merge(T1, N[push(T2)].l);
            return pull(T2);
        }
    }
    pii split(int T, int x) {
        if (!T) return make_pair(0, 0);
        if (size(N[push(T)].l) < x) {
            pii tmp = split(N[T].r, x - size(N[T].l) - 1);
            N[T].r = tmp.F;
            return make_pair(pull(T), tmp.S);
        } else {
            pii tmp = split(N[T].l, x);
            N[T].l = tmp.S;
            return make_pair(tmp.F, pull(T));
        }
    }
    inline int pull(int u) {
        N[u].sz = size(push(N[u].l)) + size(push(N[u].r)) + 1;
        return u;
    }
    inline int push(int u) {
        return u;
    }
    void push_back(char c) {
        rt = merge(rt, newNode(c));
    }
    void print(int u) {
        if (!u) return ;
        print (N[u].l);
        cout << N[u].c;
        print (N[u].r);
    }
    char query(int x) {
        pii tmp_1 = split(rt, x);
        pii tmp_2 = split(tmp_1.F, x - 1);
        char res = N[tmp_2.S].c;
        rt = merge(merge(tmp_2.F, tmp_2.S), tmp_1.S);
        return res;
    }
    void front(int x) {
        pii tmp_1 = split(rt, x);
        rt = merge(tmp_1.S, tmp_1.F);
    }
    void back(int x) {
        pii tmp_1 = split(rt, size(rt) - x);
        rt = merge(tmp_1.S, tmp_1.F);
    }
} solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    string s; cin >> s; 
    solver.init();
    for (auto &c : s)
        solver.push_back(c);
    int q; cin >> q; while (q--) {
        string op; cin >> op;
        if (op == "A") {
            int x; cin >> x;
            cout << solver.query(x) << '\n';
        } else if (op == "M") {
            int x; cin >> x;
            if (x > 0) {
                solver.front(x);
            } else {
                solver.back(-x);
            }
        }
    }
}
