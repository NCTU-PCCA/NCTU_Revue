#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
struct BIT {
    vector<int> bit; int n;
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void m(int x, int d) {
        while (x <= n)
            bit[x] += d, x += x & -x;
    }
    int q(int x) {
        int ret = 0;
        while (x > 0)
            ret += bit[x], x -= x & -x;
        return ret;
    }
};
void solve(vector<pii> &arr, int offset, LL &ans) {
    map<int, int> mp;
    sort(arr.begin(), arr.end());
    for (auto &p : arr)
        mp[p.S];
    int st = 1; for (auto &p : mp) p.S = st++;
    BIT sol; sol.init(st);
    for (auto &p : arr) {
        ans += sol.q(st) - sol.q(mp[p.S]) + offset + 1;
        sol.m(mp[p.S], 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int X, Y; cin >> X >> Y;
    int n, m; cin >> n >> m;
    vector<pii> x(n), y(m);
    for (auto &p : x)
        cin >> p.F >> p.S;
    for (auto &p : y)
        cin >> p.F >> p.S;
    LL ans = 1;
    solve(x, 0, ans);
    solve(y, n, ans);
    cout << ans << '\n';
}
