#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long ans = 0;
    vector<int> data(n), data2(n);
    for (auto &v : data)
        cin >> v;
    for (int i = 0 ; i < n ; i++) {
        cin >> data2[i];
        if (data[i] == data2[i])
            ans += 1;
        else if (data[i] > data2[i])
            ans += 3;
    }
    cout << ans << '\n';
}
