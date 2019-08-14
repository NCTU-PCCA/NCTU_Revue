#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    deque<char> S, T;
    for (auto &c : s)
        S.push_back(c);
    for (auto &c : t)
        T.push_back(c);
    while (S.size() && T.size() && S.front() == T.front())
        S.pop_front(), T.pop_front();
    while (S.size() && T.size() && S.back() == T.back())
        S.pop_back(), T.pop_back();
    string a, b;
    for (auto &c : S)
        a += c;
    for (auto &c : T)
        b += c;
    reverse(b.begin(), b.end());
    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";

}
