#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > G(2 * n);
    vector<int> deg(2 * n);
    map<pair<int, int>, int> app;
    int cnt = 0, tmp_m = m;
    for (int i = 0 ; i < tmp_m ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        v += n;
        if (!app.count({u, v})) {
            G[u].push_back(v);
            G[v].push_back(u);
            deg[v]++;
            deg[u]++;
        } else {
            if (app[{u, v}] == 1)
                cnt++;
            m--;
        }
        app[{u, v}]++;
    }
    queue<int> q;
    for (int i = 0 ; i < 2 * n ; i++) {
        if (deg[i] == 1)
            q.push(i), deg[i]--;
    }
    set<int> pool;
    while (q.size()) {
        int p = q.front(); q.pop();
        pool.insert(p);
        for (auto &v : G[p]) {
            if (deg[v] == 0)
                continue;
            deg[v]--;
            if (deg[v] == 1)
                q.push(v);
        }
    }
    cout << m - pool.size() / 2 + cnt << '\n';
}
