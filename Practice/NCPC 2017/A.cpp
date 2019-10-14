#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n) {
    ll ret = 0;
    for (ll i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ret += i;
        }
    }
    if (n != 1)
        ret += n;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        ll n; cin >> n;
        while (solve(n) != n)
            n = solve(n);
        cout << n << '\n';
    }
}
