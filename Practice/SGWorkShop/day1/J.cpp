// (m - (df)**2) / (n - d)
// -2dff*(n - d) + m - ddff
// -2nffd + 2ffdd + m - ffdd
// ffdd - 2nffd + m
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
long double func(LL d, LL n, LL m, long double f) {
    return (m - 1.0 * d * d * f * f) / (n - d);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, m; long double f; cin >> n >> m >> f;
    long double p1 = (n*f + sqrt(n*n*f*f - m) / f);
    long double p2 = (n*f - sqrt(n*n*f*f - m) / f);
    long double maxV = 0;
    maxV = max(maxV, func(0, n, m, f));
    maxV = max(maxV, func(n - 1, n, m, f));
    LL base = 10000000;
    for (LL i = max(0LL, (LL)p1 - base) ; i <= min((LL)n - 1, (LL)p1 + base) ; i++)
        maxV = max(maxV, func(i, n, m, f));
    for (LL i = max(0LL, (LL)p2 - base) ; i <= min((LL)n - 1, (LL)p2 + base) ; i++)
        maxV = max(maxV, func(i, n, m, f));
    cout << fixed << setprecision(10) << maxV << '\n';
}
