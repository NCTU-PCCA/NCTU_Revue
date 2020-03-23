#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
struct Graph {
    int V, stamp, scc_num;
    struct Node : vector<Node*> {
        int dfn, low, scc, inS;
        Node() { dfn = low = scc = -1; inS = 0; clear(); }
    }_memN[MAXN], *node[MAXN];
    Graph(int V) : V(V) {
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
    }
    int findSCC() {
        stamp = scc_num = 0;
        for (int i = 0 ; i < V ; i++) {
            if (!~node[i]->dfn)
                Tarjan(node[i]);
        }
        return scc_num;
    }
    stack<Node*> stk;
    void Tarjan(Node *u) {
        u->dfn = u->low = stamp++;
        stk.push(u); u->inS = true;
        for (auto &v : *u) if (!~v->dfn) Tarjan(v),
            u->low = min(u->low, v->low);
        else if (v->inS)
            u->low = min(u->low, v->dfn);
        if (u->dfn == u->low) {
            Node *v; do {
                v = stk.top(); stk.pop();
                v->scc = scc_num; v->inS = false;
            } while (v != u); scc_num++;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        Graph *sol = new Graph(n);
        int m; cin >> m;
        while (m--) {
            int u, v; cin >> u >> v;
            sol->addEdge(u, v);
        }
        cout << sol->findSCC() << '\n';
        delete sol;
    }
}
