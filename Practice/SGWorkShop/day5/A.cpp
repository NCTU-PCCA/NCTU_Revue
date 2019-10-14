#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<LL> > data(n, vector<LL>(2 * k + 1));
    for (auto &vv : data)
        for (auto &v : vv)
            cin >> v;
    random_shuffle(data.begin(), data.end());
    int sq = sqrt(n) + 5, m = sq * 2 * k + 1;
    vector<vector<LL> > dp(2, vector<LL>(m, INF));
    dp[0][m / 2] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            dp[i % 2][j] = INF;
            for (int x = 0 ; x < 2 * k + 1 ; x++)
                if (j - x + k >= 0 && j - x + k < m)
                    dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j - x + k] + data[i - 1][x]);
        }
    }
    cout << dp[n % 2][m / 2] << '\n';
}
