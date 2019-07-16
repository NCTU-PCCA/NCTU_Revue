#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        cout << "Case " << ++kase << ": " << (h2 - h1) * 60 + (m2 - m1) << '\n';
    }

}
