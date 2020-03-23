#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> data(2 * n);
    for (auto &v : data)
        cin >> v;
    LL sx, sy; cin >> sx;
    vector<pii> P;
    LL y = 0;
    for (int i = 1 ; i < 2 * n ; i += 2) {
        if (data[i - 1] <= sx && sx <= data[i])
            sy = y + (sx - data[i - 1]);
        y += data[i] - data[i - 1];
        P.push_back({data[i], y});
        if (i + 1 == 2 * n)
            data.push_back(data[i] + y);
        if (data[i] <= sx && sx <= data[i + 1])
            sy = y - (sx - data[i]);
        y -= data[i + 1] - data[i];
    }
    LL ans = 0;
    for (auto &p : P) {
        if (p.F >= sx)
            break;
        ans = max(ans, max(0LL, LL(ceil((1.0 * sx * (p.S - sy) / (sx - p.F)) + sy))));
    }
    cout << ans << '\n';
}
