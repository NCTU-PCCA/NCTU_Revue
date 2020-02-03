#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int> > G(n / 2, vector<int>(n / 2, 0));
        while (m--) {
            int u, v; cin >> u >> v;
            u--, v--;
            v -= n / 2;
            G[u][v] = 1;
        }
        vector<int> data;
        for (int i = 0 ; i < n / 2 ; i++)
            data.push_back(i);
        int cnt = 0;
        do {
            bool ok = true;
            for (int i = 0 ; i < n / 2 ; i++)
                if (!G[i][data[i]])
                    ok = false;
            cnt += ok;
        } while (next_permutation(data.begin(), data.end()));
        cout << (cnt + 1) % 2 << '\n';
    }
}
