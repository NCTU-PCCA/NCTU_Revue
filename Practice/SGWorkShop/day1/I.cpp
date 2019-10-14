#include <bits/stdc++.h>
using namespace std;
struct Edge { int v, dp; }; // W: 1, L: 0
int solve(int u, int p, vector<vector<Edge> > &G) {
    for (auto &e : G[u]) {
        if (e.v == p) continue;
        if (!~e.dp)
            e.dp = solve(e.v, u, G);
        if (e.dp == 0) return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; vector<vector<Edge> > G(n);
    for (int i = 1 ; i < n ; i++) {
        int v; cin >> v; v--;
        G[v].push_back({i, -1});
        G[i].push_back({v, -1});
    }
    for (int i = 0 ; i < n ; i++) {
        if (!solve(i, -1, G))
            cout << i + 1 << '\n';
    }
}
