#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL extgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) return x = 1, y = 0, a;
    LL res = extgcd(b, a % b, y, x);
    return y -= a / b * x, res;
}
void solve() {
    LL R, S, Q; cin >> R >> S >> Q;
    LL x, y;
    extgcd(R, S, x, y);
    LL g = __gcd(R, abs(S));
    LL k = Q / g;
    x *= Q / g, y *= Q / g;
    if (x * R + y * S == -Q)
        x *= -1, y *= -1;
    LL dx = abs(S) / g, dy = abs(R) / g;
    if (x <= 0) {
        LL ck = (-x) / dx + 1;
        x += ck * dx;
        y += ck * dy;
    } else {
        LL ck = (x - 1) / dx;
        x -= ck * dx;
        y -= ck * dy;
    }
    if (y <= 0) {
        LL ck = (-y) / dy + 1;
        x += ck * dx;
        y += ck * dy;
    }
    assert(x >= 1 && y >= 1);
    cout << x << ' ' << y << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
