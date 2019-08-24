#ifndef SEGMENT_H
#define SEGMENT_H
#include <bits/stdc++.h>
#include "Point.cpp"
#include "Line.cpp"
using namespace std;
// LatexBegin
struct S { P p1, p2; S() {}
  S(P p1, P p2) : p1(p1), p2(p2) {}
};
T dist(P p, S s) {
  V v = s.p2 - s.p1, v1 = p - s.p1, v2 = p - s.p2;
  if (v * v1 < -EPS) return leng(v1);
  if (v * v2 > EPS) return leng(v2);
  return abs(v1 % v2) / leng(v);
}
T btw(P p, S s) { return (s.p1 - p) * (s.p2 - p); }
T dir(P p, S s) { return dir(p, L{s.p1, s.p2}); }
bool intersect(P p, S s) {
  return abs(dir(p, s)) < EPS && btw(p, s) <= EPS;
}
bool intersection(S s1, S s2) {
  T c1 = dir(s2.p1, s1), c2 = dir(s2.p2, s1);
  T c3 = dir(s1.p1, s2), c4 = dir(s1.p2, s2);
  if (c1 * c2 < -EPS && c3 * c4 < -EPS) return true;
  if (abs(c1) < EPS && intersect(s2.p1, s1)) return true;
  if (abs(c2) < EPS && intersect(s2.p2, s1)) return true;
  if (abs(c3) < EPS && intersect(s1.p1, s2)) return true;
  if (abs(c4) < EPS && intersect(s1.p2, s2)) return true;
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
#endif
