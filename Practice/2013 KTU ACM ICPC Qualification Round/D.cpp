#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct E {
    int u, v, d, nr;
    bool operator < (const E &rhs) const {
        return nr < rhs.nr;
    }
};
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
typedef struct Edge {
    int v; LL w;
    bool operator > (const Edge &b) const {
        return w > b.w;
    }
} State;
void Dijkstra(int n, vector<vector<Edge> > &G, vector<LL> &d, int s) {
    priority_queue<State, vector<State>, greater<State> > pq;
    d.clear(); d.resize(n, INF);
    d[s] = 0; pq.push({s, d[s]});
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int u = p.v;
        if (d[u] < p.w)
            continue;
        for (auto &e : G[u]) {
            if (d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n, m, k; cin >> n >> k >> m;
        vector<E> edges(m);
        for (auto &e : edges) {
            cin >> e.u >> e.v >> e.d >> e.nr;
            e.u--, e.v--;
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        vector<int> pa(n, -1);
        vector<int> legal(n, false);
        for (int i = 0 ; i < k ; i++)
            legal[i] = true;
        LL minP = INF;
        for (auto &e : edges) {
            minP = e.nr;
            int x = find(e.u, pa);
            int y = find(e.v, pa);
            if (x == y)
                continue;
            pa[x] += pa[y];
            pa[y] = x;
            if (legal[x] || legal[y])
                legal[x] = legal[y] = true;
            int tar = find(n - 1, pa);
            if (legal[tar])
                break;
        }
        vector<vector<Edge> > G(n);
        for (auto &e : edges) {
            if (e.nr >= minP) 
                G[e.u].push_back({e.v, e.d}),
                G[e.v].push_back({e.u, e.d});
        }
        vector<LL> d;
        Dijkstra(n, G, d, n - 1);
        LL minV = INF;
        for (int i = 0 ; i < k ; i++)
            minV = min(minV, d[i]);
        vector<int> ans;
        for (int i = 0 ; i < k ; i++) {
            if (minV == d[i])
                ans.push_back(i + 1);
        }
        for (int i = 0 ; i < (int)ans.size() ; i++)
            cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    }

}
