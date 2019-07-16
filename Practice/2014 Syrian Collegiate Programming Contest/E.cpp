#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
int dp[MAXN], n, k;
int solve(int n) {
    if (~dp[n]) return dp[n];
    vector<int> tar;
    for (int i = 0 ; i + k <= n ; i++) {
        tar.push_back(solve(i) ^ solve(n - i - k));
    }
    for (int i = 0 ; ; i++) {
        bool ok = true;
        for (auto &v : tar)
            if (i == v)
                ok = false;
        if (ok)
            return dp[n] = i;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        if (solve(n) == 0)
            cout << "Losing\n";
        else
            cout << "Winning\n";
    }
}
