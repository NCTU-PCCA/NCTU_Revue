#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
bool check(LL x) {
    if (x == 1) return false;
    for (int i = 2 ; i * i <= x ; i++)
        if (x % i == 0)
            return false;
    return true;
}
const double eps = 1e-7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        double x, y; cin >> x >> y;
        LL X = (x + eps) * 100000;
        LL Y = (y + eps) * 100000;
        LL g = __gcd(X, Y);
        X /= g, Y /= g;
        if (X == Y) {
            cout << 2 << ' ' << 2 << '\n';
        } else if (check(X) && check(Y))
            cout << X << ' ' << Y << '\n';
        else
            cout << "impossible\n";
    }
}
