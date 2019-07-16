#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n, m; cin >> n >> m;
        vector<vector<int> > data(n, vector<int>(m)), dp(n, vector<int>(m, -INF));
        for (auto &vv : data)
            for (auto &v : vv)
                cin >> v;
        dp[0][0] = data[0][0];
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (i != 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + data[i][j]);
                if (j != 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + data[i][j]);
            }
        }
        cout << dp[n - 1][m - 1] << '\n';
    }

}
