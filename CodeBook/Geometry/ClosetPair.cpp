#ifndef CLOSEPAIR_H
#define CLOSEPAIR_H
#include <bits/stdc++.h>
#include "Basic.cpp"
#define F first
#define S second
using namespace std;
const T INF = 1e9;
// LatexBegin
pair<P, P> _closetPair(vector<P> &ps, int L, int R) {
  pair<P, P> ret = {P{-INF, -INF}, P{INF, INF}};
  if (R - L <= 1) return ret;
  int M = (R + L) >> 1;
  pair<P, P> pL = _closetPair(ps, L, M);
  pair<P, P> pR = _closetPair(ps, M, R);
  T d = min(pL.F.dist(pL.S), pR.F.dist(pR.S));
  ret = sign(pL.F.dist(pL.S)-pR.F.dist(pR.S))<0?pL:pR;
  vector<P> C;
  for (int i = L ; i < R ; i++)
    if (abs(ps[M].x - ps[i].x) < d)
      C.push_back({ps[i].y, ps[i].x});
  sort(C.begin(), C.end());
  for (int i = 0 ; i < (int)C.size() ; i++) {
    for (int j=i+1 ; j<C.size()&&C[j].x-C[i].x<d;j++) {
      if (sign(d - C[i].dist(C[j])) >= 0)
        ret = make_pair(C[i], C[j]);
      d = min(d, C[i].dist(C[j]));
    }
  }
  return ret;
}
pair<P, P> closetPair(vector<P> &ps) {
  sort(ps.begin(), ps.end());
  return _closetPair(ps, 0, ps.size());
}
// LatexEnd
#endif
