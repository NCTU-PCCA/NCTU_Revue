#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
void solve() {
    LL n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    cout << min(n * (m + 1) / 2, (n + 1) * m / 2) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }

}
