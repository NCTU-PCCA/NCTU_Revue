#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL MOD = 998244353;
LL fpow(LL a, LL n) {
    if (n == 0) return 1;
    LL k = fpow(a, n >> 1);
    if (n % 2)
        return k * k % MOD * a % MOD;
    return k * k % MOD;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> arr(n);
    vector<pii> rk;
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        arr[i] = v;
        if (i != 0 && i != n - 1)
            rk.push_back({v, i});
    }
    if (n == 1) {
        cout << arr[0] % MOD << '\n';
        return 0;
    }
    sort(rk.rbegin(), rk.rend());
    set<LL> st; st.insert(0); st.insert(n - 1);
    LL ans = arr[0] + arr.back();
    ans %= MOD;
    for (auto &p : rk) {
        LL idx = p.S;
        //cout << "place " << idx << '\n';
        
        LL low = *prev(st.lower_bound(idx));
        LL upp = *st.upper_bound(idx);
        
        /*
        cout << "low " << low << '\n';
        cout << "upp " << upp << '\n';
        cout << "current value " << x << '\n';
        cout << "self " << arr[idx] << '\n';
        */

        LL other = arr[upp] * (idx - low) + arr[low] * (upp - idx);
        LL self = arr[idx] * (upp - low);
        if (other > self) {
            LL tmp = (arr[upp] * (idx - low) % MOD + arr[low] * (upp - idx) % MOD) % MOD * fpow(upp - low, MOD - 2) % MOD;
            ans += tmp;
            ans %= MOD;
        } else {
            ans += arr[idx];
            ans %= MOD;
            st.insert(idx);
        }
    }
    ans *= fpow(n, MOD - 2);
    ans %= MOD;
    cout << ans << '\n';
}
