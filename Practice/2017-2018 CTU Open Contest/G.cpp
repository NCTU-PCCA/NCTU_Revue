#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        vector<vector<int>> G;
        vector<int> check(m, 0); int tot = m;
        for (int i = 0 ; i < n ; i++) {
            int x; cin >> x;
            vector<int> arr(x);
            for (auto &v : arr) {
                cin >> v; v--;
                if (check[v] == 0)
                    tot--;
                check[v]++;
            }
            G.push_back(arr);
        }
        if (tot != 0) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0 ; i < n ; i++)
            G.push_back(G[i]);
        vector<int> cnt(m, 0); int lack = m;
        int L = 0, R = 0, ans = INF, sum = 0;
        for (L = 0 ; L < 2 * n ; L++) {
            while (R < 2 * n && lack) {
                for (auto &v : G[R]) {
                    if (cnt[v] == 0)
                        lack--;
                    cnt[v]++;
                    sum++;
                }
                R++;
            }
            if (!lack)
                ans = min(ans, sum);
            for (auto &v : G[L]) {
                if (cnt[v] == 1)
                    lack++;
                cnt[v]--;
                sum--;
            }
        }
        cout << ans << '\n';
    }
}
