#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, m; cin >> n >> m;
    long long  maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        long long v; cin >> v;
        maxV = max(maxV, v);
    }
    cout << (maxV * m - 1) / 1000 + 1 << '\n';

}
