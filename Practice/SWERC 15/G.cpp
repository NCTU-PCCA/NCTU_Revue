#include <bits/stdc++.h>
using namespace std;
int k;
int solve(vector<int> &data, int sz, vector<int> &SG) {
    int target = sz;
    if (~SG[target]) return SG[target];
    if (target == 0) return SG[target] = 0;
    // if (data[sz - 1] > sz) return SG[target] = 0;
    vector<int> ret; sz++;
    // 1, sz: 1
    for (int i = 0 ; i <= k ; i++) {
        sz--;
    // 1, sz: 1
        if (sz == 0) break;
        if (data[sz - 1] > sz) continue;
        ret.push_back(solve(data, sz - data[sz - 1], SG));
    }
    if (ret.size() == 0) return SG[target] = 0;
    for (int i = 0 ; ; i++) {
        bool found = true;
        for (int j = 0 ; j < ret.size() ; j++) {
            if (ret[j] == i) {
                found = false;
                break;
            }
        }
        if (found) return SG[target] = i;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, ret = 0; cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        int N; cin >> N;
        vector<int> SG(N + 1, -1);
        vector<int> data(N); for (auto &v : data) cin >> v;
        ret ^= solve(data, data.size(), SG);
    }
    if (ret != 0)
        cout << "Alice can win.\n";
    else
        cout << "Bob will win.\n";
}
