#include <bits/stdc++.h>
using namespace std;
using T = double;
const T EPS = 1e-8;
#define O operator
#define CP (const P &p) const
typedef struct P { T x, y;
    P (T x = 0, T y = 0) : x(x), y(y) {}
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
} V;
struct S { P p1, p2; S () {}
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
void solve() {
    int L, W; cin >> L >> W;
    vector<P> p;
    for (int i = 0 ; i <= L ; i++) {
        p.push_back(P{i, 0}),
        p.push_back(P{i, W});
    }
    for (int i = 1 ; i <= W - 1 ; i++) {
        p.push_back(P{0, i});
        p.push_back(P{L, i});
    }
    vector<S> rect;
    P c; T w;
    cin >> c.x >> c.y >> w;
    rect.push_back(S{P{c.x, c.y}, P{c.x, c.y + w}});
    rect.push_back(S{P{c.x, c.y}, P{c.x + w, c.y}});
    rect.push_back(S{P{c.x + w, c.y + w}, P{c.x + w, c.y}});
    rect.push_back(S{P{c.x + w, c.y + w}, P{c.x, c.y + w}});
    int cnt = 0;
    for (int i = 0 ; i < p.size() ; i++) {
        for (int j = i + 1 ; j < p.size() ; j++) {
            for (int k = j + 1 ; k < p.size() ; k++) {
                if (p[i].x == p[j].x && p[j].x == p[k].x)
                    continue;
                if (p[i].y == p[j].y && p[j].y == p[k].y)
                    continue;
                vector<S> tar;
                tar.push_back(S{p[i], p[j]});
                tar.push_back(S{p[j], p[k]});
                tar.push_back(S{p[k], p[i]});
                bool ok = true;
                for (int x = 0 ; x < tar.size() ; x++) {
                    for (int y = 0 ; y < rect.size() ; y++) {
                        if (intersect(tar[x], rect[y]))
                            ok = false;
                    }
                }
                cnt += ok;
            }
        }
    }
    cout << cnt << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }

}
