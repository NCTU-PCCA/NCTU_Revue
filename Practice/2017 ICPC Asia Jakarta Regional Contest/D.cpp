#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k;
struct Edge {
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
map<int, int> ID;
int getID(int u) {
    int sz = ID.size();
    if (!ID.count(u))
        ID[u] = sz;
    return ID[u];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    vector<Edge> edges;
    for (int i = 0 ; i < n ; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({getID(u), getID(v), w});
    }
    sort(edges.begin(), edges.end());
    vector<int> sz(2 * n, 0);
    int cnt = 0;
    for (auto &e : edges) {
        if (sz[e.u]== 0) {
            sz[e.u] += k - 1;
            cnt++;
        } else
            sz[e.u]--;
        sz[e.v] += k;
    }
    cout << cnt << '\n';
}
