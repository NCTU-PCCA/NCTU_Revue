#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, w; cin >> n >> w;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    vector<vector<int> > G(n);
    vector<vector<int> > revG(n);
    vector<int> deg(n, 0);
    for (int i = 0 ; i < n ; i++) {
        for (int j = i - w ; j <= i + w ; j++) {
            if (i == j || j < 0 || j >= n)
                continue;
            if (data[j] <= data[i])
                continue;
            G[i].push_back(j);
            deg[j]++;
        }
    }
    vector<int> d(n, 0);
    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (deg[i])
            continue;
        q.push(i); 
    }
    int ans = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            d[v] = max(d[v], d[p] + 1);
            ans = max(ans, d[v]);
            deg[v]--;
            if (deg[v])
                continue;
            q.push(v);
        }
    }
    cout << ans << '\n';
}
