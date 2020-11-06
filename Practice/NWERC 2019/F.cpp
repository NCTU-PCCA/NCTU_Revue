#include <bits/stdc++.h>
#define F first
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
struct Edge {
    int u, v, id;
};
vector<int> pa;
int find(int x) { return pa[x] < 0 ? x : pa[x] = find(pa[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    vector<Edge> edges;
    for (int i = 0 ; i < n ; i++) {
        int m; cin >> m;
        while (m--) {
            int v; cin >> v;
            if (mp.count(v)) {
                edges.push_back({i, mp[v], v});
            } else
                mp[v] = i;
        }
    }
    pa.resize(n + 1, -1);
    vector<Edge> ans;
    for (auto &e : edges) {
        int x = find(e.u);
        int y = find(e.v);
        if (x == y)
            continue;
        ans.push_back(e);
        if (pa[x] > pa[y])
            swap(x, y);
        pa[x] += pa[y];
        pa[y] = x;
    }
    if ((int)ans.size() == n - 1) {
        for (auto &e : ans)
            cout << e.u + 1 << ' ' << e.v + 1 << ' ' << e.id << '\n';
    } else {
        cout << "impossible\n";
    }
}
