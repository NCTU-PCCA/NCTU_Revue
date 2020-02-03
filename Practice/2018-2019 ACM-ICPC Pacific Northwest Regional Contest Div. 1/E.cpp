#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 5;
const int MAXM = MAXN * 16;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Graph {
    struct Edge; int V;
    struct Node : vector<Edge*> {
        iterator cur; int d; Node() { clear(); }
    }_memN[MAXN], *node[MAXN], *s, *t;
    struct Edge {
        Node *u, *v; Edge *rev; LL c, f;
        Edge(Node *u, Node *v, LL c, Edge *rev)
            : u(u), v(v), c(c), f(0), rev(rev) {}
        Edge() {}
    }_memE[MAXM], *ptrE;
    Graph(int _V) : V(_V) {
        ptrE = _memE;
        for (int i = 0 ; i < V ; i++)
            node[i] = _memN + i;
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
        for (int i = 0 ; i < V ; i++)
            node[i]->d = -1;
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
        for (; u->cur != u->end() ; u->cur++) {
            auto &e = *u->cur; Node *v = e->v;
            if (u->d + 1 == v->d && (f = dfs(v, min(a, e->c - e->f))) > 0) {
                e->f += f; e->rev->f -= f; flow += f; a -= f;
                if (!a) break;
            }
        }
        return flow;
    }
};
int encode(int i, int j, int m) {
    return i * m + j;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, c; cin >> n >> m >> c;
    vector<vector<char> > data(n, vector<char>(m));
    pair<int, int> s;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> data[i][j];
            if (data[i][j] == 'B')
                s = {i, j};
        }
    }
    vector<LL> C(c);
    for (auto &v : C)
        cin >> v;
    Graph *sol = new Graph(2 * n * m + 2);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i - 1 >= 0) {
                sol->addEdge(encode(i, j, m) * 2 + 1, encode(i - 1, j, m) * 2, INF);
            } else {
                sol->addEdge(encode(i, j, m) * 2 + 1, 2 * n * m + 1, INF);
            }
            if (i + 1 <  n) {
                sol->addEdge(encode(i, j, m) * 2 + 1, encode(i + 1, j, m) * 2, INF);
            } else {
                sol->addEdge(encode(i, j, m) * 2 + 1, 2 * n * m + 1, INF);
            }
            if (j - 1 >= 0) {
                sol->addEdge(encode(i, j, m) * 2 + 1, encode(i, j - 1, m) * 2, INF);
            } else {
                sol->addEdge(encode(i, j, m) * 2 + 1, 2 * n * m + 1, INF);
            }
            if (j + 1 <  m) {
                sol->addEdge(encode(i, j, m) * 2 + 1, encode(i, j + 1, m) * 2, INF);
            } else {
                sol->addEdge(encode(i, j, m) * 2 + 1, 2 * n * m + 1, INF);
            }
            if (data[i][j] == '.' || data[i][j] == 'B')
                sol->addEdge(encode(i, j, m) * 2, encode(i, j, m) * 2 + 1, INF);
            else
                sol->addEdge(encode(i, j, m) * 2, encode(i, j, m) * 2 + 1, C[data[i][j] - 'a']);
        }
    }
    sol->addEdge(2 * n * m, encode(s.first, s.second, m) * 2, INF);
    LL f = sol->maxFlow(2 * n * m, 2 * n * m + 1);
    if (f == INF)
        cout << -1 << '\n';
    else
        cout << f << '\n';
    delete sol;
}
