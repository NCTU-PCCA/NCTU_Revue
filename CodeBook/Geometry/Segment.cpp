#include <bits/stdc++.h>
using namespace std;
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
// LatexBegin
struct S { P p1, p2; S() {}
  S(P p1, P p2) : p1(p1), p2(p2) {}
};
T dist(P p, S s) {
  V v = s.p2 - s.p1, v1 = p - s.p1, v2 = p - s.p2;
  if (v * v1 < 0) return leng(v1);
  if (v * v2 > 0) return leng(v2);
  return abs(v1 % v2) / leng(v);
}
T btw(P p, S s) { return (s.p1 - p) * (s.p2 - p); }
T dir(P p, S s) { return dir(p, L{s.p1, s.p2}); }
bool intersect(P p, S s) {
  return dir(p, s) == 0 && btw(p, s) <= 0;
}
bool intersection(S s1, S s2) {
  T c1 = dir(s2.p1, s1), c2 = dir(s2.p2, s1);
  T c3 = dir(s1.p1, s2), c4 = dir(s1.p2, s2);
  if (c1 * c2 < 0 && c3 * c4 < 0) return true;
  if (c1 == 0 && intersect(s2.p1, s1)) return true;
  if (c2 == 0 && intersect(s2.p2, s1)) return true;
  if (c3 == 0 && intersect(s1.p1, s2)) return true;
  if (c4 == 0 && intersect(s1.p2, s2)) return true;
  return false;
}
T dist(S s1, S s2) { 
  if (intersection(s1, s2)) return 0;
  return min({
    dist(s1.p1, s2), dist(s1.p2, s2),
    dist(s2.p1, s1), dist(s2.p2, s1)
  });
}
// LatexEnd
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
