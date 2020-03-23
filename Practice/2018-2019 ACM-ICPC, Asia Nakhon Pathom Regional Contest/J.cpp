#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l, r; while (cin >> l >> r) {
        if (l == 0 && r == 0)
            exit(0);
        long double x = 0;
        for (int i = l ; i <= r ; i++)
            x += 1.0 / 3 * pow(i, -2.0 / 3);
        int base = 15;
        while (x >= 10)
            base--, x /= 10;
        while (x < 1)
            x *= 10, base++;
        cout << fixed << setprecision(5) << x << "E-0" << base << '\n';
    }
}
