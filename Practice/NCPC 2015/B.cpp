#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        exit(0);
    }
    vector<vector<int>> arr(1, vector<int>(1, 1));
    for (int i = 2 ; i <= n ; i++) {
        vector<vector<int>> newArr;
        int order = 1;
        for (auto &vv : arr) {
            for (int j = 0 ; j < i ; j++) {
                newArr.push_back(vv);
                if (order) {
                    newArr.back().insert(newArr.back().begin() + i - j - 1, i);
                } else {
                    newArr.back().insert(newArr.back().begin() + j, i);
                }
            }
            order ^= 1;
        }
        arr = newArr;
    }
    for (auto &vv : arr) {
        for (int i = 0 ; i < vv.size() ; i++)
            cout << vv[i] << " \n"[i + 1 == vv.size()];
    }
}
