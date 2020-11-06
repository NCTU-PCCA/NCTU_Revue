#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
bool check(auto &G, int sum) {
    int n = G.size();
    for (int i = 0 ; i < n ; i++) {
        int tot = 0;
        for (int j = 0 ; j < n ;j ++) {
            if (G[i][j] == 0) {
                tot = -1;
                break;
            }
            tot += G[i][j];
        }
        if (tot != -1 && tot != sum)
            return false;
    }
    for (int i = 0 ; i < n ; i++) {
        int tot = 0;
        for (int j = 0 ; j < n ;j ++) {
            if (G[j][i] == 0) {
                tot = -1;
                break;
            }
            tot += G[j][i];
        }
        if (tot != -1 && tot != sum)
            return false;
    }
    int tot = 0;
    for (int i = 0 ; i < n ; i++) {
        if (G[i][i] == 0) {
            tot = -1;
            break;
        }
        tot += G[i][i];
    }
    if (tot != -1 && tot != sum)
        return false;
    
    
    tot = 0;
    for (int i = 0 ; i < n ; i++) {
        if (G[i][n - i - 1] == 0) {
            tot = -1;
            break;
        }
        tot += G[i][n - i - 1];
    }
    if (tot != -1 && tot != sum)
        return false;
    return true;
}
bool solve(auto &G, int x, int y, auto &used, int sum) {
    int n = G.size();
    for (auto &vv : G) {
        for (auto &v : vv)
            cout << setw(4) << v << ' ';
        cout << '\n';
    }
    cout << '\n';
    if (x == n) return true;
    for (int i = 1 ; i <= n * n ; i++) {
        if (used[i]) continue;
        G[x][y] = i;
        used[i] = 1;
        if (check(G, sum)) {
            if (solve(G, x + (y + 1) / n, (y + 1) % n, used, sum))
                return true;
        }
        used[i] = 0;
        G[x][y] = 0;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<int> arr(n);
        vector<int> used(n * n + 1, 0);
        int sum = 0;
        for (auto &v : arr)
            cin >> v, sum += v, used[v] = 1;
        vector<vector<int>> G(n, vector<int>(n));
        for (int i = 0 ; i < n ; i++)
            G[0][i] = arr[i];
        if (solve(G, 1, 0, used, sum)) {
            for (auto &vv : G) {
                for (auto &v : vv)
                    cout << v << ' ';
                cout << '\n';
            }
        } else {
            cout << -1 << '\n';
        }

    }
}
