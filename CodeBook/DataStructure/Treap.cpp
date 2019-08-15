#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F first
#define S second
const int MAXN = 2e5 + 5;
// LatexBegin
#define PNN pair<Node*, Node*>
struct Treap {
    struct Node {
        Node *l, *r;
        int sz, v;
        // data
        int minV;
        // tag
        int add;
        bool rev;
        Node (int v = 0) : v(v) {
            l = r = NULL;
            sz = 1;
            add = 0; rev = false;
        }
    }*rt, _mem[MAXN], *ptr;
    Treap() { rt = NULL; ptr = _mem; }
    inline int size(Node *u) {
        return u ? u->sz : 0;
    }
    inline Node*& pull(Node *&u) {
        u->sz = 1 + size(push(u->l)) + size(push(u->r));
        // pull function
// LatexEnd
        u->minV = u->v;
        if (u->l) u->minV = min(u->minV, u->l->minV);
        if (u->r) u->minV = min(u->minV, u->r->minV);
// LatexBegin
        return u;
    }
    inline Node*& push(Node *&u) {
        if (!u) return u;
        // push function
// LatexEnd
        if (u->add){
            u->v += u->add;
            u->minV += u->add;
            if (u->l) u->l->add += u->add;
            if (u->r) u->r->add += u->add;
            u->add = 0;
        }
        if (u->rev){
            swap(u->l, u->r);
            if (u->l) u->l->rev ^= 1;
            if (u->r) u->r->rev ^= 1;
            u->rev = false;
        }
// LatexBegin
        return u;
    }
    PNN split(Node *T, int x) {
        if (!T) return {(Node*)NULL, (Node*)NULL};
        if (size(push(T)->l) < x) {
            PNN tmp = split(T->r, x - size(T->l) - 1);
            T->r = tmp.F;
            return {pull(T), tmp.S};
        } else {
            PNN tmp = split(T->l, x);
            T->l = tmp.S;
            return {tmp.F, pull(T)};
        }
    }
    Node* merge(Node *T1, Node *T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (rand() % (size(T1) + size(T2)) < size(T1)) {
            T1->r = merge(push(T1)->r, T2);
            return pull(T1);
        } else {
            T2->l = merge(T1, push(T2)->l);
            return pull(T2);
        }
    }
// LatexEnd
    void push_back(int v){
        rt = merge(rt, new (ptr++) Node(v));
    }
    void addV(int a, int b, int k){
        PNN tmp_1 = split(rt, b);
        PNN tmp_2 = split(tmp_1.F, a-1);
        tmp_2.S->add += k;
        tmp_1.F = merge(tmp_2.F, tmp_2.S);
        rt = merge(tmp_1.F, tmp_1.S);
    }
    void insert(int a, int v){
        PNN tmp = split(rt, a);
        tmp.F = merge(tmp.F, new (ptr++) Node(v));
        rt = merge(tmp.F, tmp.S);
    }
    void remove(int a){
        PNN tmp_1 = split(rt, a);
        PNN tmp_2 = split(tmp_1.F, a-1);
        rt = merge(tmp_2.F, tmp_1.S);
    }
    int queryMin(int a, int b){
        PNN tmp_1 = split(rt, b);
        PNN tmp_2 = split(tmp_1.F, a-1);
        int res = tmp_2.S->minV;
        tmp_1.F = merge(tmp_2.F, tmp_2.S);
        rt = merge(tmp_1.F, tmp_1.S);
        return res;
    }
    void reverse(int a, int b){
        PNN tmp_1 = split(rt, b);
        PNN tmp_2 = split(tmp_1.F, a-1);
        tmp_2.S->rev ^= 1;
        tmp_1.F = merge(tmp_2.F, tmp_2.S);
        rt = merge(tmp_1.F, tmp_1.S);
    }
    void revolve(int a, int b, int t){
        PNN tmp_1 = split(rt, b);
        PNN tmp_2 = split(tmp_1.F, a-1);
        int len = b - a + 1;
        t %= len;
        PNN tmp_3 = split(tmp_2.S, len - t);
        tmp_2.S = merge(tmp_3.S, tmp_3.F);
        tmp_1.F = merge(tmp_2.F, tmp_2.S);
        rt = merge(tmp_1.F, tmp_1.S);
    }
// LatexBegin
};
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Treap *sol = new Treap();
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++){
        int tmp; cin >> tmp;
        sol->push_back(tmp);
    }
    int q; cin >> q;
    while (q--){
        char input[10]; cin >> input;
        int a, b, k;
        if (input[0] == 'A'){
            cin >> a >> b >> k;
            sol->addV(a, b, k);
        }else if (input[0] == 'I'){
            cin >> a >> k;
            sol->insert(a, k);
        }else if (input[0] == 'D'){
            cin >> a;
            sol->remove(a);
        }else if (input[0] == 'M'){
            cin >> a >> b;
            cout << sol->queryMin(a, b) << '\n';
        }else if (input[3] == 'E'){
            cin >> a >> b;
            sol->reverse(a, b);
        }else if (input[3] == 'O'){
            cin >> a >> b >> k;
            sol->revolve(a, b, k);
        }else continue;
    }
    delete sol;
}
