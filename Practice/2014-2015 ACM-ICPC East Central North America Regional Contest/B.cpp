#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;
int dp[MAXN][MAXN];
string s;
int solve(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j) return dp[i][j] = 0;
    int len = j - i;
    int minV = len;
    for (int k = 1 ; k <= len / 2 ; k++) {
        if (len % k) continue;
        string str = s.substr(i, k);
        bool flag = false;
        for (int l = i + k ; l + k <= j ; l += k) {
            string tar = s.substr(l, k);
            if (tar != str) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            int tar = len / k, cnt = 0;
            while (tar) {
                cnt++;
                tar /= 10;
            }
            minV = min(minV, solve(i, i + k) + cnt + (k != 1 ? 2 : 0));
        }
    }
    for (int k = i + 1 ; k < j ; k++) {
        minV = min(minV, solve(i, k) + solve(k, j));
    }
    return dp[i][j] = minV;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0; while (cin >> s) {
        if (s[0] == '0')
            break;
        cout << "Case " << ++kase << ": ";
        memset(dp, -1, sizeof(dp));
        cout << solve(0, s.size()) << '\n';
    }
}
