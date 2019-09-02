#ifndef POLYGON_H
#define POLYGON_H
#include <bits/stdc++.h>
#include "Point.cpp"
#include "Line.cpp"
#include "Segment.cpp"
using namespace std;

// LatexBegin
bool PointInPolygon(const vector<P> & points, P p) {
  bool ret = 0;
  for (int i = 0; i < points.size(); i++){
    int j = (i + 1) % points.size();
    T x = points[i].x + (points[j].x - points[i].x) * (p.y - points[i].y) / (points[j].y - points[i].y);
    if ((points[i].y <= p.y && p.y < points[j].y ||
      points[j].y <= p.y && p.y < points[i].y) && p.x < x)
      ret = !ret;
  }
  // strictly interior: ret = 1
  // strictly exterior: ret = 0
  // on boundary: ret = 0 or 1
  return ret;
}

bool PointOnPolygon(const vector<P> & points, P p) {
  for (int i = 0; i < points.size(); i ++) {
    P a = points[i], b = points[(i + 1) % points.size()];
    if (dist2(ProjectPointLine(p, L{a, b}), p) < EPS 
        && intersect(p, S{a, b}))
      return true;
  }
  return false;
}
// LatexEnd
#endif
