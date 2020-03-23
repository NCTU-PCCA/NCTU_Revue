#include <bits/stdc++.h>
using namespace std;
bool check(int n, int a, int b) {
    if (a + b > n) return false;
    if (n % (a + b) == 0) return true;
    if ((n - a) % (a + b) == 0) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 2 ; i <= n / 2 + 1; i++) {
        if (check(n, i, i - 1))
            cout << i << ' ' << i - 1 << '\n';
        if (check(n, i, i))
            cout << i << ' ' << i << '\n';
    }

}
