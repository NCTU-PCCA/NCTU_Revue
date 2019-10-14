#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
typedef vector<LL> VLL;
LL solve(VLL &w, VLL &m, LL W) {
    int n = w.size(); LL ans = 0;
    vector<LL> dp(W + 1, 0); dp[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = W ; j >= 0 ; j--) {
            for (int k = 1 ; k <= m[i] ; k++) {
                if (j - k * w[i] < 0) break;
                dp[j] |= dp[j - k * w[i]];
            }
        }
    }
    for(int i = W; i >= 1; --i) ans += dp[i];
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; while (cin >> n >> k && n) {
        vector<LL> w(n), m(n);
        for (auto &v : w) cin >> v;
        for (auto &v : m) cin >> v;
        cout << solve(w, m, k) << '\n';
    }
}
