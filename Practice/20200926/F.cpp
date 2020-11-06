#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int DP(int S, auto &legal, auto &dp) {
    if (~dp[S]) return dp[S];
    if (!S) return dp[S] = 0;
    int minV = INF;
    for (int i = S ; ; i = ((i - 1) & S)) {
        if (!i) break;
        if (legal[i]) {
            minV = min(minV, DP(S ^ i, legal, dp) + 1);
        }
    }
    return dp[S] = minV;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> G(n, vector<bool>(n, 0));
    while (m--) {
        int u, v; cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    vector<int> legal(1 << n, 0);
    for (int S = 0 ; S < (1 << n) ; S++) {
        vector<int> idx;
        for (int i = 0 ; i < n ; i++) {
            if (((S >> i) & 1) == 0)
                continue;
            idx.push_back(i);
        }
        bool ok = true;
        for (int i = 0 ; i < (int)idx.size() ; i++) {
            for (int j = i + 1 ; j < (int)idx.size() ; j++) {
                if (G[idx[i]][idx[j]])
                    ok = false;
            }
        }
        if (ok)
            legal[S] = 1;
    }
    vector<int> dp(1 << n, -1);
    int x = DP(((1 << n) - 1), legal, dp);
    if (x > 4)
        cout << "many\n";
    else
        cout << x << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
