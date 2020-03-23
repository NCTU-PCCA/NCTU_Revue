#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, C, h, m; cin >> n >> m >> C >> h >> m;
    vector<int> group(n, 0);
    while (h--) {
        int v; cin >> v;
        group[v] = 1;
    }
    vector<vector<pii> > G(n + 1);
    while (m--) {
        int v; cin >> v;
        G[n].push_back({v, 0});
    }
    while (m--) {
        int u, c, v; cin >> u >> c >> v;
        G[u].push_back({v, c});
    }
    
}
