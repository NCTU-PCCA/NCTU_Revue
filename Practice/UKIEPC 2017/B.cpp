#include <bits/stdc++.h>
using namespace std;
using T = double;
const T EPS = 1e-8;
#define O operator
#define CP (const P &p) const
typedef struct P {
    T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    bool O<CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
} V;
T leng2(V a) { return a * a; }
T leng(V a) { return sqrt(leng2(a)); }
T dist2(P a, P b) { return leng2(a - b); }
T dist(P a, P b) { return sqrt(dist2(a, b)); }
struct L {
    P p1, p2;
    L() {}
    L(P p1, P p2) : p1(p1), p2(p2) {}
};
T dist(P p, L l) {
    V v1 = p - l.p1, v2 = l.p2 - l.p1;
    return abs(v1 % v2) / leng(v2);
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
    for (auto &p : stk)
        ret.push_back(p);
    reverse(ps.begin(), ps.end());
    stk.clear();
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    stk.pop_back();
    for (auto &p : stk)
        ret.push_back(p);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<P> ps(n);
    for (auto &p : ps)
        cin >> p.x >> p.y;
    ps = CH(ps);
    double ans = 1e18;
    for (int i = 0 ; i < ps.size() ; i++) {
        double maxV = 0;
        for (int j = 0 ; j < ps.size() ; j++) {
            maxV = max(maxV, dist(ps[j], L{ps[i], ps[(i + 1) % ps.size()]}));
        }
        ans = min(ans, maxV);
    }
    cout << fixed << setprecision(20) << ans << '\n';
}
