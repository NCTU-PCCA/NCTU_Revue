#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int A, B, n, m; cin >> A >> B >> n >> m;
    vector<vector<int> > G(n);
    vector<vector<int> > revG(n);
    vector<int> deg(n, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        deg[v]++;
        revG[v].push_back(u);
    }
    vector<int> data(n, 0);
    for (int i = 0 ; i < n ; i++) {
        vector<int> tmp = deg;
        queue<int> q;
        for (int j = 0 ; j < n ; j++)
            if (tmp[j] == 0)
                q.push(j);
        int cnt = 0;
        while (q.size()) {
            int p = q.front(); q.pop();
            cnt++;
            if (p == i)
                continue;
            for (auto &v : G[p]) {
                tmp[v]--;
                if (tmp[v] == 0)
                    q.push(v);
            }
        }
        data[i] = cnt;
    }
    vector<int> dp(n);
    for (int i = 0 ; i < n ; i++) {
        queue<int> q; q.push(i);
        vector<int> vis(n, 0); vis[i] = 1; int cnt = 0;
        while (q.size()) {
            int p  = q.front(); q.pop();
            cnt++;
            for (auto &v : revG[p]) {
                if (vis[v]) continue;
                q.push(v), vis[v] = 1;
            }
        }
        dp[i] = cnt;
    }
    /*
    for (auto &v : dp)
        cout << v << ' ';
    cout << '\n';
    for (auto &v : data)
        cout << v << ' ';
    cout << '\n';
    */
    int ans[3] = {0};
    for (int i = 0 ; i < n ; i++) {
        if (data[i] <= A)
            ans[0]++;
        if (data[i] <= B)
            ans[1]++;
        if (dp[i] > B)
            ans[2]++;
    }
    cout << ans[0] << '\n';
    cout << ans[1] << '\n';
    cout << ans[2] << '\n';
}
