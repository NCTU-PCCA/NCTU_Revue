#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
void dfs(int u, int p, vector<vector<int> > &G, vector<int> &sz) {
    for (auto &v : G[u]) {
        if (v == p)
            continue;
        dfs(v, u, G, sz);
        sz[u] += sz[v];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<set<int> > data(n);
    vector<int> SZ;
    for (int i = 0 ; i < n ; i++) {
        int m; cin >> m; SZ.push_back(m + 1);
        while (m--) {
            int v; cin >> v; v--;
            data[i].insert(v);
        }
    }
    queue<int> q;
    vector<bool> ok(n, false);
    for (int i = 0 ; i < n ; i++) {
        if (!data[i].size()) {
            q.push(i), ok[i] = true;
        }
    }
    vector<pii> ans;
    int rt = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        int minV = INF, minIdx = -1;
        for (int i = 0 ; i < n ; i++) {
            if (ok[i] || !data[i].count(p))
                continue;
            data[i].erase(p);
            if (data[i].size() < minV)
                minV = data[i].size(),
                minIdx = i;
            if (!data[i].size())
                q.push(i), ok[i] = true;
        }
        if (minIdx == -1) {
            rt = p;
            continue;
        }
        ans.push_back({minIdx + 1, p + 1});
    }
    if (ans.size() != n - 1)
        cout << "NO\n";
    else {
        vector<vector<int> > G(n);
        for (auto &p : ans)
            G[p.F - 1].push_back(p.S - 1),
            G[p.S - 1].push_back(p.F - 1);
        vector<int> sz(n, 1);
        dfs(rt, rt, G, sz);
        bool legal = true;
        for (int i = 0 ; i < n ; i++)
            if (sz[i] != SZ[i])
                legal = false;
        if (legal) {
            cout << "YES\n";
            for (auto &p : ans)
                cout << p.F << ' ' << p.S << '\n';
        } else 
            cout << "NO\n";
    }
}
