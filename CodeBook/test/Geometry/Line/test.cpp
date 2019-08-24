#include <bits/stdc++.h>
#include "../../../Geometry/Line.cpp"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  L l1, l2;
  cin >> l1.p1.x >> l1.p1.y;
  cin >> l1.p2.x >> l1.p2.y;
  cin >> l2.p1.x >> l2.p1.y;
  cin >> l2.p2.x >> l2.p2.y;
  cout << fixed << setprecision(10) << dist(l1, l2) << '\n';
  cout << parallel(l1, l2) << '\n';
  cout << intersect(l1, l2) << '\n';
}
