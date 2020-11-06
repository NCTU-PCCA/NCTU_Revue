#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int>pii;
typedef long long LL;
using T = double;
const T EPS = 1e-10;
const T PI = acos(-1.0);
#define O operator
#define CP (const P &p) const
typedef struct P { T x, y; int idx;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    P O*(const T &c) const { return P(x * c, y * c); }
    P O/(const T &c) const { return P(x / c, y / c); }
    bool O < CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
} V;

T len(V a) {
    return sqrt(a * a);
}
T dist(P a, P b) {
    return len(a - b);
}
struct Cir {
    P c; T r;
    int idx;
};

vector<P> tang(Cir a, Cir b) {
    vector<P> res;
    if (a.r > b.r) swap(a, b);
    V v = a.c - b.c;
    double c;
    if (a.r == b.r)
        c = 0;
    else
        c = (b.r - a.r) / dist(a.c, b.c);
    double s = sqrt(1 - c * c);

    V v1 = P{v.x * c - v.y * s, v.x * s + v.y * c};
    v1 = v1 / len(v1);

    P p1 = a.c + v1 * (a.r / len(v1)); p1.idx = a.idx;
    res.push_back(p1);
    P p2 = b.c + v1 * (b.r / len(v1)); p2.idx = b.idx;
    res.push_back(p2);

    V v2 = P{v.x * c + v.y * s, -v.x * s + v.y * c};
    P p3 = a.c + v2 * (a.r / len(v2)); p3.idx = a.idx;
    res.push_back(p3);
    P p4 = b.c + v2 * (b.r / len(v2)); p4.idx = b.idx;
    res.push_back(p4);
    return res;
}

T cross(const P &o, const P &a, const P &b) {
    return (a - o) % (b - o);
}
vector<P> CH(vector<P> &ps) {
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
void testcase() {
    int n; cin >> n;
    vector<Cir> _Cs(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> _Cs[i].c.x >> _Cs[i].c.y >> _Cs[i].r;
        _Cs[i].idx = i;
    }
    vector<Cir> Cs;
    for (int i = 0 ; i < n ; i++) {
        bool ok = true;
        for (int j = 0 ; j < n ; j++) {
            if (i == j)
                continue;
            double r1 = _Cs[i].r;
            double r2 = _Cs[j].r;
            if (r1 > r2) swap(r1, r2);
            if (dist(_Cs[i].c, _Cs[j].c) + r1 + EPS > r2)
                continue;
            ok = false;
            break;
        }
        if (ok)
            Cs.push_back(_Cs[i]);
    }
    n = Cs.size();
    if (n == 1) {
        cout << fixed << setprecision(20) << 2 * PI * Cs[0].r << '\n';
        return ;
    }
    for (int i = 0 ; i < n ; i++)
        Cs[i].idx = i;
    vector<P> Ps;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            double r1 = Cs[i].r;
            double r2 = Cs[j].r;
            if (r1 > r2) swap(r1, r2);
            if (dist(Cs[i].c, Cs[j].c) + r1 + EPS <= r2)
                continue;
//            cout << "tang point btw " << "(" << Cs[i].c.x << "," << Cs[i].c.y << ")" << " and " << "(" << Cs[j].c.x << "," << Cs[j].c.y << ")" << '\n';
            vector<P> res = tang(Cs[i], Cs[j]);
//            for (auto &p : res)
//                cout << p.x << ' ' << p.y << '\n';
            for (auto &p : res)
                Ps.push_back(p);
        }
    }
    Ps = CH(Ps);
//    for (int i= 0 ; i < Ps.size() ; i++)
//        cout << Ps[i].x << ' ' << Ps[i].y << ' ' << Ps[i].idx << '\n';

    Ps.push_back(Ps[0]);

    T sum = 0;
    for (int i = 1 ; i < Ps.size() ; i++) {
        P x = Ps[i - 1], y = Ps[i];
        if (x.idx == y.idx) {
            double r = Cs[x.idx].r;
            double d = dist(x, y);
            double ct = (2 * r * r - d * d) / (2 * r * r);
            V cx = x - Cs[x.idx].c;
            V cy = y - Cs[x.idx].c;
            double th = acos(ct);
            if (cx % cy < 0) th = 2 * PI - th;
            sum += r * th;
        } else {
            sum += dist(x, y);
        }
    }
//    cout << '\n';
    cout << fixed << setprecision(10) << sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--)
        testcase();
}
