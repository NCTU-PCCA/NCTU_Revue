#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL fpow(LL a, LL n) {
    if (n == 0) return 1;
    LL k = fpow(a, n / 2);
    if (n % 2 == 0)
        return k * k % MOD;
    else
        return k * k % MOD * a % MOD;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        LL n; cin >> n;
        if (n < 7) {
            cout << 0 << '\n';
            continue;
        }
        LL x = (n - 7) / 7;
        LL ans = (1 + x) * x % MOD * fpow(2, MOD - 2) % MOD * 21 % MOD;
        LL rem = 6 - n % 7;
        n /= 7;
        LL cur = 0;
        for (int i = 6 ; i >= rem ; i--)
            cur += i;
        ans = ans + cur * n % MOD;
        ans %= MOD;
        cout << ans << '\n';
    }
}
