#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool check(auto &G, int a, int b) {
    int n = G.size();
    vector<int> c(n, 0);
    for (int i = 0 ; i < n ; i++) {
        if (i == a || i == b) continue;
        if (c[i]) continue;
        queue<int> q; c[i] = 1; q.push(i); while (q.size()) {
            int p = q.front(); q.pop();
            for (auto &v : G[p]) {
                if (v == a || v == b) continue;
                if (c[v] == c[p]) {
                    return false;
                } else if (c[v] == 0) {
                    c[v] = c[p] * -1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
#define F first
#define S second
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0 ; i < n ; i++) {
        int m; cin >> m;
        while (m--) {
            int v; cin >> v; v--;
            G[i].push_back(v);
            G[v].push_back(i);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            if (check(G, i, j)) {
                cout << "Hurrah!\n";
                exit(0);
            }
        }
    }
    cout << "Fired.\n";
}
