#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    cout << s.size();
    LL x = 0, y = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        x *= 2, y *= 2;
        if (s[i] == '1')
            x++;
        else if (s[i] == '2')
            y++;
        else if (s[i] == '3')
            x++, y++;
    }
    cout << ' ' << x << ' ' << y << '\n';
}
