#include <bits/stdc++.h>
using namespace std;
int trans(string s) {
    if (s == "red")
        return 1;
    if (s == "yellow")
        return 2;
    if (s == "green")
        return 3;
    if (s == "brown")
        return 4;
    if (s == "blue")
        return 5;
    if (s == "pink")
        return 6;
    if (s == "black")
        return 7;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int M = 0, r = 0, res = 0;
    while (n--) {
        string s; cin >> s;
        int ret = trans(s);
        if (ret == 1)
            r++;
        else {
            M = max(M, ret);
            res += ret;
        }
    }
    if (M == 0)
        cout << 1 << '\n';
    else
        cout << res + r * (1 + M) << '\n';
}
