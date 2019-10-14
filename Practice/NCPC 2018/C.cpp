#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int a, b; cin >> a >> b;
        int maxV = 0;
        while (b--) {
            if ((a + 3) % 4 == 0) {
                if (a - 2 > 0) {
                    if ((a + 3) / 2 > a - 2)
                        a += 3,
                        a /= 2;
                    else
                        a -= 2;
                } else {
                    a += 3;
                    a /= 2;
                }
            } else 
                a += 3;
            maxV = max(maxV, a);
        }
        cout << maxV << '\n';
    }
}
