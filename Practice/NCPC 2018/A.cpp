#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        vector<int> dp(n + 1, 0);
        for (int i = 1 ; i <= n ; i++) {
            int maxV = 0;
            for (int j = 0 ; j < i - 2 ; j++)
                maxV = max(maxV, dp[j]);
            dp[i] = maxV + data[i - 1];
        }
        int ans = 0;
        for (int i = 0 ; i <= n ; i++)
            ans = max(ans, dp[i]);
        cout << ans << '\n';
    }
}
