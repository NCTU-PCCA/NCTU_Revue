#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, LL> pii;
void one(LL n) {
    // 1 + 2 + ... + x = n
    // (1 + x) * x / 2 = n
    LL L = 0, R = 1e9;
    while (R - L > 1) {
        LL M = (R + L) >> 1;
        if ((1 + M) * M / 2 <= n)
            L = M;
        else
            R = M;
    }
    if ((1 + L) * L / 2 == n) {
        cout << 2 << ' ' << L << '\n';
        exit(0);
    }
}
void two(LL n) {
    LL L = 0, R = 1e6;
    while (R - L > 1) {
        LL M = (R + L) >> 1;
        if (M * (M + 1) * (2 * M + 1) / 6 <= n)
            L = M;
        else
            R = M;
    }
    if (L * (L + 1) * (2 * L + 1) / 6 == n) {
        cout << 3 << ' ' << L << '\n';
        exit(0);
    }
}
double dfpow(LL a, LL n) {
    if (n == 0) return 1;
    double k = dfpow(a, n >> 1);
    if (n % 2) return k * k * a;
    else return k * k;
}
LL fpow(LL a, LL n) {
    if (n == 0) return 1;
    LL k = fpow(a, n >> 1);
    if (n % 2) return k * k * a;
    else return k * k;
}
void gen(LL n, int x) {
    LL sum = 0;
    for (int i = 1 ;; i++) {
        sum += fpow(i, x);
        if (x * log10(i) > 16)
            return ;
        if (sum == n) {
            cout << x + 1 << ' ' << i << '\n';
            exit(0);
        }
        if (sum > n)
            return ;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n; cin >> n;
    // one(n);
    two(n);
    for (int i = 3 ; i < 60 ; i++) {
        gen(n, i);
    }
    cout << "impossible\n";
}
