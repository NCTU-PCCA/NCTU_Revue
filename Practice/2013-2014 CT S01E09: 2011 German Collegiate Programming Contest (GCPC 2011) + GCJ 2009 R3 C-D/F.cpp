#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int>pii;
typedef long long LL;
char trans(char c, int m) {
    return 'A' + (c - 'A' - m + 26) % 26;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string s; getline(cin, s); while (t--) {
        getline(cin, s);
        vector<int> cnt(26, 0);
        for (auto &c : s) {
            if (c == ' ') continue;
            cnt[c - 'A']++;
        }
        int maxV = *max_element(cnt.begin(), cnt.end());
        int x = 0, idx = -1;
        for (int i = 0 ; i < 26 ; i++) {
            if (maxV == cnt[i]) {
                x++;
                idx = i;
            }
        }
        if (x != 1) {
            cout << "NOT POSSIBLE\n";
        } else {
            int d = ((idx + 'A') - 'E' + 26) % 26;
            cout << d << ' ';
            for (auto &c : s) {
                if (c == ' ')
                    cout << c;
                else
                    cout << trans(c, d);
            }
            cout << '\n';
        }
    }
}
