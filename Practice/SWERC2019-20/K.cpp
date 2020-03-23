#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    vector<vector<int> > G(n);
    vector<int> can;
    queue<pii> q;
    while (m--) {
        int u, v; cin >> u >> v;
        if (v == s) {
            q.push({u, u});
            can.push_back(u);
            continue;
        }
        G[v].push_back(u);
    }
    vector<vector<int> > vis(n);
    while (q.size()) {
        pii p = q.front(); q.pop();
        for (auto &v : G[p.F]) {
            if (vis[v].size() == 2)
                continue;
            if (vis[v].size() == 1 && vis[v][0] == p.S)
                continue;
            vis[v].push_back(p.S);
            q.push({v, p.S});
        }
    }
    sort(can.begin(), can.end());
    vector<int> ans;
    for (auto &v : can) {
        if (!vis[v].size())
            ans.push_back(v);
        else if (vis[v].size() == 1 && vis[v][0] == v)
            ans.push_back(v);
    }
    cout << ans.size() << '\n';
    for (auto &v : ans)
        cout << v << '\n';
}
