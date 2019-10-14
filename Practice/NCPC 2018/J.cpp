#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int a[3], b[3];
        cin >> a[0] >> a[1] >> a[2];
        cin >> b[0] >> b[1] >> b[2];
        for (int i = 1 ; ; i++) {
            if (i % b[0] == a[0] && i % b[1] == a[1] && i % b[2] == a[2]) {
                cout << i << '\n';
                break;
            }
        }
    }

}
