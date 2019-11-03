#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    srand(time(NULL));
    int t = 50; while (t--) {
        LL a = 1e6, b = 1e6, c = 1e6; int n = 1e3;
        cout << a << ' ' << b << ' ' << c << ' ' << n << '\n';
        for (int i = 0 ; i < n ; i++) {
            cout << a << ' ' << b << ' ' << c << '\n';
        }
        for (int i = 0 ; i < n ; i++) {
            cout << a << ' ' << b << ' ' << c << ' ' << a << ' ' << b << ' ' << c << '\n';
        }
    }
    cout << -1 << '\n';
}
