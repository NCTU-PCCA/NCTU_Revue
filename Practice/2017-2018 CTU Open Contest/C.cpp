#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; string t; while (cin >> n >> t) {
        if (t == "K") {
            if (n == 1) {
                cout << 1 << '\n';
            } else {
                cout << 4 << '\n';
            }
        } else if (t == "N") {
            if (n <= 2) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        } else if (t == "B") {
            cout << n << '\n';
        } else if (t == "R") {
            cout << n << '\n';
        }
    }
}
