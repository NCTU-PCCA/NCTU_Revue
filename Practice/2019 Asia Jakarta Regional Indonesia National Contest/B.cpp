#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef long long ll;
typedef pair<LL, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL h; cin >> n >> h;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    vector<vector<pii> > list(n);
    LL sum = 0;
    for (int i = 0 ; i < n ; i++) {
        list[i].push_back({0, 0});
        LL power = data[i].F;
        LL value = data[i].S;
        while (value) {
            LL cost = (value - 1) / 2 + 1;
            list[i].push_back({list[i].back().F + power, list[i].back().S + cost});
            value /= 2;
            power *= 2;
        }
        sum += list[i].back().S;
    }
    vector<vector<LL> > dp(n + 1, vector<LL>(sum + 1, 0));
//     dp[i][j] := value: j   => max power
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= sum ; j++) {
            for (int k = list[i].size() - 1 ; k >= 0 ; k--) {
                if (j - list[i][k].S < 0)
                    continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - list[i][k].S] + list[i][k].F);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= sum ; i++) {
        ans = i;
        if (dp[n][i] >= h)
            break;
    }
    if (dp[n][sum] < h)
        cout << -1 << '\n';
    else
        cout << ans  << '\n';
}
