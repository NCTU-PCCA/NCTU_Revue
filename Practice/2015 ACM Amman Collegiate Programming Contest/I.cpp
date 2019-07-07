#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(string s, int K, int tar) {
    for (int i = 0 ; i + K <= (int)s.size() ; i++) {
        int diff = (tar - (s[i] - '0') + 10) % 10;
        for (int j = 0 ; j < K ; j++) {
            s[i + j] += diff;
            if (s[i + j] > '9')
                s[i + j] -= 10;
        }
    }
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] != char(tar + '0'))
            return false;
    }
    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int len = s.size(), ans;
        for (ans = len - 1 ; ans > 0 ; ans--) {
            bool ok = false;
            for (int i = 0 ; i < 10 ; i++) {
                ok = check(s, ans, i);
                if (ok) break;
            }
            if (ok) break;
        }
        cout << ans << '\n';
    }
}
