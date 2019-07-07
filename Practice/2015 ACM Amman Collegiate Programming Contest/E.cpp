#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        sort(data.begin(), data.end());
        int x = 100 - data.back();
        for (auto &v : data)
            v += x;
        int ans = 0;
        for (auto &v : data)
            if (v >= 50)
                ans++;
        cout << ans << '\n';
    }
}
