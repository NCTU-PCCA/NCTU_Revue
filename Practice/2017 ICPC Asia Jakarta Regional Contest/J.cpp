#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, t; cin >> n >> k >> t;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    sort(data.begin(), data.end());
    int cnt = 0;
    for (int i = 0 ; i < n ; i++)
        if (data[i] == data[k - 1])
            cnt++;
    if (cnt == 1) {
        cout << 0 << '\n';
        exit(0);
    }
    int cnt2 = 0;
    for (int i = 0 ; i < k ; i++) {
        if (data[i] == data[k - 1])
            cnt2++;
    }
    if (cnt2 == cnt) {
        cout << 0 << '\n';
        exit(0);
    }
    if (data[k - 1] == 0 && t == 0) {
        cout << -1 << '\n';
        exit(0);
    }
    if (data[k - 1] == 0) {
        cout << cnt - cnt2 << '\n';
        exit(0);
    }
    if (data[k - 1] == t) {
        cout << cnt2 << '\n';
        exit(0);
    }
    cout << min(cnt2, cnt - cnt2) << '\n';
}
