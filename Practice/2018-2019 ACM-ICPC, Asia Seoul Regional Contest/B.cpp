#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> m >> n;
    vector<vector<int> > data(n, vector<int>(m));
    for (auto &vv : data) {
        map<int, int> mp;
        for (auto &v : vv) {
            cin >> v;
            if (v == 0)
                v = INF;
            mp[v] = 0;
        }
        int idx = 0;
        for (auto &p : mp)
            p.S = idx++;
        for (auto &v : vv)
            v = mp[v];
    }
    vector<vector<int> > d(m, vector<int>(m, 0));
    for (int i = 0 ; i < m ; i++)
        for (int j = 0 ; j < m ; j++)
            for (int k = 0 ; k < n ; k++)
                if (data[k][i] < data[k][j])
                    d[i][j]++;
    for (int i = 0 ; i < m ; i++) {
        for (int j = 0 ; j < i ; j++) {
            if (d[i][j] == d[j][i])
                d[i][j] = d[j][i] = 0;
            else if (d[i][j] > d[j][i])
                d[j][i] = 0;
            else
                d[i][j] = 0;
        }
    }
    for (int k = 0 ; k < m ; k++)
        for (int i = 0 ; i < m ; i++)
            for (int j = 0 ; j < m ; j++)
                d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
    for (int i = 0 ; i < m ; i++) {
        bool ok = true;
        for (int j = 0 ; j < m ; j++) {
            if (d[i][j] < d[j][i])
                ok = false;
        }
        if (ok)
            cout << i + 1 << ' ';
    }
    cout << '\n';
}
