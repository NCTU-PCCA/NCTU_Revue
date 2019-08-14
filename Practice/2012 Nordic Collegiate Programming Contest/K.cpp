#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<int> > &G, int u, int c, vector<int> &C, vector<int> &group) {
    for (auto &v : G[u]) {
        if (C[v] == -1) {
            bool ok[3]; memset(ok, true, sizeof(ok));
            for (auto &nt : G[v]) {
                if (C[nt] == -1)
                    continue;
                ok[C[nt]] = false;
            }
            bool legal = false;
            for (int j = 0 ; j < 3 ; j++) {
                if (group[v] == j)
                    continue;
                if (!ok[j])
                    continue;
                C[v] = j;
                if (solve(G, v, j, C, group)) {
                    legal = true;
                    break;
                }
                C[v] = -1;
            }
            if (!legal)
                return false;
        } else {
            bool ok[3]; memset(ok, true, sizeof(ok));
            for (auto &nt : G[v]) {
                if (C[nt] == -1)
                    continue;
                ok[C[nt]] = false;
            }
            if (!ok[C[v]])
                return false;
        }
    }
    return true;
}
bool check(vector<int> &group, vector<vector<int> > &list, int M) {
    int n = (int)group.size();
    if (M == n - 1) return true;
    vector<vector<int> > G(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = M ; j < n - 1 ; j++) {
            G[i].push_back(list[i][j] - 1),
            G[list[i][j] - 1].push_back(i);
        }
    }
    vector<int> C(n, -1);
    for (int i = 0 ; i < n ; i++) {
        if (~C[i])
            continue;
        bool legal = false;
        for (int j = 0 ; j < 3 ; j++) {
            if (group[i] == j)
                continue;
            C[i] = j;
            if (solve(G, i, j, C, group)) {
                legal = true;
                break;
            }
            C[i] = -1;
        }
        if (!legal)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> group(n);
    vector<vector<int> > list(n, vector<int>(n - 1));
    for (int i = 0 ; i < n ; i++) {
        cin >> group[i];
        for (auto &v : list[i])
            cin >> v;
    }
    int L = -1, R = n - 1;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(group, list, M))
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}
