#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        char c = s[s.size() - 1];
        if (c == 'a') {
            s += "s";
        } else if (c == 'i' || c == 'y') {
            s.pop_back();
            s += "ios";
        } else if (c == 'l') {
            s += "es";
        } else if (c == 'o') {
            s += "s";
        } else if (c == 'r') {
            s += "es";
        } else if (c == 't') {
            s += "as";
        } else if (c == 'u') {
            s += "s";
        } else if (c == 'v') {
            s += "es";
        } else if (c == 'w') {
            s += "as";
        } else if (s.substr(s.size() - 2, 2) == "ne") {
            s.pop_back();
            s.pop_back();
            s += "anes";
        } else if (c == 'n') {
            s.pop_back();
            s += "anes";
        } else {
            s += "us";
        }
        cout << s << '\n';
    }
}
