#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    int ans = 0;
    for (int i = 0 ; i + t.size() <= s.size() ; i++) {
        bool ok = true;
        for (int j = 0 ; j < t.size() ; j++) {
            if (s[i + j] == t[j]) {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}
