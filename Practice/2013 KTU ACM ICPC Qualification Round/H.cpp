#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ":\n";
        int n, m; cin >> n >> m;
        vector<int> pa(n, -1);
        while (m--) {
            int u, v; cin >> u >> v; u--, v--;
            int x = find(u, pa);
            int y = find(v, pa);
            if (x == y)
                continue;
            pa[x] += pa[y];
            pa[y] = x;
        }
        for (int i = 0 ; i < n ; i++) {
            int x = find(i, pa);
            cout << abs(pa[x]) - 1 << " \n"[i + 1 == n];
        }
    }
}
