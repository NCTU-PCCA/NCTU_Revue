#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> cnt(n, 0);
    for (int i = 0 ; i < m ; i++) {
        int v; cin >> v; v--;
        cnt[v]++;
    }
    map<int, vector<int>> pool;
    for (int i = 0 ; i < n ; i++)
        pool[cnt[i]].push_back(i);
    bool ok = false;
    if (pool.size() == 2) {
        vector<int> res;
        for (auto &p : pool)
            res.push_back(p.F);
        if (res[0] == res[1] - 1) {
            if (pool[res[0]].size() == 1) {
                cout << "+" << pool[res[0]][0] + 1 << '\n';
                ok = true;
            } else if (pool[res[1]].size() == 1) {
                cout << "-" << pool[res[1]][0] + 1 << '\n';
                ok = true;
            }
        }
    } else if (pool.size() == 3) {
        vector<int> res;
        for (auto &p : pool)
            res.push_back(p.F);
        if (res[0] == res[1] - 1 && res[1] == res[2] - 1) {
            if (pool[res[0]].size() == 1 && pool[res[2]].size() == 1) {
                cout << "-" << pool[res[2]][0] + 1 << " " << "+" << pool[res[0]][0] + 1 << '\n';
                ok = true;
            }
        }
    }
    if (!ok) {
        cout << "*\n";
    }
}
