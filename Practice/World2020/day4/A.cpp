#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

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
T dir(P p, L l) {
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

P ProjectPointLine(P p, L l) {
  // assume l.p1 != l.p2
  return l.p1 + (l.p2 - l.p1) * ((p - l.p1) * (l.p2 - l.p1)) / ((l.p2 - l.p1) * (l.p2 - l.p1));
}
// LatexEnd


pair<P, T> SmallestEnclosingCircle(vector<P> points) {
  random_shuffle(points.begin(), points.end());
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

vector<P> CircleCircleIntersection(P c1, P c2, T r1, T r2) {
  vector<P> ret;
  T R = dist(c1, c2);
  if (fabs(R - (r1 + r2)) < EPS) {
    P c = (c1 * r2 + c2 * r1) / (r1 + r2);
    ret.push_back(c);
    return ret;
  }
  if (R > (r1 + r2)) return ret;
  P a = c2 - c1;
  T r = (r1 * r1 - r2 * r2) / 2 / R + R / 2;
  P c = c1 + a * (r / R);
  T h = sqrt(r1 * r1 - r * r);
  P b = P(-a.y, a.x) * (h / R);
  ret.push_back(c + b);
  ret.push_back(c - b);
  return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<P> ps(n);
    for (auto &p : ps)
        cin >> p.x >> p.y;
    auto x = SmallestEnclosingCircle(ps);
    cout << fixed << setprecision(10) << x.F.x << ' ';
    cout << fixed << setprecision(10) << x.F.y << '\n';
    cout << fixed << setprecision(10) << x.S << '\n';
}

