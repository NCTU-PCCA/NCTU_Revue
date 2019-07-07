#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, s; cin >> n >> s;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        int ans = 0;
        for (int i = 1 ; i < (1 << n) ; i++) {
            int minV = INF, sum = 0, cnt  = 0;
            for (int j = 0 ; j < n ; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    sum += data[j];
                    minV = min(minV, data[j]);
                }
            }
            if (sum >= s && sum - minV < s)
                ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }


}
