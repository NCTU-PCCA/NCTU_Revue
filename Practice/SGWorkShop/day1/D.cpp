#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b; cin >> a >> b;
    set<LL> pool;
    while (1) {
        if (pool.count(b)) {
            cout << -1 << '\n';
            exit(0);
        }
        pool.insert(b);
        LL tmp = (a - 1) / b + 1;
        b = b * tmp - a;
        if (b == 0 || a % b == 0) {
            cout << pool.size() + (b != 0) << '\n';
            exit(0);
        }
    }
}
