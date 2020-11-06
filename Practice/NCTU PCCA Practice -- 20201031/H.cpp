#include <bits/stdc++.h>
#define sq(x) (x) * (x)
using namespace std;
typedef long long LL;
using T = double;
const T EPS = 1e-8;
const T PI = acos(-1.0);

int sign(T c) { return c + EPS < 0 ? -1 : abs(c) > EPS; }

typedef struct P {
    T x, y; P(T x = 0, T y = 0) : x(x), y(y) {}
    P operator + (P p) { return P(x + p.x, y + p.y); }
    P operator - (P p) { return P(x - p.x, y - p.y); }
    P operator * (T c) { return P(x * c, y * c); }
    P operator / (T c) { return P(x / c, y / c); }
    T operator * (P p) { return x * p.x + y * p.y; }
    T operator % (P p) { return x * p.y - y * p.x; }
    T leng() { return hypot(x, y); }
    P unit() { return *this / leng(); }
    T dist(P p) { return (*this - p).leng(); }
    P spin(T o) {
        T c = cos(o), s = sin(o);
        return P(c * x - s * y, s * x + c * y);
    }
    bool operator == (P p) {
        return sign(p.x - x) == 0 && sign(p.y - y) == 0;
    }
} V;
struct L {
    P p1, p2; T a, b, c, o;
    L (P p1, P p2) : p1(p1), p2(p2),
        a(p1.y - p2.y), b(p2.x - p1.x), c(p1 % p2),
        o(atan2(-a, b)) {}
    P project(P p) {
        T c = (p2 - p1).unit() * (p - p1);
        return p1 + (p2 - p1).unit() * c;
    }
    T dist(P p) {
        V v1 = p - p1, v2 = p2 - p1;
        return abs(v1 % v2) / v2.leng();
    }
    P intersect(L l) {
        T bc = b * l.c - c * l.b, ac = a * l.c - c * l.a;
        return P(bc, -ac) / (a * l.b - b * l.a);
    }
};
struct Cir { P ct; T r;
    Cir(P ct = P(), T r = 0) : ct(ct), r(r) {}
    vector<P> intersect(L l) {
        if (sign(l.dist(ct) - r) > 0) return {};
        P x = l.project(ct);
        if (sign(l.dist(ct) - r) == 0) return {x};
        T len = sqrt(sq(r) - sq((ct - x).leng()));
        P p1 = x + (l.p1 - x).unit() * len;
        P p2 = x - (l.p1 - x).unit() * len;
        return {p1, p2};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    P A, B, C;
    cin >> B.x >> C.x >> C.y;
    double a = B.dist(C);
    double b = A.dist(C);
    double c = A.dist(B);
    P I = A + (B - A) * (b / (a + b));
    P J = A + (C - A) * (c / (a + c));
    P K = B + (C - B) * (c / (b + c));

    P ABmid = (A + B) / 2;
    L l1(ABmid + (A - B).spin(PI / 2), ABmid);
    P ACmid = (A + C) / 2;
    L l2(ACmid + (A - C).spin(PI / 2), ACmid);
    P G = l1.intersect(l2);
    
    Cir cir(G, A.dist(G));
    P p, n, m;
    {
        vector<P> ps = cir.intersect(L(C, I));
        assert(ps.size() == 2);
        if (ps[0] == C) {
            p = ps[1];
            assert(ps[0] == C);
        } else {
            p = ps[0];
            assert(ps[1] == C);
        }
    }


    {
        vector<P> ps = cir.intersect(L(A, K));
        assert(ps.size() == 2);
        if (ps[0] == A) {
            m = ps[1];
            assert(A == ps[0]);
        } else {
            m = ps[0];
            assert(A == ps[1]);
        }
    }


    {
        vector<P> ps = cir.intersect(L(B, J));
        assert(ps.size() == 2);
        if (ps[0] == B) {
            n = ps[1];
            assert(ps[0] == B);
        } else {
            n = ps[0];
            assert(ps[1] == B);
        }
    }

    P e = L(A, B).intersect(L(n, p));
    P f = L(n, p).intersect(L(A, C));
    P g = L(A, C).intersect(L(n, m));
    P h = L(n, m).intersect(L(B, C));
    P j = L(B, C).intersect(L(m, p));
    P k = L(m, p).intersect(L(A, B));
    cout << fixed << setprecision(15) << e.dist(f) << ' ' << f.dist(g) << ' ';
    cout << fixed << setprecision(15) << g.dist(h) << ' ' << h.dist(j) << ' ';
    cout << fixed << setprecision(15) << j.dist(k) << ' ' << k.dist(e) << '\n';
}
