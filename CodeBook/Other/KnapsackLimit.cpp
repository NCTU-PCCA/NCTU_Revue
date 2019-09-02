#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
typedef vector<LL> VLL;
LL knapsack(VLL &v, VLL &w, VLL &m, LL W) {
  int n = v.size(); LL ans = 0, sum = 0;
  vector<LL> dp(W + 1, 0);
  for (int i = 0 ; i < n ; i++) sum += m[i] * w[i];
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; m[i] > 0 ; ++j) {
      int take = min(m[i], (1LL << j)); m[i] -= take;
      for(int k = W; k >= take * w[i] ; --k) 
        dp[k] = max(dp[k], dp[k-take*w[i]]+take*v[i]);
    }
  }
  for(int i = W; i >= 0; --i) ans = max(ans, dp[i]);
  return ans;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  VLL v(n), w(n), m(n);
  for (int i = 0 ; i < n ; i++)
    cin >> v[i] >> w[i] >> m[i];
  LL W; cin >> W;
  cout << knapsack(v, w, m, W) << '\n';
}
