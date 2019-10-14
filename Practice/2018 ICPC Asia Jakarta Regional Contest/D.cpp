#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    if (n <= 2 && m <= 2) { 
        cout << 0 << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 1 ; i < n - 1 ; i++)
        for (int j = 1 ; j < m - 1 ; j++)
            if (G[i][j] == '.')
                cnt++;
    if (n == 1) {
        for (int j = 1 ; j < m - 1 ; j++)
            if (G[0][j] == '.')
                cnt++;
    } else if (m == 1) {
        for (int i = 1 ; i < n - 1 ; i++)
            if (G[i][0] == '.')
                cnt++;
    } else if (n == 2) {
        for (int j = 1 ; j < m - 1 ; j++)
            if (G[0][j] == '.' && G[1][j] == '.')
                cnt++;
    } else if (m == 2) {
        for (int i = 1 ; i < n - 1 ; i++)
            if (G[i][0] == '.' && G[i][1] == '.')
                cnt++;
    } else {
        bool all = true;
        for (int i = 1 ; i < n - 1 ; i++)
            if (G[i][0] == '#' || G[i][m - 1] == '#')
                all = false;
        for (int j = 1 ; j < m - 1 ; j++)
            if (G[0][j] == '#' || G[n - 1][j] == '#')
                all = false;
        cnt += all;
    }
    cout << cnt << '\n';
}
