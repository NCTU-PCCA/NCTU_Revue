#include <bits/stdc++.h>
using namespace std;
// LatexBegin
string minRotate(string s) {
  int n = s.size(), i = 0, j = 1, ans; s += s;
  while (i < n && j < n) { int k = 0;
    while (k < n && s[i + k] == s[j + k]) k++;
    if (s[i + k] <= s[j + k]) j += k + 1;
    else i += k + 1; if (i == j) j++;
  }
  return ans = i < n ? i : j, s.substr(ans, n);
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; while (cin >> s) cout << minRotate(s) << '\n';
}
