#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
LL go(LL n) {
    if (n == 4) return 2;
    if (n % 2) return n - 1;
    if (n / 2 % 2) return n / 2;
    return n - 1;
}
LL solve(LL n) {
    LL ret = 0, op = 1;
    while (n) {
        LL nx = go(n);
        if (op)
            ret += n - nx;
        n = nx;
        op ^= 1;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    /*
    vector<int> dp(100, 0);
    for (int i = 1 ; i < 100 ; i++) {
        vector<int> res;
        if (i % 2) {
            res.push_back(i - 1 - dp[i - 1] + 1);
        } else {
            res.push_back(i - 1 - dp[i - 1] + 1);
            res.push_back(i / 2 - dp[i / 2] + i / 2);
        }
        sort(res.begin(), res.end());
        dp[i] = res.back();
    }
    */
    int t; cin >> t; while (t--) {
        LL n; cin >> n;
        cout << solve(n) << '\n';
    }
}
