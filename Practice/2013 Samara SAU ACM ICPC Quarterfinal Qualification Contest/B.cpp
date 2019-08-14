#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<vector<int>, int> cnt;
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        vector<int> tar;
        map<char, int> C;
        for (auto &c : s) {
            if (!C.count(c))
                C[c] = C.size();
            tar.push_back(C[c]);
        }
        cnt[tar]++;
    }
    long long ans = 0;
    for (auto &p : cnt) {
        ans += (long long)p.second * (p.second - 1) / 2;
    }
    cout << ans << '\n';
}
