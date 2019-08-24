#ifndef CIRCLE_H
#define CIRCLE_H
#include <bits/stdc++.h>
#include "Point.cpp"
#include "Line.cpp"
using namespace std;

// LatexBegin
P CircleCenter(P a, P b, P c) {
  P ret;
  T A1 = b.x - a.x, A2 = c.x - a.x;
  T B1 = b.y - a.y, B2 = c.y - a.y;
  T C1 = (A1 * A1 + B1 * B1) / 2;
  T C2 = (A2 * A2 + B2 * B2) / 2;
  T D = A1 * B2 - A2 * B1;
  ret.x = a.x + (C1 * B2 - C2 * B1) / D;
  ret.y = a.y + (A1 * C2 - A2 * C1) / D;
  return ret;
}

pair<P, T> SmallestEnclosingCircle(vector<P> & points) {
  T r = 0; int pn = points.size();
  if (pn == 0) {
    return pair<P, T>(P(0, 0), 0);
  }
  P ret = points[0];
  for (int i = 1; i < pn; i ++) {
    if (dist(points[i], ret) > r + EPS) {
      ret = points[i]; r = 0;
      for (int j = 0; j < i; j ++) {
        if (dist(points[j], ret) > r + EPS) {
          ret.x = (points[i].x + points[j].x) / 2;
          ret.y = (points[i].y + points[j].y) / 2;
          r = dist(points[j], ret);
          for (int k = 0; k < j; k ++) {
            if (dist(points[k], ret) > r + EPS) {
              ret = CircleCenter(points[i], points[j], points[k]);
              r = dist(points[i], ret);
            }
          }
        }
      }
    }
  }
  return pair<P, T>(ret, r); // center, radius
}

vector<P> CircleLineIntersection(P c, T r, L l) {
  vector<P> ret;
  P b = l.p2 - l.p1;
  P a = l.p1 - c;

  P c1 = ProjectPointLine(c, l);
  T dis = dist2(c, c1);
  if (dis > r * r) return ret;
  if (fabs(dis - r * r) < EPS) {
      ret.push_back(c1);
      return ret;
  }
  T x = (r * r - dis);
  ret.push_back(c1 + b * sqrt(x / (b * b)));
  ret.push_back(c1 - b * sqrt(x / (b * b)));
  return ret;
}
// LatexEnd
#endif
