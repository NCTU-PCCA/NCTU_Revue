#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if (s.size() % 2) {
        cout << "NO\n";
    } else {
        stack<char> stk;
        for (auto &c : s) {
            if (stk.size() && stk.top() != c) {
                stk.pop();
            } else stk.push(c);
        }
        if (stk.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
