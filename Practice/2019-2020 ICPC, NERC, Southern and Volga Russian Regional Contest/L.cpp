#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int a, b, c; cin >> a >> b >> c;
        int ans = INF;
        ans = min(max((a - 1) / 2 + 1, c), ans);
        ans = min(max((c - 1) / 2 + 1, a), ans);
        ans = max(ans, (a + b + c - 1) / 3 + 1);
        cout << ans << '\n';
    }

}
