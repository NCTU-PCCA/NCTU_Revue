#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int t = 100; while (t--) {
        int n = 1e5;
        cout << n << ' ' << 1 << '\n';
        while (n--) {
            cout << rand() % 1000000000 + 1 << ' ';
        }
        cout << '\n';
    }
}
