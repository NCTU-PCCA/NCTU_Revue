#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
set<pair<int, int> > B;
struct Graph {
    struct Node : vector<Node*> {
        int low, dfn;
        Node *pa;
        Node () {
            clear(), low = dfn = -1;
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
    int findB() {
        stamp = 0;
        int ans =0;
        Tarjan(node[0], NULL);
        for (int i = 0 ; i < V ; i++) {
            Node *pa = node[i]->pa;
            if (pa && node[i]->low > pa->dfn) {
                pair<int, int> p = {pa - _memN, node[i] - _memN};
                if (p.first > p.second)
                    swap(p.first, p.second);
                B.insert(p);
            }
        }
    }
    void Tarjan(Node *u, Node *pa) {
        u->pa = pa;
        u->dfn = u->low = stamp++;
        for (auto &to : *u) {
            if (!~to->dfn) {
                Tarjan(to, u);
                u->low = min(u->low, to->low);
            } else if (pa != to) 
                u->low = min(u->low, to->dfn);
        }
    }
};
vector<int> bfs(vector<vector<int> > &G, int s) {
    vector<int> d(G.size(), -1);
    queue<int> q; q.push(s); d[s] = 0; while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (~d[v])
                continue;
            d[v] = d[p] + 1;
            q.push(v);
        }
    }
    return d;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        B.clear();
        int n, m; cin >> n >> m;
        Graph *sol = new Graph(n);
        vector<vector<int> > G(n);
        while (m--) {
            int u, v; cin >> u >> v; u--, v--;
            sol->addEdge(u, v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        sol->findB();
        delete sol;
        if (B.size() == 0) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> level(n, -1); int stamp = -1;
        for (int i = 0 ; i < n ; i++) {
            if (~level[i]) continue;
            stamp++;
            queue<int> q; level[i] = stamp; q.push(i); while (q.size()) {
                int p = q.front(); q.pop();
                for (auto &v : G[p]) {
                    if (~level[v])
                        continue;
                    pair<int, int> e = {p, v};
                    if (e.first > e.second)
                        swap(e.first, e.second);
                    if (B.count(e))
                        continue;
                    level[v] = stamp;
                    q.push(v);
                }
            }
        }
        
        vector<vector<int> > T(B.size() + 1);
        for (auto &p : B) {
            T[level[p.first]].push_back(level[p.second]);
            T[level[p.second]].push_back(level[p.first]);
        }
        vector<int> res = bfs(T, 0);
        int maxV = 0, maxIdx = -1;
        for (int i = 0 ; i < (int)T.size() ; i++) {
            if (maxV < res[i])
                maxV = res[i], maxIdx = i;
        }
        res = bfs(T, maxIdx);
        maxV = 0;
        for (int i = 0 ; i < (int)T.size() ; i++) {
            maxV = max(maxV, res[i]);
        }
        cout << B.size() - maxV << '\n';
    }

}
