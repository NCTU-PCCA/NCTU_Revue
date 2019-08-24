#include <bits/stdc++.h>
#include "../../../Geometry/Point.cpp"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  P a, b; cin >> a.x >> a.y >> b.x >> b.y;
  cout << fixed << setprecision(10) << (a + b).x << ' ' << (a + b).y << '\n';
  cout << fixed << setprecision(10) << (a - b).x << ' ' << (a - b).y << '\n';
  cout << fixed << setprecision(10) << a * b << '\n';
  cout << fixed << setprecision(10) << a % b << '\n';
  cout << fixed << setprecision(10) << leng(a) << '\n';
  cout << fixed << setprecision(10) << dist(a, b) << '\n';
}

