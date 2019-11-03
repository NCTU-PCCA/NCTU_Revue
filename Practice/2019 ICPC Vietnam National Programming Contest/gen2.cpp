#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL x1, x2, y1, y2, z1, z2, sum = 0; while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
        sum += (x2 - x1 + 1) * (y2 - y1 + 1) * (z2 - z1 + 1);
    }
    cout << sum << '\n';
}
