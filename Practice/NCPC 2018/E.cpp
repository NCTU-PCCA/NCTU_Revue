#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 65537;
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
struct E {
    int u, v; ll w;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m && n) {
        vector<E> edges;
        while (m--) {
            int u, v; ll w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end(), [](E a, E b) {
            return a.w < b.w;        
        });
        vector<int> pa(n, -1);
        ll ans = 1;
        for (auto &e : edges) {
            int x = find(e.u, pa);
            int y = find(e.v, pa);
            if (x == y)
                continue;
            pa[x] += pa[y];
            pa[y] = x;
            ans *= e.w;
            ans %= mod;
        }
        cout << ans << '\n';
    }
    
}
