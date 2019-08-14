#include <bits/stdc++.h>
using namespace std;
void dfs1(int u, int p, vector<vector<int> > &G, vector<int> &d) {
    if (d[u] == -1)
        d[u] = d[p];
    for (auto &v : G[u])
        dfs1(v, u, G, d);
}
void dfs2(int u, int p, vector<vector<int> > &G, vector<int> &d) {
    if (!G[u].size())
        return ;
    d[u] = 1;
    for (auto &v : G[u]) {
        dfs2(v, u, G, d);
        d[u] &= d[v];
    }
}
vector<int> ans;
void dfs3(int u, int p, vector<vector<int> > &G, vector<int> &d) {
    if (d[u]) {
        ans.push_back(u);
    } else {
        for (auto &v : G[u])
            dfs3(v, u, G, d);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] == '0')
        s[0] = '-';
    vector<vector<int> > G(n);
    for (int i = 0 ; i < n - 1 ; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    vector<int> d(n, -1);
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == '0')
            continue;
        else if (s[i] == '-')
            d[i] = 0;
        else
            d[i] = 1;
    }
    dfs1(0, 0, G, d);
    dfs2(0, 0, G, d);
    dfs3(0, 0, G, d);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0 ; i < (int)ans.size() ; i++)
        cout << ans[i] + 1 << " \n"[i + 1 == (int)ans.size()];
}
