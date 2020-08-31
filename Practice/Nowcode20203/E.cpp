#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<LL> arr(n);
        for (auto &v : arr)
            cin >> v;
        sort(arr.begin(), arr.end());
        LL ans = 0;
        for (int i = 0 ; i + 1 < n ; i += 2)
            ans += arr[i + 1] - arr[i];
        if (n == 4) {
            cout << ans - arr[0] - arr[1] + arr[2] + arr[3] << '\n';
        } else if (n == 6) {
            cout << ans -arr[0] - arr[1] + arr[2] - arr[3] + arr[4] + arr[5] << '\n';
        } else {
            vector<LL> dp(n + 1, INF); dp[0] = 0;
            dp[4] = -arr[0] - arr[1] + arr[2] + arr[3];
            dp[6] = -arr[0] - arr[1] + arr[2] - arr[3] + arr[4] + arr[5];
            for (int i = 8 ; i <= n ; i += 2) {
                dp[i] = min(dp[i], dp[i - 6] - arr[i - 6] - arr[i - 5] + arr[i - 4] - arr[i - 3] + arr[i - 2] + arr[i - 1]);
                dp[i] = min(dp[i], dp[i - 4] - arr[i - 4] - arr[i - 3] + arr[i - 2] + arr[i - 1]);
            }
            cout << dp.back() + ans << '\n';
        }
    }
}

// df = b*k
// gcd(d, f) | a * k

// df / lcm(d, f) | a * k
// bk / lcm(d, f) | a * k

// b / lcm(d, f) | a

// b / (df / gcd(d, f)) | a

// gcd(d, f) * b / df | a

