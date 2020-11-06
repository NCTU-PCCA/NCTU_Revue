#include <bits/stdc++.h>
using namespace std;
bool check(auto &state) {
    int sum = 0;
    for (auto &v : state)
        sum += v;
    return sum == 0;
}
void oper(auto &state, auto &op) {
    for (auto &v : op)
        state[v] ^= 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> state(m, 0);
    int x; cin >> x; while (x--) {
        int v; cin >> v; v--;
        state[v] = 1;
    }
    vector<vector<int>> op(n);
    for (auto &vv : op) {
        int x; cin >> x;
        vector<int> arr(x);
        for (auto &v : arr)
            cin >> v, v--;
        vv = arr;
    }

    for (int i = 0 ; i < 2 * n ; i++) {
        oper(state, op[i % n]);
        if (check(state)) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
