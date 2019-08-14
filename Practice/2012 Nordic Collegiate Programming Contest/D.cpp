#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x; cin >> x;
    string s; cin >> s;
    int cur = 0;
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] == 'W')
            cur--;
        else
            cur++;
        if (abs(cur) > x + 1) {
            cout << i - 1 << '\n';
            return 0;
        }
    }
    cout << s.size() << '\n';
}
