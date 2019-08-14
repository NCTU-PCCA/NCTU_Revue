#include <bits/stdc++.h>
using namespace std;
void bfs(int i, vector<vector<int> > &G, vector<int> &vis, vector<int> &ans) {
    queue<int> q; q.push(i); vis[i] = 0;
    vector<int> data[2];
    while (q.size()) {
        int p = q.front(); q.pop();
        data[vis[p]].push_back(p);
        for (auto &v : G[p]) {
            if (~vis[v])
                continue;
            vis[v] = vis[p] ^ 1;
            q.push(v);
        }
    }
    for (auto &v : data[data[1].size() < data[0].size()])
        ans.push_back(v);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> pos(n);
    vector<set<int> > with(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> pos[i];
        int m; cin >> m; while (m--) {
            int v; cin >> v; v--;
            with[i].insert(v);
        }
        with[i].insert(i);
    }
    vector<vector<int> > G(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (pos[i] == pos[j])
                continue;
            bool ok = true;
            for (auto &v : with[i])
                if (with[j].count(v))
                    ok = false;
            if (!ok)
                G[i].push_back(j), G[j].push_back(i);
        }
    }
    vector<int> vis(n, -1), ans;
    for (int i = 0 ; i < n ; i++) {
        if (~vis[i])
            continue;
        bfs(i, G, vis, ans);
    }
    if ((int)ans.size() == 0) {
        cout << 1 << '\n' << 1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for (auto &v : ans)
            cout << v + 1 << '\n';
    }
}
