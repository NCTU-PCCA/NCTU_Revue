#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v, v--;
    vector<int> ans;
    int minV = arr[n - 1];
    for (int i = n - 2 ; i >= 0 ; i--) {
        if (minV < arr[i])
            ans.push_back(arr[i]);
        minV = min(minV, arr[i]);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto &v : ans)
        cout << v + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
