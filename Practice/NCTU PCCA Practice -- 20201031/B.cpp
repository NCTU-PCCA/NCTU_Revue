#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        LL b, n; cin >> b >> n;
        LL sum = 0;
        while (n) {
            LL x = n % b; n /= b;
            sum += x * x;
        }
        cout << sum << '\n';
    }
}
