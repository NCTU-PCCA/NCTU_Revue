#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL MOD = 1e9 + 7;
vector<vector<LL>> solve(int u, auto &G, auto &d) {
    if (u == -1) {
        return {
            {1, 0},
            {0, 1}
        };
    }
    auto l = solve(G[u][0], G, d);
    auto r = solve(G[u][1], G, d);
    vector<vector<LL>> dp(2, vector<LL>(2, 0));
    for (int li = 0 ; li < 2 ; li++) {
        for (int lj = 0 ; lj < 2 ; lj++) {
            for (int ri = 0 ; ri < 2 ; ri++) {
                for (int rj = 0 ; rj < 2 ; rj++) {
                    if (d[u] == -1) {
                        dp[!(li & ri)][!(lj & rj)] += l[li][lj] * r[ri][rj] % MOD;
                        dp[!(li & ri)][!(lj & rj)] %= MOD;
                    } else if (d[u] == 1) {
                        dp[!(li & ri)][1] += l[li][lj] * r[ri][rj] % MOD;
                        dp[!(li & ri)][1] %= MOD;
                    } else if (d[u] == 0) {
                        dp[!(li & ri)][0] += l[li][lj] * r[ri][rj] % MOD;
                        dp[!(li & ri)][0] %= MOD;
                    }
                }
            }
        }
    }
    return dp;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> d(n, 0);
    vector<vector<int>> G(n);
    for (int i = 0 ; i < n ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        cin >> d[i];
        G[i].push_back(u);
        G[i].push_back(v);
    }
    vector<vector<LL>> ans = solve(0, G, d);
    cout << (ans[0][1] + ans[1][0]) % MOD << '\n';
}
