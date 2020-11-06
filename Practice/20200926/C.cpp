#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
