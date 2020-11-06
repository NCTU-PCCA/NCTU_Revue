#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
void solve() {
    LL n; cin >> n;
    cout << __builtin_popcount(n ^ (n - 1)) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
