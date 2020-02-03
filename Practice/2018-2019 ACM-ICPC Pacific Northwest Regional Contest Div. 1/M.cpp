#include <bits/stdc++.h>
using namespace std;
using T = double;
const T EPS = 1e-8;
#define O operator
#define CP (const P &p) const
typedef struct P {
    T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O%CP { return x * p.y - y * p.x; }
    P O/(const T c) const { return P(x / c, y / c); }
    bool O<CP { return (x + EPS < p.x) || ((abs(x - p.x) <= EPS) && (y + EPS < p.y)); }
} V;
T cross(const P &o, const P &a, const P &b) {
    return (a - o) % (b - o);
}
vector<P> CH(vector<P> &ps) {
    sort(ps.begin(), ps.end());
    vector<P> stk, ret;
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) + EPS <= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    stk.pop_back();
    for (auto &p : stk) ret.push_back(p);
    reverse(ps.begin(), ps.end()); stk.clear();
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) + EPS <= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    stk.pop_back();
    for (auto &p : stk) ret.push_back(p);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; double c; cin >> n >> c;
    double ans = 0;
    vector<P> data(n);
    for (int i = 0 ; i < n ; i++) {
        double d, h, p; cin >> d >> h >> p;
        data[i].x = h * c / d;
        data[i].y = p * c / d;
        ans = max(ans, data[i].x * data[i].y);
    }
    vector<P> ps = CH(data);
    for (int i = 0 ; i < ps.size() ; i++) {
        // i , (i + 1) % ps.size();
        P L = ps[i], R = ps[(i + 1) % ps.size()];
        for (int j = 0 ; j < 60 ; j++) {
            P M = (L + R) / 2;
            P MM = (L + M) / 2;
            if (MM.x * MM.y < M.x * M.y)
                L = MM;
            else
                R = M;
        }
        ans = max(ans, L.x * L.y);
    }
    cout << fixed << setprecision(2) << ans << '\n';
}
