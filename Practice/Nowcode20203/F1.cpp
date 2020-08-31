#include <bits/stdc++.h>
using namespace std;
// df = b*k
// gcd(d, f) | a * k
 
// df / lcm(d, f) | a * k
// bk / lcm(d, f) | a * k
 
// bk | a * k * lcm(d, f)
 
 
// b | a * lcm(d, f)
 
// lcm(d, f) = b / gcd(a, b)
 
 
const int MAXN = 2e6 + 5;
typedef long long LL;
LL extgcd(LL a, LL b, LL &x, LL &y) {
  if (!b) return x = 1, y = 0, a;
  LL res = extgcd(b, a % b, y, x);
  return y -= a / b * x, res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> f(MAXN, 1);
    for (int i = MAXN - 1 ; i >= 2 ; i--)
        for (int j = i ; j < MAXN ; j += i)
            f[j] = i;
    int t; cin >> t; while (t--) {
        LL A, B; cin >> A >> B;
        if (__gcd(A, B) != 1) {
            LL g = __gcd(A, B);
            cout << A/g+1 << ' ' << B/g << ' ' << 1 << ' ' << B/g << '\n';
            continue;
        }
        LL a = A, b = B;
        LL rest = b, rem = 1;
        if (f[b] == 1) {
            cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 << '\n';
            continue;
        }
        while (rest % f[b] == 0) {
            rem *= f[b], rest /= f[b];
        }
        if (rest == 1) {
            cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 << '\n';
            continue;
        }
        LL d = rest, f = rem;
        if (f < d) swap(f, d);
        LL c, e; extgcd(f, d, c, e); e = -e;
        e *= a / gcd(f, d);
        c *= a / gcd(f, d);
        // fc + d(-e) = a
        // for d  e += a / gcd(f, d) * f
        // for f  c += a / gcd(f, d) * d
        if (e <= 0) {
            LL cnt = -e / (a / __gcd(f, d) * f) + 1;
            e += a / __gcd(f, d) * f * cnt;
            c += a / __gcd(f, d) * d * cnt;
        }
        if (c <= 0) {
            LL cnt = -c / (a / __gcd(f, d) * d) + 1;
            e += a / __gcd(f, d) * f * cnt;
            c += a / __gcd(f, d) * d * cnt;
        }
        LL ed = a / __gcd(f, d) * f;
        LL cd = a / __gcd(f, d) * d;
        while (e - ed > 0 && c - cd > 0)
            e -= ed, c -= cd;
        if (d >= B || f >= B) {
            cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 << '\n';
            continue;
        }
        cout << c << ' ' << d << ' ' << e << ' ' << f << endl;
        assert(1 <= c && c <= 4e12);
        assert(1 <= e && e <= 4e12);
        assert(d < B && f < B);
    }
}

