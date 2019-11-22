#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
// LatexBegin
VI SM(VVI &B, VVI &_G) { int n = B.size();
  VVI G(n, VI(n));
  for (int i = 0 ; i < n ; i++)
    for (int j = 0 ; j < n ; j++)
      G[i][_G[i][j]] = j;
  VI p(n, 0), b(n, -1), g(n, -1); bool chg = true;
  while (chg) { chg = false;
    for (int i = 0 ; i < n ; i++) {
      if (~b[i]) continue; chg = true;
      while (1) { int j = B[i][p[i]];
        if (g[j]==-1||G[j][g[j]]>G[j][i]&&(b[g[j]]=-1))
          break;
        p[i]++;
      }
      int j = B[i][p[i]]; b[i] = j; g[j] = i;
    }
  }
  return b;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t, f = 1; cin >> t; while (t--) {
    if (f) f = 0; else cout << '\n';
    int n; cin >> n;
    vector<vector<int> > B(n, vector<int>(n)), G(n, vector<int>(n));
    for (auto &vv : B)
      for (auto &v : vv)
        cin >> v, v--;
    for (auto &vv : G)
      for (auto &v : vv)
        cin >> v, v--;
    vector<int> b = SM(B, G);
    for (int i = 0 ; i < n ; i++)
      cout << b[i] + 1 << '\n';
  }
}
