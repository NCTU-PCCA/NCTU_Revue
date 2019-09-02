#include <bits/stdc++.h>
#include "Point.cpp"
#include "Convex.cpp"
using namespace std;
// LatexBegin
double largestTriangle(vector<P> &ps) {
  vector<P> c = convexHull(ps); int n = c.size();
  if (n < 3) return 0; T ans = A(c[0], c[1], c[2]);
  for (int i = 0 ; i < n ; i++) {
    for (int j = (i + 1) % n, k = (i + 2) % n 
                   ; (k + 1) % n != i ; j++, j %= n) {
      if (j == k) k++, k %= n;
      while ((k + 1) % n != i 
        && A(c[i],c[j],c[(k+1)%n]) > A(c[i],c[j],c[k]))
        k++, k %= n, ans = max(ans, A(c[i],c[j],c[k]));
    }
  }
  return ans / 2.0;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n; vector<P> data(n);
  for (auto &p : data)
    cin >> p.x >> p.y;
  cout << fixed << setprecision(10) << largestTriangle(data) << '\n';
}
