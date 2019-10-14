#include <bits/stdc++.h>
#define O operator
#define CP (const P &p) const
using namespace std;
using T = double;
const double EPS = 1e-8;
typedef struct P {
    T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    P O*(const T c) const { return P(x * c, y * c); }
    P O/(const T c) const { return P(x / c, y / c); }
}V;
T leng2(V a) { return a * a; }
T leng(V a)  { return sqrt(leng2(a)); }
T dist2(P a, P b) { return leng2(a - b); }
T dist(P a, P b)  { return sqrt(dist2(a, b)); }
struct S {
    P p1, p2; S() {}
    S(P p1, P p2) : p1(p1), p2(p2) {}
};
T dist(P p, S s) {
    V v = s.p2 - s.p1, v1 = p - s.p1, v2 = p - s.p2;
    if (v * v1 < -EPS) return leng(v1);
    if (v * v2 > EPS)  return leng(v2);
    return abs(v1 % v2) / leng(v);
}
const double INF = 1e30;
double getLen(double h, double x) {
    return sqrt(h * h - x * x);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    P s, t; cin >> s.x >> s.y >> t.x >> t.y;
    P bc, sc; double br, sr;
    cin >> bc.x >> bc.y >> br;
    cin >> sc.x >> sc.y >> sr;
    if (dist(sc, S{s, t}) >= sr + EPS) {
        cout << fixed << setprecision(10) << dist(s, t) << '\n';
    } else {
        double s2c = dist(sc, s);
        double c2t = dist(sc, t);
        double s2t = dist(s, t);
        double ans = getLen(s2c, sr) + getLen(c2t, sr);
        double bigA = acos((s2c * s2c + c2t * c2t - s2t * s2t) / (2 * s2c * c2t));
        cout << fixed << setprecision(10) << ans + (bigA - acos(sr / s2c) - acos(sr / c2t)) * sr << '\n';
    }
}
