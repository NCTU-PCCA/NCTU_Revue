#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL ans = 0;
    int n; cin >> n; while (n--) {
        vector<pii> ps;
        int m; cin >> m; while (m--) {
            LL x, y; cin >> x >> y;
            ps.push_back({x, y});
        }
        ps.push_back(ps[0]);
        LL sum = 0;
        for (int i = 0 ; i < ps.size() - 1 ; i++)
            sum += ps[i].F * ps[i + 1].S - ps[i].S * ps[i + 1].F;
        ans += abs(sum);
    }
    cout << ans / 2 << '\n';
}
