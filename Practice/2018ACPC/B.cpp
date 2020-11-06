#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
void solve() {
    LL x, n; cin >> x >> n;
    if (n == 1) {
        cout << x << '\n';
        return ;
    }
    if (x <= n) {
        for (int i = 0 ; i < x ; i++) 
            cout << 1 << ' ';
        for (int i = x ; i < n ; i++)
            cout << 0 << ' ';
        cout << '\n';
    } else {
        x -= n;
        LL k = x / (n - 1);
        LL r = x % (n - 1);
        vector<LL> ans(n);
        ans[0] = k - k / 2;
        ans[n - 1] = k / 2;
        for (int i = 1 ; i < n - 1 ; i++)
            ans[i] = k;
        if (k % 2 == 0) {
            for (int i = 0 ; i < r ; i++) {
                ans[n - 2 - i]++;
            }
        } else {
            for (int i = 0 ; i < r ; i++) {
                ans[i + 1]++;
            }
        }
        for (int i = 0 ; i < n ; i++) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
