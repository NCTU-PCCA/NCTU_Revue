#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 4e5 + 5;
typedef pair<int, int> pii;
struct Graph {
    int V, stamp;
    struct Node : vector<Node*> {
        int low, dfn; bool is_cut; Node *pa;
        Node() {
            low = dfn = -1;
            is_cut = false;
            pa = NULL;
        }
    }_memN[MAXN], *node[MAXN];
    Graph (int V = 0) : V(V) {
        stamp = 0;
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void init(int _V) {
        stamp = 0;
        V = _V;
        for (int i = 0 ; i < V ; i++) {
            node[i] = _memN + i;
            node[i]->clear();
            node[i]->low = node[i]->dfn = -1;
            node[i]->is_cut = false;
            node[i]->pa = NULL;
        }
    }
    void addEdge(int u, int v) {
        node[u]->push_back(node[v]);
        node[v]->push_back(node[u]);
    }
    void Tarjan(Node *u, Node *pa, vector<int> &target) {
        target.push_back(u - _memN);
        u->pa = pa; u->dfn = u->low = ++stamp;
        for (auto &v : *u) if (!~v->dfn)
            Tarjan(v, u, target), u->low = min(u->low, v->low);
        else if (pa != v)
            u->low = min(u->low, v->dfn);
    }
    void Cut() {
        for (int i = 0 ; i < V ; i++) {
            if (node[i]->pa)
                continue;
            vector<int> target;
            Tarjan(node[i], NULL, target);
            int rt_son = 0;
            for (int _i = 1 ; _i < target.size() ; _i++) {
                int i = target[_i];
                Node *pa = node[i]->pa;
                if (pa == node[target[0]]) rt_son++;
                else if (node[i]->low >= pa->dfn)
                    pa->is_cut = true;
            }
            if (rt_son > 1) node[target[0]]->is_cut = true;
        }
    }
};
int getId(int x, map<int, int> &ID, vector<int> &list) {
    int sz = ID.size();
    if (!ID.count(x)) {
        ID[x] = sz;
        list.push_back(x);
    }
    return ID[x];
}
int bfs(vector<vector<pii> > &G, int s, vector<int> &vis, Graph *sol) {
    int target = -1;
    vis[s] = 1; queue<int> q; q.push(s); while (q.size()) {
        int p = q.front(); q.pop();
        if (target == -1 && !sol->node[p]->is_cut)
            target = p;
        for (auto &e : G[p]) {
            if (vis[e.F])
                continue;
            vis[e.F] = 1;
            q.push(e.F);
        }
    }
    return target;
}
struct A {
    int id, before, after;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Graph *sol = new Graph();
    int t; cin >> t; while (t--) {
        int m; cin >> m;
        vector<int> list;
        map<int, int> ID;
        vector<pii> data(m);
        for (auto &p : data) {
            cin >> p.F >> p.S;
            p.F = getId(p.F, ID, list);
            p.S = getId(p.S, ID, list);
        }
        sol->init(ID.size());
        vector<vector<pii> > G(ID.size());
        for (int i = 0 ; i < m ; i++) {
            auto p = data[i];
            sol->addEdge(p.F, p.S);
            G[p.F].push_back({p.S, i + 1});
            G[p.S].push_back({p.F, i + 1});
        }
        sol->Cut();
        vector<int> vis(ID.size(), 0);
        bfs(G, 0, vis, sol);
        vector<A> ans;
        for (int i = 0 ; i < ID.size() ; i++) {
            if (vis[i])
                continue;
            int x = bfs(G, i, vis, sol);
            ans.push_back({G[x].front().second, list[x], list[0]});
        }
        cout << ans.size() << '\n';
        for (auto &a : ans)
            cout << a.id << ' ' << a.before << ' ' << a.after << '\n';
    }
    delete sol;
}
