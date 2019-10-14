#include <bits/stdc++.h>
using namespace std;
#define O operator
#define CP (const P &p) const
typedef long long LL;
using T = LL;
struct P {
    T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    bool O < CP { return (x < p.x) || (x == p.x && y < p.y); }
    P O*(const T c) const { return P(x * c, y * c); }
    P O/(const T c) const { return P(x / c, y / c); }
};
T leng2(P a) { return a * a; }
T dist2(P a, P b) { return leng2(a - b); }
T cross(const P &o, const P &a, const P &b) {
    return (a - o) % (b - o);
}
vector<P> convexHull(vector<P> &ps) {
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
    for (auto &p : stk) ret.push_back(p);
    ret.pop_back();
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int L; cin >> L;
    vector<P> Ls(L);
    for (auto &p : Ls)
        cin >> p.x >> p.y;
    vector<P> ps = convexHull(Ls);
    int M; cin >> M; int cnt = 0;
    while (M--) {
        P p; cin >> p.x >> p.y;
        LL dir = 0, undir = 0;
        for (int i = 0 ; i < ps.size() ; i++) {
            P a = ps[i], b = ps[(i + 1) % ps.size()];
            dir += (a - p) % (b - p);
            undir += abs((a - p) % (b - p));
        }
        if (dir == undir)
            cnt++;
    }
    cout << cnt << '\n';
}
