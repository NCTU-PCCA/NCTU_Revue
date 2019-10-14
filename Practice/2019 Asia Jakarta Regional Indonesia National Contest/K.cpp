#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int cnt[2] = {0};
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        cnt[v % 2]++;
    }
    int ans = min(cnt[0], cnt[1]);
    cnt[0] -= ans;
    cnt[1] -= ans;
    ans += cnt[1] / 2;
    cout << ans << '\n';
}
