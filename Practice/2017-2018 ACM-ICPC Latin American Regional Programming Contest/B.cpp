#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
bool ok(char c) {
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<int> idx;
    for (int i = 0 ; i < s.size() ; i++) {
        char c = s[i];
        if (ok(c))
            idx.push_back(i);
    }
    if (idx.size() == 0 || idx.size() == s.size()) {
        cout << 1 << '\n';
    } else if (!ok(s[0])) {
        cout << 0 << '\n';
    } else if (idx.size() == 1) {
        cout << s.size() << '\n';
    } else if (idx.size() % 2 == 0) {
        cout << idx[idx.size() / 2] - idx[idx.size() / 2 - 1] << '\n';
    } else {
        cout << idx[(idx.size() + 1) / 2] - idx[(idx.size() + 1) / 2 - 1] << '\n';
    }
}
