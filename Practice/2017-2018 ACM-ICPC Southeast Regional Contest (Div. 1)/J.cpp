#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1005;
vector<int> G[MAXN * MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pii> V(n);
    vector<int> d(MAXN * MAXN);
    for (int i = 0 ; i < n ; i++) {
        cin >> V[i].F >> V[i].S;
        for (int j = 0 ; j < MAXN ; j++)
            d[j * MAXN + i] = max(0, V[i].F - j * V[i].S);
    }
    vector<int> deg(MAXN * MAXN);
    while (m--) {
        int u, v, d; cin >> u >> v >> d; u--, v--;
        for (int i = 0 ; i + d < MAXN ; i++) {
            G[(i + d) * MAXN + v].push_back(i * MAXN + u);
            G[(i + d) * MAXN + u].push_back(i * MAXN + v);
            deg[i * MAXN + u]++;
            deg[i * MAXN + v]++;
        }
    }
    queue<int> q;
    for (int i = 0 ; i < MAXN * MAXN ; i++)
        if (!deg[i])
            q.push(i);
    vector<int> dp(MAXN * MAXN, 0);
    while (q.size()) {
        int p = q.front(); q.pop();
        dp[p] += d[p];
        for (auto &v : G[p]) {
            dp[v] = max(dp[v], dp[p]);
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }
    cout << dp[0] << '\n';
}
