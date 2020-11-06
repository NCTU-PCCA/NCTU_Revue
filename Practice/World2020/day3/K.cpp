#include <bits/stdc++.h>
using namespace std;
void update(auto &G, int u, auto &ok, int &sum) {
    for (auto &v : G[u]) {
        if (ok[v]) continue;
        sum++; ok[v] = 1;
        update(G, v, ok, sum);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, q; cin >> n >> k >> q;
    vector<int> ok(n, 0);
    vector<vector<int>> G(n);
    int sum = 0;
    while (k--) {
        int v; cin >> v; v--;
        ok[v] = 1;
        sum++;
    }
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u == v) {
            cout << sum << '\n';
            continue;
        }
        G[v].push_back(u);
        if (ok[v])
            update(G, v, ok, sum);
        cout << sum << '\n';
    }
}
