#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Dinic { LL flow;
    struct Node : vector<int> { int d, p; };
    struct Edge { int u, v; LL c; };
    vector<Node> N; vector<Edge> E;
    void init(int n) {
        E.clear(); N.clear(); N.resize(n); flow = 0;
    }
    void addEdge(int u, int v, LL c) { int m = E.size();
        // cout << u << ' ' << v << ' ' << c << endl;
        E.push_back({u, v, c}); N[u].push_back(m++);
        E.push_back({v, u, 0}); N[v].push_back(m++);
    }
    void run(int s, int t) {
        flow = 0; while (bfs(s, t)) flow += dfs(s, t, INF);
    }
    bool bfs(int s, int t) {
        for (auto &v : N) v.d = -1, v.p = 0;
        queue<int> q; q.push(s); N[s].d = 0;
        while (q.size()) { int u = q.front(); q.pop();
            for (auto &e : N[u]) { int v = E[e].v;
                if (!~N[v].d && E[e].c)
                    q.push(v), N[v].d = N[u].d + 1;
            }
        }
        return ~N[t].d;
    }
    LL dfs(int u, int t, LL a) {
        if (u == t || !a) return a; LL flow = 0;
        for (int &p = N[u].p ; p < N[u].size() ; p++) {
            auto e = N[u][p], v = E[e].v;
            if (N[u].d + 1 != N[v].d) continue;
            LL f = dfs(v, t, min(a, E[e].c));
            E[e].c -= f; E[e ^ 1].c += f;
            flow += f; a -= f;
            if (!a) break;
        }
        return flow;
    }
} solver;
#define sq(x) (x) * (x)
LL dist(pii a, pii b) {
    return sq(a.F - b.F) + sq(a.S - b.S);
}
void testcase() {
    int n, m; cin >> n >> m;
    vector<LL> c(n);
    vector<pair<pii, int>> arr(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i].F.F >> arr[i].F.S >> c[i] >> arr[i].S;
    }
    vector<LL> sum = c;
    vector<int> have(m, 0);
    solver.init(n + m + 2);
    vector<pair<pii, LL>> los(m);
    for (int j = 0 ; j < m ; j++)
        cin >> los[j].F.F >> los[j].F.S >> los[j].S;

    vector<int> out(m, 0);
    for (int j = 0 ; j < m ; j++) {
        if (dist(arr[0].F, los[j].F) <= arr[0].S * arr[0].S) {
            out[j] = 1;
            sum[0] += los[j].S;
        }
    }

    for (int i = 1 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (out[j]) continue;
            if (dist(arr[i].F, los[j].F) <= arr[i].S * arr[i].S) {
                sum[i] += los[j].S;
                have[j] = 1;
                solver.addEdge(i + 1, j + n + 1, INF);
            }
        }
    }
    for (int i = 1 ; i < n ; i++) {
        if (c[i] > sum[0]) {
            cout << "Lonesome Willy\n";
            return ;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        solver.addEdge(0, i + 1, sum[0] - c[i]);
    }
    LL tot = 0;
    for (int i = 0 ; i < m ; i++) {
        solver.addEdge(i + n + 1, n + m + 1, los[i].S);
        if (have[i])
            tot += los[i].S;
    }
    solver.run(0, 1 + n + m);
    if (tot == solver.flow) {
        cout << "Suiting Success\n";
    } else {
        cout << "Lonesome Willy\n";
    }


}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        testcase();
    }
}
