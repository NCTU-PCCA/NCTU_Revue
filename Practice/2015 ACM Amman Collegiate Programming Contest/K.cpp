#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> data;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            data[v]++;
        }
        bool find = false;
        for (auto &p : data) {
            if (!p.first) continue;
            if (k % p.first)
                continue;
            int tar = k / p.first;
            if (p.first == tar) {
                if (p.second > 1) {
                    find = true;
                    cout << p.first << ' ' << tar << '\n';
                }
            } else if (data.count(tar)) {
                find = true;
                cout << p.first << ' ' << tar << '\n';
            }
            if (find)
                break;
        }
        if (!find)
            cout << -1 << '\n';
        
    }

}
