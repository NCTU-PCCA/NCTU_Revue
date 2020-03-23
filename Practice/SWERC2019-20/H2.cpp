#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL cur = 29466792348;
    set<LL> pool;
    for (LL i = 3e8 ; ; i++) {
        if (pool.count(cur)) {
            cout << i << '\n';
            break;
        }
        bitset<40> x = cur;
//        cout << setw(5) << i << ' ' << x << ' ' << cur << '\n';
//        cout << "      --------------------\n";
        pool.insert(cur);
        cur = (cur + (cur >> 20) + 12345) % (1LL << 40);
    }
}
