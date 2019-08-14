#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<vector<int> > data(n);
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            for (int j = 0 ; j < n - 1 ; j++) {
                cin >> v; v--;
                data[i].push_back(v);
            }
        }
        vector<pii> ans;
        vector<int> used(n, 0);
        vector<int> ptr(n, 0);
        int cnt = 0;
        for (int j = n - 2 ; j >= 0 ; j--) {
            for (int i = 0 ; i < n ; i++) {
                if (used[data[i][j]])
                    continue;
                used[data[i][j]] = 1;
                cnt++;
                if (cnt == n)
                    break;
                int target = data[i][j];
                while (used[data[target][ptr[target]]])
                    ptr[target]++;
                ans.push_back({data[target][ptr[target]], target});
            }
        }
        for (auto &p : ans)
            cout << p.first + 1 << ' ' << p.second + 1 << '\n';
        cout << '\n';
    }
}
