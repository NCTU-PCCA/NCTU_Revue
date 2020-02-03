#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
vector<int> bfs(vector<vector<int> > &G, int s) {
    queue<int> q; q.push(s);
    vector<int> d(G.size(), -1);
    d[s] = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (~d[v])
                continue;
            d[v] = d[p] + 1;
            q.push(v);
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        int m; cin >> m;
        vector<vector<int> > G(n);
        while (m--) {
            int u, v; cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> d;
        d = bfs(G, 0);
        int maxV = 0, maxIdx = -1;
        for (int i = 0 ; i < n ; i++)
            if (maxV < d[i])
                maxV = d[i], maxIdx = i;
        int cur = maxIdx;
        vector<int> ans(n, -1);
        int l = 0, r = n - 1, state = 0;
        do {
            if (state == 0) {
                ans[cur] = l++;
            } else {
                ans[cur] = r--;
            }
            int nxt = -1;
            for (auto &v : G[cur]) {
                if (~ans[v])
                    continue;
                if (G[v].size() > 1)
                    nxt = v;
                else {
                    if (state == 0)
                        ans[v] = r--;
                    else
                        ans[v] = l++;
                }
            }
            cur = nxt;
            state ^= 1;
        } while (cur != -1);
        for (int i = 0 ; i < n ; i++)
            cout << ans[i] << " \n"[i + 1 == n];
    }
}
