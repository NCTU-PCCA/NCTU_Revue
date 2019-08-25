#include <bits/stdc++.h>
using namespace std;
// LatexBegin
vector<int> build(string &t) {
  vector<int> F(t.size()); F[0] = -1;
  for (int i = 1, pos = -1 ; i < t.size() ; i++) {
    while (~pos && t[i] != t[pos + 1]) pos = F[pos];
    if (t[i] == t[pos + 1]) pos++; F[i] = pos;
  }
  return F;
}
bool match(string &s, string &t, vector<int> &F) {
  for (int i = 0, pos = -1 ; i < s.size() ; i++) {
    while (~pos && s[i] != t[pos + 1]) pos = F[pos];
    if (s[i] == t[pos + 1]) pos++;
    if (pos + 1 == (int)t.size()) return true;
  }
  return false;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s, t; cin >> t;
  vector<int> F = build(t);
  while (cin >> s)
    cout << match(s, t, F) << '\n';
}
