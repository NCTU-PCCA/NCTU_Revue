#ifndef CLOSEPAIR_H
#define CLOSEPAIR_H
#include <bits/stdc++.h>
#include "Point.cpp"
#define F first
#define S second
using namespace std;
const T INF = 1e9;
// LatexBegin
bool cmpPair(const P &l, const P &r) {
  return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}
pair<P, P> solve(vector<P> &ps, int L, int R) {
  pair<P, P> ret = {P{-INF, -INF}, P{INF, INF}};
  if (R - L <= 1) return ret;
  int M = (R + L) >> 1;
  pair<P, P> pL = solve(ps, L, M);
  pair<P, P> pR = solve(ps, M, R);
  T d = min(dist(pL.F, pL.S), dist(pR.F, pR.S));
  ret = (dist(pL.F, pL.S) + EPS < dist(pR.F, pR.S) ? pL : pR);
  vector<P> C;
  for (int i = L ; i < R ; i++)
    if (abs(ps[M].x - ps[i].x) < d)
      C.push_back({ps[i].y, ps[i].x});
  sort(C.begin(), C.end(), cmpPair);
  for (int i = 0 ; i < (int)C.size() ; i++) {
    for (int j = i + 1 ; j < (int)C.size() && C[j].x - C[i].x < d ; j++)
      ret = (d + EPS < dist(C[i], C[j]) ? ret : make_pair(C[i], C[j])),
      d = min(d, dist(C[i], C[j]));
  }
  return ret;
}
pair<P, P> closetPair(vector<P> &ps) {
  sort(ps.begin(), ps.end(), cmpPair);
  return solve(ps, 0, ps.size());
}
// LatexEnd
#endif
