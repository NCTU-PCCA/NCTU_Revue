#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const vector<vector<int>> U = {{1, 2}, {0, 3}};
const vector<vector<int>> D = {{3, 0}, {2, 1}};
const vector<vector<int>> L = {{1, 0}, {2, 3}};
const vector<vector<int>> R = {{3, 2}, {0, 1}};
pii solve(int n, int m, auto S) {
    if (n == 1) {
        return {0, 0};
    } else {
        pii ans;
        int k = (n / 2) * (n / 2);
        int x = m / k;
        int y = m % k;
        k = n / 2;
        if (S == U) {
            // 1, 2
            // 0, 3
            if (x == 0) {
                ans = solve(n >> 1, y, R);
            } else if (x == 1) {
                ans = solve(n >> 1, y, U);
                ans.S += k;
            } else if (x == 2) {
                ans = solve(n >> 1, y, U);
                ans.F += k;
                ans.S += k;
            } else if (x == 3) {
                ans = solve(n >> 1, y, L);
                ans.F += k;
            }
        } else if (S == R) {
            // 3, 2
            // 0, 1
            if (x == 0) {
                ans = solve(n >> 1, y, U);
            } else if (x == 1) {
                ans = solve(n >> 1, y, R);
                ans.F += k;
            } else if (x == 2) {
                ans = solve(n >> 1, y, R);
                ans.F += k;
                ans.S += k;
            } else if (x == 3) {
                ans = solve(n >> 1, y, D);
                ans.S += k;
            }
        } else if (S == L) {
            // 1, 0
            // 2, 3
            if (x == 0) {
                ans = solve(n >> 1, y, D);
                ans.F += k;
                ans.S += k;
            } else if (x == 1) {
                ans = solve(n >> 1, y, L);
                ans.S += k;
            } else if (x == 2) {
                ans = solve(n >> 1, y, L);
            } else if (x == 3) {
                ans = solve(n >> 1, y, U);
                ans.F += k;
            }
        } else if (S == D) {
            // 3, 0
            // 2, 1
            if (x == 0) {
                ans = solve(n >> 1, y, L);
                ans.F += k;
                ans.S += k;
            } else if (x == 1) {
                ans = solve(n >> 1, y, D);
                ans.F += k;
            } else if (x == 2) {
                ans = solve(n >> 1, y, D);
            } else if (x == 3) {
                ans = solve(n >> 1, y, R);
                ans.S += k;
            }
        }
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; m--;
    vector<vector<int>> S = {{1, 2}, {0, 3}};
    pii ans = solve(n, m, S);
    cout << ans.F + 1 << ' ' << ans.S + 1 << '\n';
}
