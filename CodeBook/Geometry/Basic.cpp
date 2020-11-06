#include <bits/stdc++.h>
#define sq(x) ((x) * (x))
#define F first
#define S second
using namespace std;
using T = long double;
const T EPS = 1e-8;
const T PI = acos(-1.0);
// LatexBegin
int sign(T c) { return c + EPS < 0 ? -1 : abs(c) > EPS; }
typedef struct P {
  T x, y; P(T x = 0, T y = 0) : x(x), y(y) {}
  P operator + (P p) { return P(x + p.x, y + p.y); }
  P operator - (P p) { return P(x - p.x, y - p.y); }
  P operator * (T c) { return P(x * c, y * c); }
  P operator / (T c) { return P(x / c, y / c); }
  T operator * (P p) { return x * p.x + y * p.y; }
  T operator % (P p) { return x * p.y - y * p.x; }
  bool operator < (const P &p) const {
    return sign(x-p.x) ? sign(x-p.x)<0 : sign(y-p.y)<0;
  }
  bool operator == (const P &p) const {
    return !sign(x - p.x) && !sign(y - p.y);
  }
  T leng() { return hypot(x, y); }
  P unit() { return *this / leng(); }
  T dist(P p) { return (*this - p).leng(); }
  P spin(T o) { T c = cos(o), s = sin(o);
    return P(c * x - s * y, s * x + c * y);
  }
  T angle() { return atan2(y, x); }
} V;
struct L { P p1, p2; T a, b, c, o;
  L(P p1, P p2) : p1(p1), p2(p2), a(p1.y - p2.y),
    b(p2.x - p1.x), c(p1 % p2), o(atan2(-a, b)) {}
  P project(P p) { T c = (p2 - p1).unit() * (p - p1);
    return p1 + (p2 - p1).unit() * c;
  }
  P reflect(P p) { return p + (project(p) - p) * 2; }
  T dist(P p) { V v1 = p - p1, v2 = p2 - p1;
    return abs(v1 % v2) / v2.leng();
  }
  T dist(L l) { return isParallel(l) ? dist(l.p1):0; }
  T ratio(P p) {
    return (p - p1) * (p2 - p1) / sq(p2.dist(p1));
  }
  bool isParallel(L l) {
    V v1 = p2 - p1, v2 = l.p2 - l.p1;
    return sign(v1 % v2) == 0;
  }
  bool isIntersect(P p) { return !sign(dist(p)); }
  bool isIntersect(L l) { return !isParallel(l); }
  P intersect(L l) { assert(isIntersect(l));
    T bc = b * l.c - c * l.b, ac = a * l.c - c * l.a;
    return P(bc, -ac) / (a * l.b - b * l.a);
  }
};



