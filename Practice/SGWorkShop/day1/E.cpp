#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> row[2];
    for (int i = 1 ; i <= n ; i++) {
        int u, v; cin >> u >> v;
        row[u].push_back({v, i});
    }
    int ts = 1000;
    while (ts--) {
        random_shuffle(row[1].begin(), row[1].end());
        bool ok = true;
        for (int i = 0 ; i < n / 2 ; i++) {
            if (row[0][i].second == row[1][i].first || row[1][i].second == row[0][i].first)
                ok = false;
        }
        if (ok) {
            for (int i = 0 ; i < n / 2 ; i++)
                cout << row[1][i].second << " \n"[i + 1 == n / 2];
            for (int i = 0 ; i < n / 2 ; i++)
                cout << row[0][i].second << " \n"[i + 1 == n / 2];
            exit(0);
        }
    }
    cout << "impossible\n";
}
