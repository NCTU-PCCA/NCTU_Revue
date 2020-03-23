#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, pair<int, int> > pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        sort(data.begin(), data.end());
        for (auto &v : data)
            cout << v << ' ';
        cout << '\n';
        vector<pii> item;
        vector<int> sz;
        int cnt = 0;
        int p = 0; while (p < n) {
            int cnt2 = 1;
            item.push_back({p, {-1, cnt}});
            while (p + 1 < n && data[p + 1] - data[p] <= 2)
                p++, cnt2++;
            item.push_back({p, {1, cnt}});
            sz.push_back(cnt2);
            p++; cnt++;
        }
        for (auto &v : item)
            cout << '(' << v.F << ' ' << v.S.F << ' ' << v.S.S << ')';
        cout << '\n';
        for (auto &v : sz)
            cout << v << ' ';
        cout << '\n';

        int ans = 0;
        for (auto &v : sz)
            ans = max(ans, v);

        for (auto &v : item) {
            if (v.S.F == -1) {
                if (v.S.S == 0)
                    continue;
                if ((data[v.F] - 1) - data[v.F - 1] > 2)
                    continue;
                if (data[v.F + 1] - (data[v.F - 1]) <= 2) { // connect
                    ans = max(ans, sz[v.S.S - 1] + sz[v.S.S]);
                } else {   // move
                    ans = max(ans, sz[v.S.S - 1] + 1);
                }
            } else if (v.S.F == 1) {
                if (v.S.S == sz.size() - 1)
                    continue;
                if (data[v.F + 1] - (data[v.F] + 1) > 2)
                    continue;
                if ((data[v.F] + 1) - data[v.F - 1] <= 2) { // connect
                    
                }
            }
        }


    }
}
