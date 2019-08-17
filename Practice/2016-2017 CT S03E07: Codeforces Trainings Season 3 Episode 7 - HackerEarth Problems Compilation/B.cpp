#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        if ((1 << __lg(s.size())) == s.size()) {
            bool ok = true;
            for (int i = 0 ; i < s.size() ; i += 2) {
                if (s[i] == 'A' && s[i + 1] == 'A')
                    ok = false;
            }
            if (ok)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else cout << "NO\n";
    }
}
