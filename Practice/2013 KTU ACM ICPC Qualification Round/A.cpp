#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n; cin >> n;
        for (int i = 0 ; i < n - 1 ; i++) {
            int u, v; cin >> u >> v;
        }
        if (n == 1) {
            cout << 1 << '\n';
        } else 
            cout << 2 << '\n';
    }
}
