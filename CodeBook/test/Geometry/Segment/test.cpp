#include <bits/stdc++.h>
#include "../../../Geometry/Segment.cpp"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  S s1, s2; 
  cin >> s1.p1.x >> s1.p1.y;
  cin >> s1.p2.x >> s1.p2.y;
  cin >> s2.p1.x >> s2.p1.y;
  cin >> s2.p2.x >> s2.p2.y;
  cout << intersection(s1, s2) << '\n';
  cout << fixed << setprecision(10) << dist(s1, s2) << '\n';
}

