#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 2e5 + 5;
const int MAXM = 4e6 + 6;
typedef pair<int, int> pii;
struct Graph {
    struct Edge; int V;
    struct Node : vector<Edge*> {
        iterator cur; int d; Node() { clear(); }
    }_memN[MAXN], *node[MAXN], *s, *t;
    struct Edge { Node *u, *v; Edge *rev; LL c, f;
        Edge(Node *u, Node *v, LL c, Edge *rev)
            : u(u), v(v), c(c), f(0), rev(rev){}
        Edge(){}
    }_memE[MAXM], *ptrE;
    void realinit(int _V) { V = _V;
        ptrE = _memE;
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
    }
    void init() {
        ptrE = _memE;
        for (int i = 0 ; i < V ; i++)
            node[i]->clear();
    }
    void addEdge(int _u, int _v, LL _c) {
        *ptrE = Edge(node[_u], node[_v], _c, ptrE + 1);
        node[_u]->push_back(ptrE++);
        *ptrE = Edge(node[_v], node[_u],  0, ptrE - 1);
        node[_v]->push_back(ptrE++);
    }
    LL maxFlow(int _s, int _t) {
        s = node[_s], t = node[_t]; LL flow = 0;
        while (bfs()) {
            for (int i = 0 ; i < V ; i++)
                node[i]->cur = node[i]->begin();
            flow += dfs(s, INF);
        }
        return flow;
    }
    bool bfs() {
        for (int i = 0 ; i < V ; i++) node[i]->d = -1;
        queue<Node*> q; q.push(s); s->d = 0;
        while (q.size()) {
            Node *u = q.front(); q.pop();
            for (auto &e : *u) {
                Node *v = e->v;
                if (!~v->d && e->c > e->f)
                    q.push(v), v->d = u->d + 1;
            }
        }
        return ~t->d;
    }
    LL dfs(Node *u, LL a) {
        if (u == t || !a) return a; LL flow = 0, f;
        for (; u->cur != u->end(); u->cur++) {
            auto &e = *u->cur; Node *v = e->v;
            if (u->d + 1 == v->d && (f = dfs(v, min(a, e->c - e->f))) > 0) {
                e->f += f; e->rev->f -= f; flow += f; a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
} sol;
typedef struct Edge {
    int v; LL w;
    bool operator > (const Edge &b) const {
        return w > b.w;
    }
} S;
vector<LL> Dijkstra(vector<vector<Edge> > &G, int s) {
    priority_queue<S, vector<S>, greater<S> > pq;
    vector<LL> d(G.size(), INF);
    d[s] = 0; pq.push({s, d[s]});
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (d[p.v] < p.w) continue;
        for (auto &e : G[p.v]) {
            if (d[e.v] > d[p.v] + e.w) {
                d[e.v] = d[p.v] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s; LL sum = 0; cin >> n >> m >> s;
    vector<int> cap(n);
    for (auto &v : cap)
        cin >> v, sum += v;
    vector<vector<Edge> > G(n);
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<pii> _S(s);
    for (auto &v : _S) {
        cin >> v.F >> v.S;
        v.F--;
    }
    vector<vector<LL> > D;
    for (int i = 0 ; i < s ; i++)
        D.push_back(Dijkstra(G, _S[i].F));
    LL maxW = 0, minW = INF;
    for (auto &vv : D)
        for (auto &v : vv)
            maxW = max(maxW, v),
            minW = min(minW, v);
    sol.realinit(2 + (1 << s) + s);
    LL L = minW - 1, R = maxW;
    while (R - L > 1) {
        sol.init();
        LL M = (R + L) >> 1;
        vector<LL> C(1 << s, 0);
        for (int i = 0 ; i < n ; i++) {
            int mask = 0;
            for (int j = 0 ; j < s ; j++) {
                if (D[j][i] <= M)
                    mask |= (1 << j);
            }
            C[mask] += cap[i];
        }
        for (int i = 0 ; i < (1 << s) ; i++)
            sol.addEdge(0, i + 1, C[i]);
        for (int i = 0 ; i < s ; i++)
            sol.addEdge(1 + (1 << s) + i, 1 + (1 << s) + s, _S[i].S);
        for (int i = 0 ; i < (1 << s) ; i++) {
            for (int j = 0 ; j < s ; j++) {
                if (i & (1 << j))
                    sol.addEdge(1 + i, 1 + (1 << s) + j, INF);
            }
        }
        LL flow = sol.maxFlow(0, 1 + (1 << s) + s);
        if (flow == sum)
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}
