#include <bits/stdc++.h>
using namespace std;
/*
// LatexBegin
string BWT(string); // by suffix array
// LatexEnd
*/
// LatexBegin
string iBWT(string &s, int start=0){
  int n = (int)s.size(); string ret(n, ' ');
  vector <int> next(n, 0), box[256];
  for (int i = 0; i < n ; i++) box[s[i]].push_back(i);
  for (int i = 0, j = 0 ; i < 256 ; i++)
  for (int x : box[i]) next[j++] = x;
  for (int i = 0, p = start ; i < n ; i++)
    ret[i] = s[p = next[p]];
  return ret;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int f = 1;
  string s; while (cin >> s) {
    if (s == "END")
      break;
    int p; cin >> p; p--;
    if (f) f = 0; else cout << '\n';
    cout << iBWT(s, p) << '\n';
  }
}
