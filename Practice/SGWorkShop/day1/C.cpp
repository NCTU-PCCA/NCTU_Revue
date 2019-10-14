#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > G(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char c; cin >> c;
            if (c == 'L') {
                G[i][j] = -2;
            } else if (c == 'F') {
                G[i][j] = 0;
            }
        }
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (G[i][j]) continue;
            queue<pii> q; q.push({i, j}); G[i][j] = 1;
            while (q.size()) {
                auto p = q.front(); q.pop();
                for (int d = 0 ; d < 4 ; d++) {
                    pii nt = {p.F + dx[d], p.S + dy[d]};
                    if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                        continue;
                    if (G[nt.F][nt.S]) continue;
                    G[nt.F][nt.S] = G[p.F][p.S] * -1;
                    q.push(nt);
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (G[i][j] == -2) cout << 'L';
            else if (G[i][j] == 1)
                cout << 'B';
            else cout << 'F';
        }
        cout << '\n';
    }
}
