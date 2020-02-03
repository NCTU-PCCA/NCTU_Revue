#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL r, a, b; while (cin >> r && r) {
        cin >> a >> b;
        if (a == b) {
            cout << "false\n";
            continue;
        }
        LL q = r * a;
        LL p = 2 * abs(a - b);
        while (q < 0) q += p * r;
        LL g = __gcd(q, p);
        p /= g, q /= g;
        q %= r * p;
        if (p == 1)
            cout << q << '\n';
        else
            cout << q << '/' << p << '\n';
    }
}
