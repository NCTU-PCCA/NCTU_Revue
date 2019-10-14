#include <bits/stdc++.h>
using namespace std;
void doing(vector<vector<int> > &data, int x, int y) {
    for (int dx = -1 ; dx <= 1 ; dx++) {
        for (int dy = -1 ; dy <= 1 ; dy++) {
            if (data[x + dx][y + dy] == 0) {
                cout << "impossible\n";
                exit(0);
            }
            data[x + dx][y + dy]--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > data(n + 2, vector<int>(m + 2));
    for (auto &vv : data)
        for (auto &v : vv)
            cin >> v;
    vector<vector<char> > ans(n, vector<char>(m));
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (data[i - 1][j - 1] == 0)
                ans[i - 1][j - 1] = '.';
            else if (data[i - 1][j - 1] == 1) {
                ans[i - 1][j - 1] = 'X';
                doing(data, i, j);
            } else {
                cout << "impossible\n";
                exit(0);
            }
        }
    }
    bool legal = true;
    for (int i = 0 ; i <= n + 1 ; i++)
        for (int j = 0 ; j <= m + 1 ; j++)
            if (data[i][j] != 0)
                legal = false;
    if (!legal)
        cout << "impossible\n";
    else {
        for (auto &vv : ans) {
            for (auto &v : vv)
                cout << v;
            cout << '\n';
        }
    }

}
