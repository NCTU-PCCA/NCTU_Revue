#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int find(int x, vector<int> &pa) { return pa[x] < 0 ? x : pa[x] = find(pa[x], pa); }
int query(int x) {
    cout << "? " << x + 1 << endl;
    int ret; cin >> ret; ret--;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m; vector<int> pa(n, -1);
        multiset<pii> rk; vector<set<int> > dj_sets(n);
        for (int i = 0 ; i < n ; i++) dj_sets[i].insert(i), rk.insert({1, i});
        vector<bool> out(n, false);
        while (1) {
            int cnt = 0;
            for (int i = 0 ; i < n ; i++)
                cnt += (pa[i] < 0);
            if (cnt == 1) {
                cout << "+" << endl;
                break;
            }
            pii cur = *rk.begin();
            vector<int> list;
            for (auto &v : dj_sets[cur.second]) {
                if (out[v]) continue;
                list.push_back(v);
            }
            if (list.size() == 0) {
                cout << "-" << endl;
                break;
            }
            int tar = list[rand() % list.size()];
            int ret = query(tar);
            if (ret == -2) {
                out[tar] = true;
            } else {
                int x = find(tar, pa);
                int y = find(ret, pa);
                if (x == y)
                    continue;
                if (pa[x] < pa[y])
                    swap(x, y);
                rk.erase({-pa[x], x});
                rk.erase({-pa[y], y});
                pa[y] += pa[x];
                pa[x] = y;
                for (auto &v : dj_sets[x])
                    dj_sets[y].insert(v);
                dj_sets[x].clear();
                rk.insert({-pa[y], y});
            }
        }
    }
}
