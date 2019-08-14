#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
typedef long long LL;
const LL MOD = 1e9 + 7;
int n, a, b;
LL dp[2][MAXN];
int solve(int x, int type) {
    if (~dp[type][x]) return dp[type][x];
    dp[type][x] = 0;
    if (type == 0) {
        for (int i = 0 ; i < a ; i++) {
            if (x - i - 1 < 0) break;
            dp[type][x] += solve(x - i - 1, type ^ 1);
            dp[type][x] %= MOD;
        }
    } else {
        for (int i = 0 ; i < b ; i++) {
            if (x - i - 1 < 0) break;
            dp[type][x] += solve(x - i - 1, type ^ 1);
            dp[type][x] %= MOD;
        }
    }
    return dp[type][x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> a >> b;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[1][0] = 1;
    cout << (solve(n, 0) + solve(n, 1)) % MOD<< '\n';
}
