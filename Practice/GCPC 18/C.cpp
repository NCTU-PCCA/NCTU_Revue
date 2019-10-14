#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
LL solve(int u, vector<vector<pii> > &G, vector<LL> &dp) {
    if (~dp[u]) return dp[u];
    dp[u] = 0;
    for (auto &e : G[u]) {
        dp[u] = max(dp[u], solve(e.F, G, dp) + e.S);
    }
    return dp[u];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pii> > G(n);
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
    }
    vector<LL> dp(n, -1);
    LL maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        maxV = max(maxV, solve(i, G, dp));
    }
    cout << maxV << '\n';
}
