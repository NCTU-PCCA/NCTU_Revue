#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, k; cin >> n >> k;
    map<LL, LL> pool;
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        pool[v]++;
        pool[v + 1000]--;
    }
    LL maxV = 0, sum = 0;
    for (auto &p : pool) {
        sum += p.second;
        maxV = max(maxV, sum);
    }
    cout << (maxV - 1) / k + 1 << '\n';
}
