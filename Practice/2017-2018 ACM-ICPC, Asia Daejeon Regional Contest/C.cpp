#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> _G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        _G[u].push_back(v);
        _G[v].push_back(u);
    }
    vector<vector<int>> G(n);
    vector<int> deg(n, 0);
    for (int u = 0 ; u < n ; u++) {
        for (auto &v : _G[u]) {
            if (_G[u].size() == _G[v].size())
                continue;
            if (_G[u].size() > _G[v].size())
                G[v].push_back(u), deg[u]++;
            else
                G[u].push_back(v), deg[v]++;
        }
    }
    queue<int> q;
    vector<int> dp(n, -1);
    for (int i = 0 ; i < n ; i++) {
        if (deg[i] == 0)
            q.push(i), dp[i] = 0;
    }
    int ans = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            deg[v]--;
            dp[v] = max(dp[v], dp[p] + 1);
            ans = max(ans, dp[v]);
            if (deg[v] == 0)
                q.push(v);
        }
    }
    cout << ans + 1 << '\n';
}
