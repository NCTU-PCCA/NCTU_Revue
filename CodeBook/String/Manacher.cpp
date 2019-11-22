#include<bits/stdc++.h>
using namespace std;
// LatexBegin
string manacher(string &S) { string s = "*", ret;
  for (auto &c : S) s += "#", s += c; s += "#";
  int p = 0, r = 0, len = 0, idx;
  vector<int> dp(s.size(), 0);
  for (int i = 1 ; i < s.size() ; i++) {
    dp[i] = (i < r ? min(r - i, dp[2 * p - i]) : 1);
    while (s[i - dp[i]] == s[i + dp[i]]) dp[i]++;
    if (i + dp[i] > r) r = i + dp[i], p = i;
    if (len < dp[i] - 1) idx = i, len = dp[i] - 1;
  }
  s = s.substr(idx - len, len * 2);
  for (auto &c : s) if (c != '#') ret += c;
  return ret;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; while (cin >> s)
    cout << manacher(s).size() << '\n';
}
