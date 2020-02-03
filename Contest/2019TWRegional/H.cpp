#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        LL n; cin >> n;
        LL ans = 0;
        for (LL b = n + 1 ; b <= 2 * n ; b++) {
            if ((n * b) % (b - n) == 0) {
                ans = max(ans, b ^ ((n * b) / (b - n)));
            }
        }
        cout << ans << '\n';
    }
}
