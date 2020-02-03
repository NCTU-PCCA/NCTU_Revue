#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
using T = LL;
#define O operator
#define CP (const P &p) const
typedef struct P {
    T x, y; int idx;
    P(T x = 0, T y = 0) : x(x), y(y) {}
    P O+CP { return P(x + p.x, y + p.y); }
    P O-CP { return P(x - p.x, y - p.y); }
    T O*CP { return x * p.x + y * p.y; }
    T O%CP { return x * p.y - y * p.x; }
    bool O<CP { return (x < p.x) || ((x == p.x) && (y < p.y)); }
}V;
T cross(const P &o, const P &a, const P &b) {
    return (a - o) % (b - o);
}
vector<P> CH(vector<P> &ps, set<int> &I) {
    sort(ps.begin(), ps.end());
    vector<P> stk, ret;
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    stk.pop_back();
    for (auto &p : stk) ret.push_back(p), I.insert(p.idx);
    reverse(ps.begin(), ps.end());
    stk.clear();
    for (auto &p : ps) {
        while (stk.size() >= 2 && cross(stk[stk.size() - 2], stk.back(), p) <= 0)
            stk.pop_back();
        stk.push_back(p);
    }
    stk.pop_back();
    for (auto &p : stk) ret.push_back(p), I.insert(p.idx);
    return ret;
}
LL A(P a, P b, P c) {
    return abs((b - a) % (c - a));
}
LL unA(P a, P b, P c) {
    return (b - a) % (c - a);
}
LL calc(vector<P> &ps) {
    LL ret = 0;
    for (int i = 0 ; i < ps.size() ; i++) {
        ret += unA(P{0, 0}, ps[i], ps[(i + 1) % ps.size()]);
    }
    return abs(ret);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<P> ps(n);
        int cnt = 0;
        for (auto &p : ps)
            cin >> p.x >> p.y, p.idx = cnt++;
        set<int> pool;
        vector<P> con = CH(ps, pool);
        if (con.size() == 1)
            cout << 0 << '\n';
        else if (con.size() == 2)
            cout << 0 << '\n';
        else if (con.size() == 3) {
            LL ans = 0;
            for (int i = 0 ; i < n ; i++) {
                if (pool.count(ps[i].idx))
                    continue;
                for (int j = 0 ; j < 3 ; j++) {
                    vector<P> tar;
                    for (int k = 0 ; k < 3 ; k++) {
                        tar.push_back(con[k]);
                        if (j == k)
                            tar.push_back(ps[i]);
                    }
                    ans = max(ans, calc(tar));
                }
            }
            if (ans % 2)
                cout << ans / 2 << ".5" << '\n';
            else
                cout << ans / 2 << '\n';
        } else {
            LL ans = 0;
            for (int i = 0 ; i < con.size() ; i++) {
                int l = (i + 1) % con.size(), r = (i + 3) % con.size();
                for (int j = (i + 2) % con.size() ; (j + 1) % con.size() != i ; j++, j %= con.size()) {
                    while (A(con[i], con[j], con[(l + 1) % con.size()]) > A(con[i], con[j], con[l]))
                        l++, l %= con.size();
                    while (A(con[i], con[j], con[(r + 1) % con.size()]) > A(con[i], con[j], con[r]))
                        r++, r %= con.size();
                    ans = max(ans, A(con[i], con[j], con[l]) + A(con[i], con[j], con[r]));
                }
            }
            if (ans % 2)
                cout << ans / 2 << ".5" << '\n';
            else
                cout << ans / 2 << '\n';
        }
    }
}
