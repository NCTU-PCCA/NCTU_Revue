#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
int getId(int x, int y) {
    return x * m + y;
}
const int MAXN = 1e6 + 5;
const int lgN  = __lg(MAXN) + 5;
struct Tree {
    int V;
    struct Node : vector<Node*> {
        Node *p[lgN]; LL dep;
    }_memN[MAXN], *node[MAXN], *rt;
    Tree(int V) : V(V) { 
        rt = node[0];
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
        node[v]->push_back(node[u]);
    }
    void run() {
        dfs(node[0], node[0], 0);
    }
    void dfs(Node *u, Node *p, int dep) {
        u->p[0] = p, u->dep = dep;
        for (int i = 1 ; i < lgN ; i++)
            u->p[i] = u->p[i - 1]->p[i - 1];
        for (auto &v : *u)
            if (v != p) dfs(v, u, dep + 1);
    }
    LL query(int _u, int _v) {
        Node *u = node[_u], *v = node[_v]; LL ret = 0;
        if (u->dep < v->dep) swap(u, v);
        for (int i = lgN - 1 ; ~i ; i--)
            if (u->p[i]->dep >= v->dep)
                ret += u->dep - u->p[i]->dep, u = u->p[i];
        if (u == v) return ret;
        for (int i = lgN - 1 ; ~i ; i--)
            if (u->p[i] != v->p[i])
                ret += (u->dep - u->p[i]->dep) * 2,
                u = u->p[i], v = v->p[i];
        return ret + 2;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    string s;
    getline(cin, s);
    getline(cin, s);
    Tree *sol = new Tree(n * m);
    for (int i = 0 ; i < n ; i++) {
        getline(cin, s);
        s = s.substr(1, s.size() - 1);
        for (int j = 0 ; j < m ; j++) {
            if (s[j * 2] == ' ') {
                sol->addEdge(getId(i, j), getId(i + 1, j));
            }
            if (s[j * 2 + 1] == ' ') {
                sol->addEdge(getId(i, j), getId(i, j + 1));
            }
        }
    }
    sol->run();
    /*
    for (int i = 0 ; i < n * m ; i++) {
        cout << "node " << i << endl;
        cout << "pa: ";
        for (int j = 0; j < lgN ; j++)
            cout << sol->node[i]->p[j] - sol->_memN << ' ';
        cout << endl;
    }
    */
    int q; cin >> q; q--;
    int x, y; cin >> x >> y; x--, y--;
    LL ans = 0;
    while (q--) {
        int nx, ny; cin >> nx >> ny; nx--, ny--;
        ans += sol->query(getId(x, y), getId(nx, ny));
        /*
        cout << "(" << x << "," << y << ") -> (" << nx << "," << ny << "): " << sol->query(getId(x, y), getId(nx, ny)) << endl;
        */
        x = nx, y = ny;
    }
    cout << ans << '\n';
}
