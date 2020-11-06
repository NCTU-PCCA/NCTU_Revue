#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    int d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << max(0, - a + d) + max(0, - b + e) + max(0, - c + f) << '\n';
}
