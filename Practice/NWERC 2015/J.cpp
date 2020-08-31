#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int f(int x) {
    return (x ^ (x << 1)) % 256;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        for (int i = 0 ; i < 256 ; i++) {
            if (f(i) == x) {
                cout << i << ' ';
                break;
            }
        }
    }
}
