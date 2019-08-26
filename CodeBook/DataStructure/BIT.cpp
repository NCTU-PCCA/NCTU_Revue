#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
struct BIT { vector<LL> d1, d2; int n;
  BIT(int n) : n(n) { d1.resize(n + 1, 0); d2 = d1; }
  void _(int &x, int v) { x += v * (x & -x); }
  int Q(int x) { x++; LL ret = 0, p = x;
    while (x > 0) ret += (p+1)*d1[x] - d2[x], _(x,-1);
    return ret;
  }
  void M(int x, LL v) { x++; LL p = x;
    while (x <= n) d1[x] += v, d2[x] += v * p, _(x, 1);
  }
  int Q(int l, int r) { return Q(r - 1) - Q(l - 1); }
  void M(int l, int r, LL v) { M(l, v); M(r, -v); }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n; cin >> n; BIT *sol = new BIT(n);
    for (int i = 0 ; i < n ; i++) {
      LL v; cin >> v; sol->M(i, i + 1, v);
    }
    int q; cin >> q; while (q--) {
      int op; cin >> op;
      if (op == 0) { // Q
        int l, r; cin >> l >> r;
        cout << sol->Q(l, r) << '\n';
      }
      if (op == 1) {
        int l, r; LL v; cin >> l >> r >> v;
        sol->M(l, r, v);
      }
    }
    delete sol;
  }
}
