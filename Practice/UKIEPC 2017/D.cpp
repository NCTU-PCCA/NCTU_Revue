#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == t[i])
            continue;
        for (int j = i + 1 ; j < s.size() ; j++) {
            if (t[j] != s[i])
                continue;
            // t[i], t[j];
            if (t[i] > t[j])
                cout << i + 1 << ' ' << j + 1 << '\n';
            else
                cout << j + 1 << ' ' << i + 1 << '\n';
            swap(t[i], t[j]);
            break;
        }
    }
}
