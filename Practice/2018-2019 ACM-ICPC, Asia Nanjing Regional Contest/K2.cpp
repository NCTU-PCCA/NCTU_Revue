#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string ds =   "DRUL";

void dfs(int x, int y, int px, int py, vector<vector<char> > &G, string &step) {
    int n = G.size();
    int m = G[0].size();
    for (int d = 0 ; d < 4 ; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (nx == px && ny == py)
            continue;
        if (G[nx][ny] == '0')
            continue;
        if (d == 0)
            step += "D";
        else if (d == 1)
            step += "R";
        else if (d == 2)
            step += "U";
        else if (d == 3)
            step += "L";
        dfs(nx, ny, x, y, G, step);
        if (d == 0)
            step += "U";
        else if (d == 1)
            step += "L";
        else if (d == 2)
            step += "D";
        else if (d == 3)
            step += "R";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &c : vv)
            cin >> c;
    string step = "";
    int f = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (G[i][j] == '0')
                continue;
            f = 1;
            dfs(i, j, i, j, G, step);
            if (f)
                break;
        }
        if (f)
            break;
    }
    if (step.size() == 0)
        cout << "L" << '\n';
    else {
        int sz = 0;
        while (sz + step.size() <= 50000)
            cout << step, sz += step.size();
        cout << step.substr(0, 50000 - sz);
        cout << '\n';
    }
}
