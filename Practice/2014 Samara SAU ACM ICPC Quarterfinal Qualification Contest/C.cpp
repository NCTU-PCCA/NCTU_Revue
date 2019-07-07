#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    LL k; cin >> k;
    for (LL b = k + 1; ; b++) {
        LL v = b - k;
        if (b * k % v == 0)
            cout << b * k / v << ' ' << b << '\n';
    }
}
