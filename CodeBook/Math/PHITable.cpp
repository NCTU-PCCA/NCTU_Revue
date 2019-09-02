#include <bits/stdc++.h>
using namespace std;
// LatexBegin
vector<int> PHITable(int n){
  vector<int> ret(n + 1, 0);
  for (int i = 1 ; i <= n ; i++) ret[i] = i;
  for (int i = 1 ; i <= n ; i++)
    for (int j = i * 2 ; j <= n ; j += i)
      ret[j] -= ret[i];
  return ret;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<int> ret = PHITable(50000);
  vector<int> pre{0, 0, 0};
  for (int i = 2 ; i < ret.size() ; i++)
    pre.push_back(pre.back() + ret[i]);
  int n; while (cin >> n && n) {
    cout << pre[n + 1] * 2 + 1 << '\n';
  }
}
