#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int digit(int x) {
    if (x < 10) return 1;
    if (x < 100) return 2;
    return 3;
}
int n, m, p;
LL dp[55][55][205];
LL solve(int u, int x, int p) {
    if (x < 0) return 0;
    if (~dp[u][x][p]) return dp[u][x][p];
    dp[u][x][p] = 0;
    for (int i = 0 ; i < m ; i++) {
        if (digit(i) > u)
            break;
        if (digit(i) == u) {
            (dp[u][x][p] += solve(u - digit(i), x - 1, (p - i + m) % m)) %= MOD;
        } else {
            if (digit(i) + 1 != u) {
                (dp[u][x][p] += solve(u - digit(i) - 1, x - 1, (p - i + m) % m)) %= MOD;
                (dp[u][x][p] += solve(u - digit(i) - 1, x - 1, (p + i + m) % m)) %= MOD;
            }
        }
    }
    return dp[u][x][p];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p; cin >> n >> m >> p;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1 ; i < m ; i++)
        dp[0][0][i] = 0;
    /*
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cout << "len: " << i << ' ' << "num: " << j << ' ' << solve(i, j, p) << '\n';
        }
    }
    */
    LL g[55][55][55][2] = {};
    g[1][0][0][0] = 1;
    for (int i = 1 ; i <= 50 ; i++) {
        for (int j = 0 ; j < 55 ; j++) {
            for (int k = 0 ; k < 55 ; k++) {
                for (int l = 0 ; l < 2 ; l++) {
                    if (l == 0) {
                        if (j < 53) {
                            g[i][j+1][k][0] += g[i][j][k][l];
                            g[i][j+1][k][0] %= MOD;
                        }
                        g[i][j][k][1] += g[i][j][k][l];
                        g[i][j][k][1] %= MOD;
                    }
                    else {
                        if (k < j) {
                            g[i][j][k+1][l] += g[i][j][k][l];
                            g[i][j][k+1][l] %= MOD;
                        }
                        g[i+1][j][k][0] += g[i][j][k][l];
                        g[i+1][j][k][0] %= MOD;
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= n ; j++) {
            if (n - j * 2 >= 0) {
                (ans += g[i][j][j][1] * solve(n - j * 2, i, p) % MOD) %= MOD;
            }
        }
    }
    cout << ans << '\n';
}
