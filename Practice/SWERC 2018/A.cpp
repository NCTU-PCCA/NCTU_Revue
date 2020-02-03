#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> data(n + 1, 1);
    int cnt = 0, ans = 0;
    while (m--) {
        int v; cin >> v;
        for (int i = v ; i <= n ; i += v) {
            if (data[i] == 0)
                cnt--;
            else
                cnt++;
            data[i] ^= 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
