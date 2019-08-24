#ifndef LINE_H
#define LINE_H
#include <bits/stdc++.h>
#include "Point.cpp"
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
  return abs((l1.p1 - l1.p2) % (l2.p1 - l2.p2)) <= EPS ;
}
int intersect(L l1, L l2) { 
  // -1: infinity, 1: one, 0: none
  return parallel(l1, l2) ? 
      (abs(dir(l1.p2, l2)) <= EPS ? -1 : 0) : 1;
}
// LatexEnd
#endif
