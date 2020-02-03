#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 1e5, m = 2e5, s = 10;
    cout << n << ' ' << m << ' ' << s << '\n';
    LL sum = 0;
    for (int i = 0 ; i < n ; i++) {
        int v = rand() % 10;
        sum += v;
        cout << v << ' ';
    }
    cout << '\n';
    LL sum2 = 0;
    for (int i = 0 ; i < n - 1 ; i++) 
        cout << i + 1 << ' ' << i + 2 << ' ' << rand() % 10000 << '\n', m--;
    while (m--)
        cout << rand() % n + 1 << ' ' << rand() % n + 1 << ' ' << rand() % 100000 << '\n';
    s--;
    while (s--) {
        int v = rand() % 1000;
        cout << rand() % n + 1 << ' ' << v << '\n';
        sum2 += v;
    }
    cout << rand() % n + 1 << ' ' << 2 * sum - sum2 << '\n';
}
