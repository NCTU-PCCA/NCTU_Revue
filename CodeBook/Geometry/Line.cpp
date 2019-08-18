#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
using T = double;
#define O operator
#define CP (const P &p) const 
typedef struct P { T x, y;
  P(T x = 0, T y = 0) : x(x), y(y) {}
  P O+CP { return P(x + p.x, y + p.y); }
  P O-CP { return P(x - p.x, y - p.y); }
  T O*CP { return x * p.x + y * p.y; }
  T O%CP { return x * p.y - y * p.x; }
  P O*(const T c) const { return P(x * c, y * c); }
  P O/(const T c) const { return P(x / c, y / c); }
} V;
T leng2(V a) { return a * a; }
T leng(V a) { return sqrt(leng2(a)); }
T dist2(P a, P b) { return leng2(a - b); }
T dist(P a, P b) { return sqrt(dist2(a, b)); }
// LatexBegin
struct L { P p1, p2; L() {}
    L(P p1, P p2) : p1(p1), p2(p2) {}
};
T dist(P p, L l) {
  V v1 = p - l.p1, v2 = l.p2 - l.p1;
  return abs(v1 % v2) / leng(v2);
}
T dist(L l1, L l2) {
  V v1 = l1.p2 - l1.p1; V v2 = l2.p2 - l2.p1;
  if (v1 % v2 != 0) return 0;
  return dist(l1.p1, l2);
}
int dir(P p, L l) { 
  return (l.p2 - l.p1) % (p - l.p1);
}
bool parallel(L l1, L l2) {
  return (l1.p1 - l1.p2) % (l2.p1 - l2.p2) == 0;
}
int intersect(L l1, L l2) { 
  // -1: infinity, 1: one, 0: none
  return parallel(l1, l2) ? 
      (dir(l1.p2, l2) == 0 ? -1 : 0) : 1;
}
// LatexEnd
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
