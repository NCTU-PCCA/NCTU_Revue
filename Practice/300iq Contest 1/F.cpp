#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; int cnt = 0;
    pa.clear(); pa.resize(n, -1);
    for (int i = 0 ; i < m ; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        int x = find(u);
        int y = find(v);
        if (x == y)
            continue;
        cnt++;
        pa[x] += pa[y];
        pa[y] = x;
    }
    cout << m - cnt << '\n';
}
