#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int>pii;
typedef long long LL;
vector<int> bfs(auto &G, int s) {
    queue<int> q; q.push(s);
    int n = G.size();
    vector<int> d(n, -1); d[s] = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (d[v] != -1)
                continue;
            d[v] = d[p] + 1;
            q.push(v);
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<vector<int>> G(n);
        for (int i = 1 ; i < n ; i++) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> d = bfs(G, 0);
        int idx = 0;
        for (int i = 0 ; i < n ; i++) {
            if (d[idx] < d[i])
                idx = i;
        }
        vector<int> d2 = bfs(G, idx);
        int x = *max_element(d2.begin(), d2.end());
        cout << (x - 1) / 2 + 1 << '\n';
    }
}