struct S { P p1, p2; S(P p1, P p2) : p1(p1), p2(p2) {}
  T dist(P p) { V v = p2 - p1,v1 = p - p1,v2 = p - p2;
    if (sign(v * v1) < 0) return v1.leng();
    if (sign(v * v2) > 0) return v2.leng();
    return abs(v1 % v2) / v.leng();
  }
  T dist(L l) { if (isIntersect(l)) return 0;
    return min(l.dist(p1), l.dist(p2));
  }
  T dist(S s) { if (isIntersect(s)) return 0;
    return min({ dist(s.p1), dist(s.p2),
                 s.dist(p1), s.dist(p2) });
  }
  bool isIntersect(P p) {
    T c = (p2-p1) % (p-p1), d = (p1-p) * (p2-p);
    return sign(c) == 0 && sign(d) <= 0;
  }
  bool isIntersect(L l) {
    V v = l.p2 - l.p1, v1 = p1 - l.p1, v2 = p2 - l.p1;
    return sign((v1 % v) * (v2 * v)) <= 0;
  }
  bool isIntersect(S s) {
    V v1 = p2 - p1, v2 = s.p2 - s.p1;
    T c1 = v1 % (s.p1 - p1), c2 = v1 % (s.p2 - p1);
    T c3 = v2 % (p1 - s.p1), c4 = v2 % (p2 - s.p1);
    if (sign(c1*c2)<0 && sign(c3*c4)<0) return true;
    if (!sign(c1) && isIntersect(s.p1)) return true;
    if (!sign(c2) && isIntersect(s.p2)) return true;
    if (!sign(c3) && s.isIntersect(p1)) return true;
    if (!sign(c4) && s.isIntersect(p2)) return true;
    return false;
  }
  P intersect(L l) { assert(isIntersect(l));
      return L(p1, p2).intersect(l);
  }
  P intersect(S s) { assert(isIntersect(s));
      return L(p1, p2).intersect(L(s.p1, s.p2));
  }
};
struct C { P ct; T r;
  C(P ct = P(), T r = 0) : ct(ct), r(r) {}
  vector<P> intersect(L l) { P x = l.project(ct);
    if (sign(l.dist(ct) - r) > 0) return {};
    if (sign(l.dist(ct) - r) == 0) return {x};
    T len = sqrt(sq(r) - sq((ct - x).leng()));
    P p = l.p1 == x ? l.p2 : l.p1; V v = (p-x).unit();
    return { x + v * len, x - v * len };
  }
  vector<P> intersect(S s) {
    vector<P> lret = intersect(L(s.p1, s.p2)), sret;
    for (auto &p : lret)
      if (s.isIntersect(p)) sret.push_back(p);
    return sret;
  }
  vector<P> intersect(C c) { C a = *this, b = c;
    if (sign(a.r - b.r) > 0) swap(a, b);
    T d = a.ct.dist(b.ct);
    if (sign(a.r + b.r - d) == 0)
      return {a.ct + (b.ct - a.ct).unit() * a.r};
    if (sign(a.r + d - b.r) == 0)
      return {a.ct + (a.ct - b.ct).unit() * a.r};
    if (sign(b.r-a.r-d) < 0 && sign(d-a.r-b.r) < 0) {
      T o = acos((sq(a.r)+sq(d)-sq(b.r)) / (2*a.r*d));
      P v = (b.ct - a.ct).unit();
      return {a.ct+v.spin(o)*a.r, a.ct+v.spin(-o)*a.r};
    }
    return {};
  }
  T intersectArea(C c) { C a = *this, b = c;
    if (a.r > b.r) swap(a, b); T d = a.ct.dist(b.ct);
    if (sign(d-a.r-b.r) >= 0) return 0;
    if (sign(d+a.r-b.r) <= 0) return sq(a.r)*acos(-1);
    T p = acos((sq(a.r)+sq(d)-sq(b.r)) / (2*a.r*d));
    T q = acos((sq(b.r)+sq(d)-sq(a.r)) / (2*b.r*d));
    return p * sq(a.r) - sq(a.r) * sin(p) * cos(p)
         + q * sq(b.r) - sq(b.r) * sin(q) * cos(q);
  }
  vector<L> innerTangent(C c) { C a = *this, b = c;
    if (a.r > b.r) swap(a, b); T d = a.ct.dist(b.ct);
    if (sign(a.r + b.r - d) > 0) return {};
    T o = acos((a.r+b.r)/d); V v = (b.ct-a.ct).unit();
    if (!sign(o)) return {
      L(a.ct + v*a.r, a.ct + v*a.r + v.spin(PI/2))
    };
    P pa1=a.ct+v.spin( o)*a.r,pb1=b.ct-v.spin( o)*b.r;
    P pa2=a.ct+v.spin(-o)*a.r,pb2=b.ct-v.spin(-o)*b.r;
    return {L(pa1, pb1), L(pa2, pb2)};
  }
  vector<L> outerTangent(C c) { C a = *this, b = c;
    if (a.r > b.r) swap(a, b); T d = a.ct.dist(b.ct);
    if (sign(b.r - a.r - d) > 0) return {};
    T o = acos((b.r-a.r)/d); V v = (a.ct-b.ct).unit();
    if (!sign(o)) return {
      L(a.ct + v*a.r, a.ct + v*a.r + v.spin(PI/2))
    };
    return {
      L(a.ct + v.spin( o)*a.r, b.ct + v.spin( o)*b.r),
      L(a.ct + v.spin(-o)*a.r, b.ct + v.spin(-o)*b.r)
    };
  }
};
C TriangleCircumCircle(P a, P b, P c) {
  T a1 = atan2(b.y - a.y, b.x - a.x) + PI / 2;
  T a2 = atan2(c.y - b.y, c.x - b.x) + PI / 2;
  T ax = (a.x + b.x) / 2, ay = (a.y + b.y) / 2;
  T bx = (c.x + b.x) / 2, by = (c.y + b.y) / 2;
  T r1 = (sin(a2) * (ax - bx) + cos(a2) * (by - ay)) 
       / (sin(a1) * cos(a2) - sin(a2) * cos(a1));
  P ct(ax + r1 * cos(a1), ay + r1 * sin(a1));
  return C(ct, a.dist(ct));
}
C TriangleInnerCircle(P a, P b, P c) {
  T la = b.dist(c), lb = a.dist(c), lc = a.dist(b);
  P ct(
    (la * a.x + lb * b.x + lc * c.x) / (la + lb + lc),
    (la * a.y + lb * b.y + lc * c.y) / (la + lb + lc)
  );
  return C(ct, L(a, b).dist(ct));
}

struct Polygon { vector<P> ps;
  Polygon(vector<P> ps = {}) : ps(ps) {}
  /* 0: in, 1: on, 2: out */
  int with(P p) { int c = 0;
    for (int i = 0 ; i < ps.size() ; i++) {
      P a = ps[i], b = ps[(i + 1) % ps.size()];
      S s(a, b); L l(a, b); P q = l.project(p);
      if (!sign(p.dist(q))&&s.isIntersect(q)) return 1;
      if (!sign(a.y - b.y)&&!sign(a.y - p.y)) continue;
      if (sign(a.y - b.y) > 0) swap(a, b);
      c += sign(a.y-p.y) <= 0 && sign(p.y-b.y) < 0 && 
      sign(p.x-(a.x+(b.x-a.x)/(b.y-a.y)*(p.y-a.y)))<=0;
    }
    return (c & 1) * 2;
  }
};
struct Convex { vector<P> ps;
  Convex(vector<P> ps) : ps(CH(ps)) {}
  vector<P> CH(vector<P> ps) { vector<P> ret, stk;
    sort(ps.begin(), ps.end());
    stk = _CH(ps); stk.pop_back();
    for (auto &p : stk) ret.push_back(p);
    reverse(ps.begin(), ps.end());
    stk = _CH(ps); stk.pop_back();
    for (auto &p : stk) ret.push_back(p);
    return ret;
  }
  vector<P> _CH(vector<P> &ps) { vector<P> stk;
    for (auto &p : ps) {
      while (stk.size() >= 2 && sign(
        (stk[stk.size() - 2] - p) % (stk.back() - p)
      ) <= 0) stk.pop_back(); stk.push_back(p);
    }
    return stk;
  }

  T A(P a, P b, P c) { return abs((b - a) % (c - a)); }
  bool inConvex(P p) {
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
         + A(p, ps[L], ps[R]) <= A(ps[0],ps[L],ps[R]);
  }
};
