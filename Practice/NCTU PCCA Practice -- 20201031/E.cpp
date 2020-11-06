#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int M; cin >> M;
        long double x; cin >> x;
        long double a = 0, b = 1;
        for (int i = 1 ; i <= M ; i++) {
            int _a0 = x * i, _b = i;
            int _a1 = _a0 + 1;
            if (_a0 <= M && abs(x - (long double)_a0 / _b) < abs(x - (long double)a / b))
                a = _a0, b = _b;
            if (_a1 <= M && abs(x - (long double)_a1 / _b) < abs(x - (long double)a / b))
                a = _a1, b = _b;
        }
        cout << a << '/' << b << '\n';
    }
}
