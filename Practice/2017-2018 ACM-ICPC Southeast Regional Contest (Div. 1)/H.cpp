#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, pair<int, int> > edge;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int s, t; cin >> s >> t; s--, t--;
    vector<vector<edge> > G(n);
    vector<int> pool;
    while (m--) {
        int u, v, l, r; cin >> u >> v >> l >> r;
        u--, v--, r++;
        pool.push_back(l);
        pool.push_back(r);
        G[u].push_back({v, {l, r}});
    }
    pool.push_back(1); pool.push_back(k + 1);
    sort(pool.begin(), pool.end());
    pool.erase(unique(pool.begin(), pool.end()), pool.end());
    int ans = 0;
    for (int i = 1 ; i < pool.size() ; i++) {
        int l = pool[i - 1], r = pool[i];
        vector<bool> vis(n, false); vis[s] = true;
        queue<int> q; q.push(s); while (q.size()) {
            int p = q.front(); q.pop();
            for (auto &e : G[p]) {
                if (e.S.F > l || r > e.S.S)
                    continue;
                if (vis[e.F])
                    continue;
                vis[e.F] = true;
                q.push(e.F);
            }
        }
        if (vis[t])
            ans += r - l;
    }
    cout << ans << '\n';
    
}
