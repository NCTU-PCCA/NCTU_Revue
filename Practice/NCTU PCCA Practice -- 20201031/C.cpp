#include <bits/stdc++.h>
using namespace std;
bool dfs(int i, int j, auto &G, auto &idx, auto &cnt) {
    int n = G.size(), m = G[0].size();
    if (i == n) return true;
    if (G[i][j] == -1) {
        int maxV = cnt[idx[i][j]].size();
        for (int x = 0 ; x < maxV ; x++) {
            if (cnt[idx[i][j]][x])
                continue;
            if (i - 1 >= 0 && G[i - 1][j] == x)
                continue;
            if (j - 1 >= 0 && G[i][j - 1] == x)
                continue;
            if (i - 1 >= 0 && j - 1 >= 0 && G[i - 1][j - 1] == x)
                continue;
            if (i - 1 >= 0 && j + 1 < m && G[i - 1][j + 1] == x)
                continue;
            cnt[idx[i][j]][x] = 1;
            G[i][j] = x;
            if (dfs(i + (j + 1) / m, (j + 1) % m, G, idx, cnt))
                return true;
            cnt[idx[i][j]][x] = 0;
            G[i][j] = -1;
        }
    } else {
        int x = G[i][j];
        if (i - 1 >= 0 && G[i - 1][j] == x)
            return false;
        if (j - 1 >= 0 && G[i][j - 1] == x)
            return false;
        if (i - 1 >= 0 && j - 1 >= 0 && G[i - 1][j - 1] == x)
            return false;
        if (i - 1 >= 0 && j + 1 < m && G[i - 1][j + 1] == x)
            return false;
        if (dfs(i + (j + 1) / m, (j + 1) % m, G, idx, cnt))
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m));
    vector<vector<int>> idx(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char c; cin >> c;
            if (c == '-') 
                G[i][j] = -1;
            else
                G[i][j] = c - '0' - 1;
        }
    }
    int tot; cin >> tot;
    vector<vector<int>> cnt(tot);
    for (int i = 0 ; i < tot ; i++) {
        int num; cin >> num;
        cnt[i] = vector<int>(num, 0);
        while (num--) {
            char c; int x, y;
            cin >> c >> x >> c >> y >> c;
            x--, y--;
            idx[x][y] = i;
            if (G[x][y] != -1)
                cnt[i][G[x][y]]++;
        }
    }
    dfs(0, 0, G, idx, cnt);
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            cout << G[i][j] + 1 << " \n"[j + 1 == m];
}
