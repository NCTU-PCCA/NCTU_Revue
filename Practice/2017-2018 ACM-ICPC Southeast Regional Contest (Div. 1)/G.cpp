#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> pii;
#define F first
#define S second
void dfs(vector<vector<pii> > &G, int u, int p, vector<int> &d) {
    d[u] = false;
    for (auto &e : G[u]) {
        if (e.F.F == p)
            continue;
        if (!e.F.S)
            continue;
        e.F.S = 0;
        dfs(G, e.F.F, u, d);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<pii> > G(n);
    for (int i = 0 ; i < n - 1 ; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({{v, 1}, c});
        G[v].push_back({{u, 1}, c});
    }
    vector<int> d(n, 1);
    for (int i = 0 ; i < n ; i++) {
        unordered_map<int, vector<pair<int, int> > > c;
        for (auto &e : G[i])
            c[e.S].push_back(e.F);
        for (auto &p : c) {
            if (p.S.size() >= 2) {
                for (auto &e : p.S) {
                    if (!e.S)
                        continue;
                    e.S = 0;
                    dfs(G, e.F, i, d);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
        ans += d[i];
    cout << ans << '\n';
    for (int i = 0 ; i < n ; i++)
        if (d[i])
            cout << i + 1 << '\n';
}
