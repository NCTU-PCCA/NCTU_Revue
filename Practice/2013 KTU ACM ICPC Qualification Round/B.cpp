#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        vector<pii> data(4);
        for (auto &p : data)
            cin >> p.first >> p.second;
        data.push_back(data[0]);
        LL x; cin >> x;
        LL res = 0;
        for (int i = 0 ; i < 4 ; i++)
            res += data[i].first * data[i + 1].second;
        for (int i = 0 ; i < 4 ; i++)
            res -= data[i].second * data[i + 1].first;
        res = abs(res);
        cout << fixed << setprecision(2) << (LL)((double)x / res * 2.0 * 100 + 0.5) / 100.0 << '\n';
    }
}
