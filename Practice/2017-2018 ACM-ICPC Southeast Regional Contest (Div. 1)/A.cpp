#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string s;
int len, K;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> len >> K >> s;
    int n = s.size();
    if (K * (len + 1) - 1 > s.size()) {
        cout << -1 << '\n';
        exit(0);
    }
    s = " " + s;
    int minV = INF;
    int dp[n + 5][K + 5][len + 5][2];
    memset(dp, INF, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < K ; j++) {
            for (int k = 0 ; k <= len ; k++) {
                // dp[i][j][k][0]
                if (s[i + 1] == 'G') {
                    int newlen = min(len, k + 1);
                    if (k == len - 1)
                        dp[i + 1][j + 1][newlen][0] = min({dp[i + 1][j + 1][newlen][0], dp[i][j][newlen][0], dp[i][j][newlen][1]});
                    else
                        dp[i + 1][j][newlen][0] = min({dp[i + 1][j][newlen][0], dp[i][j][newlen][0], dp[i][j][newlen][1]});
                } else {
                    dp[i + 1][j][0][0] = min({dp[i + 1][j][0][0], dp[i][j][k][0], dp[i][j][k][1]});
                }
                // dp[i][j][k][1]
                if (s[i + 1] == 'D') {
                    int newlen = min(len, k + 1);
                    if (k == len - 1)
                        dp[i + 1][j + 1][newlen][1] = min({dp[i + 1][j + 1][newlen][1], dp[i][j][newlen][0] + 1, dp[i][j][newlen][1]});
                    else
                        dp[i + 1][j][newlen][1] = min({dp[i + 1][j][newlen][1], dp[i][j][newlen][0] + 1, dp[i][j][newlen][1]});
                } else {
                    dp[i + 1][j][0][1] = min({dp[i + 1][j][0][1], dp[i][j][k][0], dp[i][j][k][1]});
                }
            }
        }
    }
    for (int i = 0 ; i <= n ; i++)
        for (int k = 0 ; k <= len ; k++)
            minV = min({minV, dp[i][K][k][0], dp[i][K][k][1]});
    cout << minV << '\n';
}

// dp[i][j][k][l]: [0, i]湊好j個最後一段長度為K, 最後一段的長度是k, 第i個有沒有轉

// http://codepad.org/Inrmv63y
