#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<double, double> pii;
struct BIT {
    int n; vector<LL> bit;
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    void m(int x, LL d) {
        while (x <= n)
            bit[x] = max(bit[x], d), x += x & (-x);
    }
    LL q(int x) {
        LL ret = 0;
        while (x > 0)
            ret = max(ret, bit[x]), x -= x & (-x);
        return ret;
    }
} bit;
map<double, int> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k; int x; cin >> x >> x;
    vector<pii> arr(n);
    for (int i = 0 ; i < n ; i++) {
        LL x, y; cin >> x >> y;
        arr[i].F = double(   k * x + y) / k;
        arr[i].S = double( - k * x + y) / k;
        mp[arr[i].S];
    }
    sort(arr.begin(), arr.end());
    int st = 0; for (auto &p : mp) p.S = ++st;
    bit.init(st);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int maxV = bit.q(mp[arr[i].S]);
        ans = max(ans, maxV + 1);
        bit.m(mp[arr[i].S], maxV + 1);
    }
    cout << ans << '\n';
}
