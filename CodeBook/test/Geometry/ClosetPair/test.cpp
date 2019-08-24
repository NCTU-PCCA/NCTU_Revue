#include <bits/stdc++.h>
#include "../../../Geometry/ClosetPair.cpp"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    int n; cin >> n; vector<P> data(n);
    for (auto &p : data)
      cin >> p.x >> p.y;
    sort(data.begin(), data.end(), cmpPair);
    pair<P, P> ans = closetPair(data);
    cout << fixed << setprecision(10) << dist(ans.F, ans.S) << '\n';
  }
}

