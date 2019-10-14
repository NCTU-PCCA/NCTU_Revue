#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
set<pii> B;
const int MAXN = 1e5 + 5;
struct Graph {
    struct Node : vector<Node*> {
        int low, dfn;
        Node *pa;
        Node () {
            clear(); low = dfn = -1;
            pa = NULL;
        }
    }_memN[MAXN], *node[MAXN];
    int V;
    Graph (int _V) : V(_V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
        node[v]->push_back(node[u]);
    }
    int stamp;
    int solve() {
        stamp = 0;
        Tarjan(node[0], NULL);
        for (int i = 0 ; i < V ; i++) {
            Node *pa = node[i]->pa;
            if (pa && node[i]->low > pa->dfn)
                B.insert({pa - _memN, i}),
                B.insert({i, pa - _memN});
        }
    }
    void Tarjan(Node *u, Node *pa) {
        u->pa = pa;
        u->dfn = u->low = stamp++;
        for (auto &v : *u) {
            if (!~v->dfn) {
                Tarjan(v, u);
                u->low = min(u->low, v->low);
            } else if (pa != v)
                u->low = min(u->low, v->dfn);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    B.clear();
    vector<vector<int> > G(n);
    Graph *sol = new Graph(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        sol->addEdge(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sol->solve();
    vector<int> label(n, -1);
    int stamp = 0;
    for (int i = 0 ; i < n ; i++) {
        if (~label[i])
            continue;
        stamp++;
        queue<int> q; q.push(i); label[i] = stamp;
        while (q.size()) {
            int p = q.front(); q.pop();
            for (auto &v : G[p]) {
                if (B.count({p, v}))
                    continue;
                if (~label[v])
                    continue;
                q.push(v);
                label[v] = stamp;
            }
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (label[u] == label[v])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    delete sol;
}
