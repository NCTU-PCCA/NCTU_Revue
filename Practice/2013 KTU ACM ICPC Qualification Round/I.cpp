#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ":\n";
        int n, m; cin >> n >> m;
        vector<string> data(n);
        for (auto &v : data)
            cin >> v;
        while (m--) {
            bool find = false;
            string tar; cin >> tar;
            for (auto &v : data) {
                if (tar == v)
                    find = true;
                if (find)
                    break;
            }
            if (find) {
                cout << "yes\n";
                continue;
            }
            int cnt = 0;
            for (auto &v : data) {
                if (v.size() != tar.size())
                    continue;
                int sum = 0;
                for (int i = 0 ; i < (int)v.size() ; i++)
                    sum += (v[i] != tar[i]);
                if (sum < 2)
                    cnt++;
            }
            if (cnt == 1)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

}
