#include <bits/stdc++.h>
using namespace std;
bool ok(auto &G, int x, int y) {
    int n = G.size();
    return (0 < x && x < n - 1 && 0 < y && y < n - 1);
}
void solve(int S, int x, int y, auto &G) {
    // cout << S << ' ' << x << ' ' << y << '\n';
    int n = G.size();
    if (S == 0) {
        if (ok(G, x, y - 1))
            G[x][y - 1] = '_';
        if (ok(G, x, y))
            G[x][y] = 'o';
        if (ok(G, x, y + 1))
            G[x][y + 1] = '_';
    } else {
        if (ok(G, x, y - 1))
            G[x][y - 1] = '_';
        if (ok(G, x, y))
            G[x][y] = '|';
        if (ok(G, x, y + 1))
            G[x][y + 1] = '_';
        for (int i = min(x - 1, n) ; i >= max(x - S, 0) ; i--) {
            if (ok(G, i, y - 1))
                G[i][y - 1] = '/';
            if (ok(G, i, y))
                G[i][y] = '|';
            if (ok(G, i, y + 1))
                G[i][y + 1] = '\\';
        }
        if (ok(G, x - S - 1, y))
            G[x - S - 1][y] = '^';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int f = 1;
    int n, m; while (cin >> n >> m) {
        if (f) f = 0; else cout << '\n';
        vector<vector<char>> G(n + 2, vector<char>(n + 2, '.'));
        for (int i = 0 ; i < n + 2 ; i++)
            G[i][0] = G[i][n + 1] = G[0][i] = G[n + 1][i] = '*';
        while (m--) {
            int S, X, Y; cin >> S >> X >> Y;
            int x = n - Y;
            int y = X + 1;
            solve(S, x, y, G);
        }
        for (auto &vv : G) {
            for (auto &v : vv)
                cout << v;
            cout << '\n';
        }
    }
}
