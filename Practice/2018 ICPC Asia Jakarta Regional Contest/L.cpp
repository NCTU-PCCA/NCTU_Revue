#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL eval(string &s) {
    LL ret = 0;
    for (auto &c : s)
        ret *= 2, ret += c - '0';
    return ret;
}
void trans(string &s) {
    int idx = -1;
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (s[i] == '1') {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        s.pop_back();
    else {
        string ret = s.substr(0, idx) + s.substr(idx + 1, s.size() - idx - 1);
        s = ret;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL k; cin >> k;
    string s; cin >> s;
    int cnt = 0;
    while (eval(s) > k)
        trans(s), cnt++;
    cout << cnt << '\n';
}
