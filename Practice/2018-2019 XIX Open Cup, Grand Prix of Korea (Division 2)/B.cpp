#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<set<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    queue<int> q;
    vector<int> deg;
    for (int i = 0 ; i < n ; i++) {
        deg.push_back(G[i].size());
        if (deg[i] == 2)
            q.push(i);
    }
    set<int> ok;
    while (q.size()) {
        int p = q.front(); q.pop();
        if (deg[p] != 2) continue;
        vector<int> V;
        for (auto &v : G[p])
            V.push_back(v);
        if (G[V[0]].count(V[1])) {
            deg[V[0]]--;
            if (deg[V[0]] == 2)
                q.push(V[0]);
            deg[V[1]]--;
            if (deg[V[1]] == 2)
                q.push(V[1]);
        } else {
            G[V[0]].insert(V[1]);
            G[V[1]].insert(V[0]);
        }
        ok.insert(p);
        G[V[0]].erase(p);
        G[V[1]].erase(p);
    }
    if (ok.size() == n - 2)
        cout << "Yes\n";
    else
        cout << "No\n";
}
