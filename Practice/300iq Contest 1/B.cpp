#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool check(vector<LL> &data, LL M, LL k) {
    LL target = M / 2;
    vector<int> idx;
    for (int i = 0 ; i < (int)data.size() ; i++) {
        if (data[i] <= target)
            idx.push_back(i);
    }
    if (idx.size() == 0)
        return false;
    int cnt = idx.size();
    for (int i = 0 ; i < idx.size() - 1 ; i++) {
        // idx[i], idx[i + 1];
        for (int j = idx[i] + 1 ; j < idx[i + 1] ; j++) {
            if (max(data[idx[i]], data[idx[i + 1]]) + data[j] <= M) {
                cnt++;
                break;
            }
        }
    }
    for (int j = idx.back() + 1 ; j < idx[0] + data.size() ; j++) {
        if (data[j % data.size()] + max(data[idx.back()], data[idx[0]]) <= M) {
            cnt++;
            break;
        }
    }
    return cnt >= k;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> data(n);
    for (auto &v : data)
        cin >> v;
    LL L = 0, R = 2e9 + 5;
    while (R - L > 1) {
        LL M = (R + L) / 2;
        if (check(data, M, k))
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}
