#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int g = 0;
    while (n--) {
        int v; cin >> v;
        g = __gcd(abs(v), g);
    }
    cout << g << '\n';
}
