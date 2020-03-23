#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, int> pool;
    int n; cin >> n; for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        pool[s]++;
    }
    int maxV = 0; string ans;
    for (auto &p : pool) {
        if (maxV < p.second)
            maxV = p.second, ans = p.first;
    }
    if (maxV * 2 > n)
        cout << ans << '\n';
    else
        cout << "NONE\n";
}
