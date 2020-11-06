#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL fpow(LL a, LL n) {
    if (n == 0) return 1;
    LL k = fpow(a, n >> 1);
    if (n % 2)
        return k * k % MOD * a % MOD;
    return k * k % MOD;
}
const int MAXN = 1e7 + 5;
vector<int> isP, mu, ps;
void mobius() { isP.clear(); isP.resize(MAXN, 1);
  mu.resize(MAXN); isP[0] = isP[1] = 0; mu[1] = 1;
  for (int i = 2 ; i < MAXN ; i++) {
    if (isP[i]) ps.push_back(i), mu[i] = -1;
    for (auto p : ps) { if (i * p >= MAXN) break;
      isP[i * p] = mu[i * p] = false;
      if (i % p == 0) break; mu[i * p] = -mu[i];
    }
  }
}
LL cal(LL k, LL m) {
    LL b = m / k, ret = 0;
    for (int d = 1 ; d * d <= b ; d++) {
        if (b % d) continue;
        ret += mu[d] * (b / d);
        if (d != b / d)
            ret += mu[b / d] * (b / (b / d));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    mobius();
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        LL n, m; cin >> n >> m;
        unordered_map<LL, LL> mp;
        vector<LL> ans(n + 5, -1);
        LL sum = 0;
        for (LL i = 0 ; i < n ; i++) {
            int gi = __gcd(i, n);
            if (ans[gi] == -1) {
                LL cur = 0;
                for (LL gj1 = 1 ; gj1 * gj1 <= m ; gj1++) {
                    if (m % gj1) continue;
                    LL gj2 = m / gj1;
                    cur += fpow(2, gj1 * gi * __gcd(n / gi, m / gj1)) * cal(gj1, m) % MOD;
                    cur %= MOD;
                    if (gj1 != gj2) {
                        cur += fpow(2, gj2 * gi * __gcd(n / gi, m / gj2)) * cal(gj2, m) % MOD;
                        cur %= MOD;
                    }
                }
                ans[gi] = cur;
            }
            sum += ans[gi]; sum %= MOD;
        }
        sum *= fpow(n, MOD - 2);
        sum %= MOD;
        sum *= fpow(m, MOD - 2);
        sum %= MOD;
        cout << sum << '\n';
    }
}
