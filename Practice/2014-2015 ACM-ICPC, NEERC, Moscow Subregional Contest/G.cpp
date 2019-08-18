#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<string, string> pss;
map<pss, int> ID;
int getId(pss x) {
    int len = ID.size();
    if (!ID.count(x))
        ID[x] = len;
    return ID[x];
}
void draw(int u, vector<vector<int> > &G, vector<int> &dp, int x) {
    for (int i = 0 ; i < x ; i++) {
        dp[u] = x;
        u = G[u][0];
    }
}
int solve(int u, vector<vector<int> > &G, vector<int> &dp) {
    if (dp[u]) return dp[u];
    if (!G[u].size()) return dp[u] = 1;
    return dp[u] = solve(G[u][0], G, dp) + 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; set<pss> list;
    vector<pair<pss, pss> > edges;
    for (int i = 0 ; i < n ; i++) {
        string a, b, c, d;
        cin >> a >> b >> c >> c >> d;
        getId({a, b});
        if (b == d)
            continue;
        edges.push_back({{a, b}, {a, d}});
    }
    n = ID.size();
    vector<vector<int> > G(n);
    for (auto &e : edges) {
        if (!ID.count(e.S))
            continue;
        G[getId(e.F)].push_back(getId(e.S));
    }
    vector<int> dp(n, 0);
    vector<bool> vis(n, false);
    for (int i = 0 ; i < n ; i++) {
        if (vis[i])
            continue;
        int cur = i, cnt = 0;
        map<int, int> mp;
        while (1) {
            if (mp.count(cur)) {
                draw(cur, G, dp, cnt - mp[cur]);
                break;
            }
            if (vis[cur]) break;
            vis[cur] = true;
            if (!G[cur].size()) break;
            mp[cur] = cnt++;
            cur = G[cur][0];
        }
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) 
        ans = max(ans, solve(i, G, dp));
    cout << ans << '\n';
}
