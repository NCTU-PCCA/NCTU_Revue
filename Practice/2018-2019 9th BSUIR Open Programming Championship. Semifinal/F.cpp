#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n; cin >> n;
    if (n == 1) {
        cout << "No\n";
        return 0;
    }
    int x = __builtin_popcountll(n);
    if (x == 1) {
        cout << "Yes\n";
    } else if (x == 2 && (n & 1)) {
        cout << "Yes\n";
    } else
        cout << "No\n";
}
