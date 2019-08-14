#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<char> a, b;
    string A, B; cin >> A >> B;
    for (auto &c : A)
        a.push_back(c);
    for (auto &c : B)
        b.push_back(c);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int ans = 0;
    while (a.size() && b.size()) {
        ans++;
        if (a.back() == 'L' && b.back() != 'L') {
            b.pop_back();
        } else if (b.back() == 'L' && a.back() != 'L') {
            a.pop_back();
        } else {
            a.pop_back();
            b.pop_back();
        }
    }
    ans += a.size();
    ans += b.size();
    cout << ans << '\n';
}
