#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, u, v; cin >> n >> u >> v;
    while (n--) {
        int x, y; cin >> x >> y;
        x -= u, y -= v;
        /*
        if (x == 0) {
            swap(x, y);
        } else if (x == y) {
            x *= 2; y = -y;
        } else if (y == 0) {
            y = -x;
        } else if (x == -2 * y) {
            swap(x, y);
            x = -x;
            y = -y;
        } else if (y == -x) {
            x = 0;
        } else if (2 * x == -y) {
            x = -x, y = -x;
        }
        */
        int a = x + y;
        int b = -x;
        a += u, b += v;
        cout << a << ' ' << b << '\n';
    }
}
