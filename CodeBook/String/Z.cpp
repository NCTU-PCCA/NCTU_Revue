#include <bits/stdc++.h>
using namespace std;
// LatexBegin
vector<int> Z(string &s) { int L = 0, R = 0;
  vector<int> z(s.size()); z[0] = s.size();
  for (int i = 1 ; i < (int)s.size() ; i++) {
    if (i <= R && z[i - L] <= R - i) z[i] = z[i - L];
    else { L = i; if (i > R) R = i;
      while (R < z[0] && s[R - L] == s[R]) R++;
      z[i] = (R--) - L;
    }
  }
  return z;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; while (cin >> s) {
    vector<int> z = Z(s);
    for (int i = 0 ; i < z.size() ; i++)
      cout << z[i] << " \n"[i + 1 == (int)z.size()];
  }
}
