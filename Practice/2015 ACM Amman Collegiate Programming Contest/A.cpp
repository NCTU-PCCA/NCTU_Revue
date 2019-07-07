#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string ans; int maxV = 0, minP = INF;
        int n; cin >> n;
        for (int i = 0 ; i < n ; i++) {
            string a; int b, c; cin >> a >> b >> c;
            if (b == maxV) {
                if (c < minP) {
                    ans = a;
                    minP = c;
                }
            } else if (b > maxV) {
                ans = a;
                maxV = b;
                minP = c;
            }
        }
        cout << ans << '\n';
    }


}
