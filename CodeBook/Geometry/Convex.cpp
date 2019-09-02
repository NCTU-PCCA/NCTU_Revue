#ifndef CONVEX_H
#define CONVEX_H
#include <bits/stdc++.h>
#include "Point.cpp"
using namespace std;
// LatexBegin
T cross(const P &o, const P &a, const P &b) {
  return (a - o) % (b - o);
}
vector<P> convexHull(vector<P> &ps) {
  sort(ps.begin(), ps.end());
  vector<P> stk, ret;
  for (auto &p : ps) {
    while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
      stk.pop_back();
    stk.push_back(p);
  }
  stk.pop_back();
  for (auto &p : stk) ret.push_back(p);
  reverse(ps.begin(), ps.end()); stk.clear();
  for (auto &p : ps) {
    while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
      stk.pop_back();
    stk.push_back(p);
  }
  stk.pop_back();
  for (auto &p : stk) ret.push_back(p);
  return ret;
}
T A(P a, P b, P c) { return abs((b - a) % (c - a)); }
bool PointInConvex(P p, vector<P> &ps) { 
  int n = ps.size(); 
  P t = p-ps[0], f = ps[1]-ps[0], b = ps[n - 1]-ps[0];
  if (atan2(t.y, t.x) < atan2(f.y, f.x)
   || atan2(t.y, t.x) > atan2(b.y, b.x)
  )
    return false;
  int L = 0, R = n - 2; while (R - L > 1) {
    int M = (L + R) >> 1; P c = ps[M + 1] - ps[0];
    (atan2(t.y, t.x) >= atan2(c.y, c.x) ? L : R) = M;
  }
  L++, R++;
  return A(p, ps[0], ps[L]) + A(p, ps[0], ps[R]) 
       + A(p, ps[L], ps[R]) <= A(ps[0], ps[L], ps[R]);
}
// LatexEnd
#endif
