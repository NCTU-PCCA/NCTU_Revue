#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool check(vector<LL> &data, LL p, LL q, LL M) {
    if (p == q) {
        for (auto &v : data)
            if (max(0LL, v - q * M) != 0)
                return false;
        return true;
    } else { 
        LL ans = 0;
        for (auto &v : data) {
            LL tar = max(0LL, v - q * M);
            if (tar == 0)
                continue;
            ans += (tar - 1) / (p - q) + 1;
        }
        return ans <= M;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL q, p; cin >> n >> p >> q;
    vector<LL> data(n);
    for (auto &v : data)
        cin >> v;
    LL L = 0, R = 1e9 + 7;
    while (R - L > 1) {
        LL M = (L + R) >> 1;
        (check(data, p, q, M) ? R : L) = M;
    }
    cout << R << '\n';
}
