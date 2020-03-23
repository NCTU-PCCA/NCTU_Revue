#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> h(n);
        for (auto &v : h)
            cin >> v;
        int ans = 0;
        int pre = -INF;
        for (int i = 0 ; i < n ; i++) {
            if (pre + 10 < h[i])
                ans++, pre = h[i] + 10;
        }
        cout << ans << '\n';
    }
}
