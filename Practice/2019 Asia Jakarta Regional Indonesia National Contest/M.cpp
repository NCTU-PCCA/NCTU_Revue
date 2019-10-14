#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
LL fpow(LL a, int n) {
    if (n == 0) return 1;
    LL k = fpow(a, n >> 1);
    if (n % 2)
        return k * k % MOD * a % MOD;
    return k * k % MOD;
}
vector<LL> fact, invFact;
LL C(LL n, LL m) {
    return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    fact.clear(); fact.resize(MAXN, 1);
    invFact.clear(); invFact.resize(MAXN, 1);
    for (int i = 1 ; i < MAXN ; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
        invFact[i] = fpow(fact[i], MOD - 2);
    }
    int n, m; cin >> n >> m;
    LL ans = 0;
    for (int i = 0 ; 2 * i <= n ; i++) {
        int two = i;
        int one = n - 2 * i;
        if (two + one - 1 > m)
            continue;
        LL cur = fact[two + one] * invFact[two] % MOD * invFact[one] % MOD;
        LL com = C(m - (two + one - 1) + two + one, two + one);
        ans += (cur * com) % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
