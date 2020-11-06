#include <bits/stdc++.h>
#include "Basic.cpp"
using namespace std;

// LatexBegin
C SmallestEnclosingCircle(vector<P> ps) {
  if (ps.size() == 0) return C(P(0, 0), 0);
  random_shuffle(ps.begin(), ps.end());
  C ret(ps[0], 0);
  for (int i = 1 ; i < ps.size() ; i++) {
    if (sign(ps[i].dist(ret.ct) - ret.r) > 0) {
      ret = C(ps[i], 0);
      for (int j = 0 ; j < i ; j++) {
        if (sign(ps[j].dist(ret.ct) - ret.r) > 0) {
          P ct = (ps[i] + ps[j]) / 2;
          ret = C(ct, ps[j].dist(ct));
          for (int k = 0 ; k < j ; k++) {
            if (sign(ps[k].dist(ret.ct) - ret.r) > 0) {
              ret = TriangleCircumCircle(ps[i], ps[j], ps[k]);
            }
          }
        }
      }
    }
  }
  return ret;
}
// LatexEnd
int main() {
    int n; cin >> n;
    vector<P> ps(n);
    for (auto &p : ps)
        cin >> p.x >> p.y;
    C ans = SmallestEnclosingCircle(ps);
    cout << fixed << setprecision(10) << ans.r << '\n' << ans.ct.x << ' ' << ans.ct.y << '\n';

}
