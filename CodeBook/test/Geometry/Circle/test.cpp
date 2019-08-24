#include <bits/stdc++.h>
#include "../../../Geometry/Circle.cpp"
using namespace std;

// uva 10005
vector<P> points;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  while (cin >> n && n) {
      for (int i = 0; i < n; i ++) {
        double x, y; cin >> x >> y;
        points.push_back({x, y});
      }
      double r; cin >> r;
      pair<P, double> ans = SmallestEnclosingCircle(points);
      if (ans.second > r) {
          cout << "There is no way of packing that polygon.\n";
      } else {
          cout << "The polygon can be packed in the circle.\n";
      }
  }
}

