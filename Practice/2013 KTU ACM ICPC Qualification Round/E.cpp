#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MOD = 1013;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int x; cin >> x;
        string s; cin >> s;
        int n = (int)s.size();
        vector<vector<LL> > dp(n + 1, vector<LL>(MOD, 0));
        vector<vector<pii> > pre(n + 1, vector<pii>(MOD));
        vector<int> p(s.size(), 0); p[0] = 1;
        for (int i = 1 ; i < (int)s.size() ; i++)
            p[i] = (p[i - 1] * 31) % MOD;
        reverse(p.begin(), p.end());
        dp[0][0] = 1;
        for (int i = 1 ; i <= (int)s.size() ; i++) {
            if (s[i - 1] == '?') {
                for (int j = 0 ; j < MOD ; j++) {
                    for (int k = 0 ; k < 26 ; k++) {
                        int delta = p[i - 1] * ('a' + k) % MOD;
                        if (dp[i - 1][j] != 0)
                            pre[i][(j + delta) % MOD] = {j, k};
                        dp[i][(j + delta) % MOD] += dp[i - 1][j];
                    }
                }
            } else {
                int delta = (p[i - 1] * s[i - 1]) % MOD;
                for (int j = 0 ; j < MOD ; j++) {
                    dp[i][(j + delta) % MOD] += dp[i - 1][j];
                    if (dp[i - 1][j] != 0)
                        pre[i][(j + delta) % MOD] = {j, s[i - 1] - 'a'};
                }
            }
        }
        if (dp[s.size()][x] == 1) {
            string ans = "";
            int pos = x;
            for (int i = n ; i >= 1 ; i--) {
                ans += pre[i][pos].second + 'a';
                pos = pre[i][pos].first;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        } else cout << dp[s.size()][x] << '\n';
    }

}
