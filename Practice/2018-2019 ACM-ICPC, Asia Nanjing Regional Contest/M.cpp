#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int z[MAXN];
int num[MAXN];
void manacher(string &S) {
    string s = "*";
    for (auto &c : S)
        s += "#", s += c;
    s += "#";
    int p = 0, r = 0, len = 0, idx;
    vector<int> dp(s.size(), 0);
    for (int i = 1 ; i < s.size() ; i++) {
        dp[i] = (i < r ? min(r - i, dp[2 * p - i]) : 1);
        while (s[i - dp[i]] == s[i + dp[i]])
            dp[i]++;
        if (i + dp[i] > r) 
            r = i + dp[i], p = i;
        if (len < dp[i] - 1)
            idx = i, len = dp[i] - 1;
    }
    vector<int> diff(S.size() + 1, 0);
    for (int i = 1 ; i < dp.size() ; i += 2) {
        if (dp[i] / 2 == 0)
            continue;
        diff[(i + 1) / 2 - 1]++; // 3
        diff[(i + 1) / 2 - 1 + dp[i] / 2]--; // 6
    }
    for (int i = 2 ; i < dp.size() ; i += 2) {
        diff[(i + 1) / 2 - 1]++;    
        diff[(i + 1) / 2 - 1 + dp[i] / 2]--;
    }
    int cur = 0, iidx = 0;
    for (int i = 0 ; i < diff.size() - 1 ; i++) {
        cur += diff[i];
        num[iidx++] = cur;
    }
}
void Z(int t_len, string s) {
    z[0] = s.size();
    for (int L = 0, R = 0, i = 1; i < s.size(); i++) {
        if (i <= R && z[i - L] <= R - i)
            z[i] = z[i - L];
        else {
            L = i;
            if (i > R) R = i;
            while (R < z[0] && s[R - L] == s[R])
                R++;
            z[i] = (R--) - L;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    manacher(s);
    Z(t.size(), t + "$" + s);
    /*
    for (auto &c : s)
        cout << c << ' ';
    cout << '\n';
    for (auto &v : num)
        cout << v << ' ';
    cout << '\n';
    for (auto &v : z)
        cout << v << ' ';
    cout << '\n';
    */
    long long ans = 0;
    for (int i = 1 ; i < s.size() ; i++)
        ans += (long long)z[i + t.size() + 1] * num[i - 1];
    cout << ans << '\n';
}
