#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx;
        cout << idx << ' ';
        LL n; cin >> n;
        cout << n * (1 + n) / 2 + n << '\n';
    }
}
