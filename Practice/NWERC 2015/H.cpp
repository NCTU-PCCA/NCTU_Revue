#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
using T = long double;
const T EPS = 1e-6;
const T pi = acos(-1.0);
#define O operator
#define CP (const P &p) const
typedef struct P { T x, y;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    P O*(const T c) const { return P(x * c, y * c); }
    P O/(const T c) const { return P(x / c, y / c); }
    bool O==CP { return abs(x - p.x) < EPS && abs(y - p.y) < EPS; }
} V;
T leng2(V a) { return a * a; }
T dist2(P a, P b) { return leng2(a - b); }
struct S { P p1, p2; S() {}
    S(P p1, P p2) : p1(p1), p2(p2) {}
};
T btw(P p, S s) { return (s.p1 - p) * (s.p2 - p); }
T dir(P p, S s) { return (s.p2 - s.p1) % (p - s.p1); }
bool intersect(P p, S s) {
    return abs(dir(p, s)) < EPS && btw(p, s) <= EPS;
}
bool intersect(S s1, S s2) {
    T c1 = dir(s2.p1, s1), c2 = dir(s2.p2, s1);
    T c3 = dir(s1.p1, s2), c4 = dir(s1.p2, s2);
    if (c1 * c2 < -EPS && c3 * c4 < -EPS) return true;
    if (abs(c1) < EPS && intersect(s2.p1, s1)) return true;
    if (abs(c2) < EPS && intersect(s2.p2, s1)) return true;
    if (abs(c3) < EPS && intersect(s1.p1, s2)) return true;
    if (abs(c4) < EPS && intersect(s1.p2, s2)) return true;
    return false;
}
P intersection(S s1, S s2) {
    P p1 = s1.p1, p2 = s1.p2, q1 = s2.p1, q2 = s2.p2;
    T tmpxLeft = (q2.x - q1.x) * (p1.y - p2.y) - (p2.x - p1.x) * (q1.y - q2.y);
    T tmpxRight = (p1.y - q1.y) * (p2.x - p1.x) * (q2.x - q1.x) + q1.x * (q2.y - q1.y) * (p2.x - p1.x) - p1.x * (p2.y - p1.y) * (q2.x - q1.x);
    T tmpyLeft = (p1.x - p2.x) * (q2.y - q1.y) - (p2.y - p1.y) * (q1.x - q2.x);
    T tmpyRight = p2.y * (p1.x - p2.x) * (q2.y - q1.y) + (q2.x- p2.x) * (q2.y - q1.y) * (p1.y - p2.y) - q2.y * (q1.x - q2.x) * (p2.y - p1.y);
    return P(tmpxRight / tmpxLeft, tmpyRight / tmpyLeft);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    P t; cin >> t.x >> t.y;
    vector<S> seg(n);
    for (auto &st : seg)
        cin >> st.p1.x >> st.p1.y >> st.p2.x >> st.p2.y;
    int ans = 0;
    for (long double x = 0 ; x < 2 * pi ; x += 2 * pi / 100000.) {
        P s{0, 0};
        int vis[n] = {}, cnt = 0;
        long double theta = x;
        if (abs(theta - atan(1.0 / 3)) < 0.00003)
            cout << theta << '\n';
        theta = 0.321762;
        while (cnt < n) {
            int idx = -1; long double dist = 1e30;
            S cur_seg = S{s, s + P(cos(theta), sin(theta)) * 4000};
            for (int i = 0 ; i < n ; i++) {
                if (vis[i])
                    continue;
                if (!intersect(seg[i], cur_seg))
                    continue;
                P p = intersection(seg[i], cur_seg);
                if (dist2(p, s) < dist)
                    dist = dist2(p, s), idx = i;
            }
            if (idx == -1) {
                if (intersect(t, cur_seg))
                    ans = max(ans, cnt);
                break;
            }
            if (intersect(t, cur_seg)) {
                if (dist2(s, t) < dist)
                    ans = max(ans, cnt);
            }
            if (seg[idx].p1.x == seg[idx].p2.x) {
                // vertical
                theta = pi - theta;
            } else if (seg[idx].p1.y == seg[idx].p2.y) {
                // horizon
                theta = -theta;
            }
            vis[idx] = 1; cnt++; s = intersection(seg[idx], cur_seg);
        }
        S cur_seg = S{s, s + P(cos(theta), sin(theta)) * 2000};
        if (intersect(t, cur_seg))
            ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
