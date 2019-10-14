#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, S, W; cin >> n >> m >> S >> W;
    vector<int> s(S);
    for (auto &v : s)
        cin >> v;
    s.push_back(1); s.push_back(n);
    sort(s.begin(), s.end());
    vector<vector<LL> > G(n, vector<LL>(n, INF));
    for (int i = 0 ; i < n ; i++)
        G[i][i] = 0;
    while (m--) {
        int u, v; LL d; cin >> u >> v >> d;
        u--, v--;
        G[u][v] = G[v][u] = d;
    }
    for (int k = 0 ; k < n ; k++)
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    vector<vector<LL> > ans(n, vector<LL>(n, INF));
    for (int i = 0 ; i < n ; i++)
        ans[i][i] = 0;
    S += 2;
    for (int i = 0 ; i < S ; i++) {
        for (int j = i + 1 ; j < S ; j++) {
            int u = s[i], v = s[j];
            u--, v--;
            if (G[u][v] > W)
                continue;
            ans[u][v] = ans[v][u] = G[u][v];
        }
    }
    for (int k = 0 ; k < n ; k++)
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
    if (ans[0][n - 1] == INF) {
        cout << "stuck\n";
    } else {
        cout << ans[0][n - 1] << '\n';
    }

}
