#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long a, b; cin >> a >> b;
    long long g = __gcd(a, b);
    a /= g, b /= g;
    if (a % 2 == 0 || b % 2 == 0)
        cout << 0 << '\n';
    else
        cout << g << '\n';

}
