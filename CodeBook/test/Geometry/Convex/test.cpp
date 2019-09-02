#include <bits/stdc++.h>
#include "../../../Geometry/Convex.cpp"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n; cin >> n;
    vector<P> ps;
    while (n--) {
      long long x, y; cin >> x >> y; char c; cin >> c;
      ps.push_back(P{(double)x, (double)y});
    }
    vector<P> ans = convexHull(ps);
    cout << ans.size() << '\n';
    for (auto &p : ans)
      cout << (long long)p.x << ' ' << (long long)p.y << '\n';
  }
}
