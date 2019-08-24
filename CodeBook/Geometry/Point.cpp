#ifndef POINT_H
#define POINT_H
// LatexBegin
using T = double;
const T EPS = 1e-8;
#define O operator
#define CP (const P &p) const 
typedef struct P { T x, y;
  P(T x = 0, T y = 0) : x(x), y(y) {}
  P O+CP { return P(x + p.x, y + p.y); }
  P O-CP { return P(x - p.x, y - p.y); }
  T O*CP { return x * p.x + y * p.y; }
  T O%CP { return x * p.y - y * p.x; }
  T O<CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
  P O*(const T c) const { return P(x * c, y * c); }
  P O/(const T c) const { return P(x / c, y / c); }
} V;
T leng2(V a) { return a * a; }
T leng(V a) { return sqrt(leng2(a)); }
T dist2(P a, P b) { return leng2(a - b); }
T dist(P a, P b) { return sqrt(dist2(a, b)); }
// LatexEnd
#endif
