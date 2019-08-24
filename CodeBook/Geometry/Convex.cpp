#ifndef CONVEX_H
#define CONVEX_H
#include <bits/stdc++.h>
#include "Point.cpp"
using namespace std;
bool convexCmp(const P& l, const P& r) {
  return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}
T cross(const P &o, const P &a, const P &b) {
  return (a - o) % (b - o);
}
vector<P> convexHull(vector<P> &ps) {
  sort(ps.begin(), ps.end(), convexCmp);
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
  for (auto &p : stk) ret.push_back(p);
  return ret;
}
#endif
