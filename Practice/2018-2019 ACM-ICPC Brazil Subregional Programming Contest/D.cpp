#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    int ans = 0;
    for (auto &v : arr) {
        cin >> v;
        if (v != 1)
            ans++;
    }
    cout << ans << '\n';
}
