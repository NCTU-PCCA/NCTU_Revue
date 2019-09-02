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
// LatexEnd
bool PointInConvex(P p, vector<P> &ps) {
  int n = ps.size();
  vector<P> ang;
  for (int i = 0 ; i < n - 1 ; i++) {
    ang.push_back(ps[i] - ps.back());
  }
  for (auto &p : ang)
    cout << p.x << ' ' << p.y << '\n';
  return true;
}
#endif
