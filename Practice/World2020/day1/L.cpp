#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct Edge { int v; LL w;
    bool operator > (const Edge &b) const {
        return w > b.w;
    }
} S;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
vector<LL> solve(vector<vector<Edge>> &G, int s) {
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
    freopen("linear.in","r",stdin);
    freopen("linear.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<Edge>> G(n);
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w; u--, v--;
        G[u].push_back({v, w});
    }
    auto d = solve(G, 0);
    if (d[n - 1] == INF) {
        cout << "Infinity\n";
    } else 
        cout << d[n - 1] << '\n';
}
