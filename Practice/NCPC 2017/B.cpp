#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int> > &G, int s) {
    vector<int> d(G.size(), -1);
    d[s] = 0; queue<int> q; q.push(s);
    int ret = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (~d[v]) continue;
            d[v] = d[p] + 1;
            ret = max(ret, d[v]);
            q.push(v);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<vector<int> > G(n);
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            if (!v) continue;
            v--;
            G[v].push_back(i);
            G[i].push_back(v);
        }
        int minV = n + 4;
        for (int i = 0 ; i < n ; i++) {
            minV = min(minV, bfs(G, i));
        }
        bool f = true;
        for (int i = 0 ; i < n ; i++) {
            if (bfs(G, i) == minV) {
                if (f) f = false;
                else cout << ' ';
                cout << i + 1;
            }
        }
        cout << '\n';
        
    }
}
