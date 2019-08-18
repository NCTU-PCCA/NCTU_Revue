#include <bits/stdc++.h>
using namespace std;
bool isS(int x) {
    int t = sqrt(x) + 1e-5;
    return t * t == x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    if (isS(a * a + b * b) || isS(b * b - a * a))
        cout << "YES\n";
    else
        cout << "NO\n";
}
