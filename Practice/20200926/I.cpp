#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int getId(string s, map<string, int> &id) {
    if (!id.count(s)) {
        int m = id.size();
        id[s] = m;
    }
    return id[s];
}
const int INF = 0x3f3f3f3f;
vector<int> bfs(vector<vector<int>> &G, int s) {
    int n = G.size();
    vector<int> d(n, INF); d[s] = 0;
    queue<int> q; q.push(s); while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (d[v] > d[p] + 1)
                d[v] = d[p] + 1, q.push(v);
        }
    }
    return d;
}
void solve() {
    int m; cin >> m;
    map<string, int> id;
    vector<pii> edges;
    while (m--) {
        string a, b; cin >> a >> b;
        int x = getId(a, id);
        int y = getId(b, id);
        edges.push_back({x, y});
    }
    vector<vector<int>> G(id.size());
    for (auto &e : edges)
        G[e.F].push_back(e.S),
        G[e.S].push_back(e.F);
    int cnt = 0;
    for (int i = 0 ; i < id.size() ; i++) {
        vector<int> d = bfs(G, i);
        int maxV = *max_element(d.begin(), d.end());
        if (maxV > 6)
            cnt++;
    }
    if (cnt * 20 > id.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
