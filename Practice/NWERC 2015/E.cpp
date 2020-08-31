#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Dinic {
    LL flow;
    struct Node : vector<int> { int d, p; };
    struct Edge { int u, v; LL c; };
    vector<Node> N; vector<Edge> E;
    void init(int n) {
        E.clear(); N.clear(); N.resize(n); flow = 0;
    }
    void addEdge(int u, int v, LL c) { int m = E.size();
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
            E[e].c -= f; E[e ^ 1].c += f; flow += f; a -= f;
            if (!a) break;
        }
        return flow;
    }
} solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<LL, int> mp;
    vector<pair<LL, LL> > arr(n);
    for (auto &p : arr) {
        cin >> p.F >> p.S;
        mp[p.F + p.S];
        mp[p.F - p.S];
        mp[p.F * p.S];
    }
    int st = 0;
    vector<LL> toList;
    for (auto &p : mp) {
        p.S = st++;
        toList.push_back(p.F);
    }
    solver.init(2 + n + mp.size());
    for (int i = 0 ; i < n ; i++) {
        solver.addEdge(i + 1, n + 1 + mp[arr[i].F + arr[i].S], 1);
        solver.addEdge(i + 1, n + 1 + mp[arr[i].F - arr[i].S], 1);
        solver.addEdge(i + 1, n + 1 + mp[arr[i].F * arr[i].S], 1);
    }
    for (int i = 0 ; i < n ; i++)
        solver.addEdge(0, 1 + i, 1);
    for (int i = 0 ; i < mp.size() ; i++)
        solver.addEdge(n + 1 + i, 1 + n + mp.size(), 1);
    solver.run(0, 1 + n + mp.size());
    if (solver.flow == n) {
        for (int i = 0 ; i < 3 * n ; i++) {
            if (solver.E[i * 2].c)
                continue;
            int u = solver.E[i * 2].u - 1;
            int v = solver.E[i * 2].v - n - 1;
            cout << arr[u].F << ' ' << "+-*"[i % 3] << ' ' << arr[u].S << " = " << toList[v] << '\n';
        }
        
    } else 
        cout << "impossible\n";
}
