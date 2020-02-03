#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
#define O operator
#define CP (const P &p) const
using namespace std;
typedef long long LL;
struct S {
    LL F, S, T;
};
typedef struct P {
    LL x, y;
    P(LL x = 0, LL y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    LL O*CP { return x * p.x + y * p.y; }
    LL O%CP { return x * p.y - y * p.x; }
    LL O<CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
    P O*(const LL c) const { return P(x * c, y * c); }
    P O/(const LL c) const { return P(x / c, y / c); }
}V;
LL cross(const P &o, const P &a, const P &b) {
    return (a - o) % (b - o);
}
vector<P> CH(vector<P> &ps) {
    sort(ps.begin(), ps.end());
    vector<P> stk, ret;
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) >= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    for (auto &p : stk) ret.push_back(p);
    return ret;
}
P solve(vector<P> &ps) {
    ps.push_back(P{ps.back().x, 0});
    reverse(ps.begin(), ps.end());
    ps.push_back(P{ps.back().x, 0});
    reverse(ps.begin(), ps.end());
//    for (auto &p : ps)
//        cout << "(" << p.x << ' ' << p.y << ")\n";
    int p1;
    for (int i = 0 ; i < ps.size() - 1 ; i++) {
        if (ps[i + 1].x - ps[i].x >= ps[i + 1].y - ps[i].y) {
            p1 = i;
            break;
        }
    }
    for (auto &p : ps)
        p.x = -p.x;
    reverse(ps.begin(), ps.end());
    int p2;
    for (int i = 0 ; i < ps.size() - 1 ; i++) {
        if (ps[i + 1].x - ps[i].x >= ps[i + 1].y - ps[i].y) {
            p2 = i;
            break;
        }
    }
    for (auto &p : ps)
        p.x = -p.x;
    reverse(ps.begin(), ps.end());
    p2 = (ps.size() - 1) - p2;
    if (ps[p2] < ps[p1])
        swap(p1, p2);
//    cout << "p1: (" << ps[p1].x << "," << ps[p1].y << ")\n";
//    cout << "p2: (" << ps[p2].x << "," << ps[p2].y << ")\n";
    LL y = -ps[p1].x + ps[p1].y + ps[p2].x + ps[p2].y;
    LL x =  ps[p1].x - ps[p1].y + ps[p2].x + ps[p2].y;
    if (abs(x) % 2)
        x--, y++;
    return {x / 2, y / 2};
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<S> data(n);
    vector<P> _X, _Y;
    for (auto &s : data) {
        cin >> s.F >> s.S >> s.T;
        _X.push_back({s.F, s.T});
        _Y.push_back({s.S, s.T});
    }
    vector<P> X = CH(_X);
    P x = solve(X);
    vector<P> Y = CH(_Y);
    P y = solve(Y);
    cout << x.x << ' ' << y.x << ' ' << max(x.y, y.y) << '\n';
}
