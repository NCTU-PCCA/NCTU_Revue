#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, h, m; cin >> n >> h >> m;
    vector<int> level(n, INF);
    queue<int> q;
    for (int i = 0 ; i < h ; i++) {
        int v; cin >> v;
        q.push(v); level[v] = 0;
    }
    vector<vector<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (level[v] != INF)
                continue;
            level[v] = level[p] + 1;
            q.push(v);
        }
    }
    int maxV = 0, maxIdx = -1;
    for (int i = 0 ; i < n ; i++) {
        if (maxV < level[i]) {
            maxV = level[i];
            maxIdx = i;
        }
    }
    cout << maxIdx << '\n';
}
