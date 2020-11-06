#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    int n = 1000, m = 30000;
    cout << n << ' ' << m << '\n';
    while (m--) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        int w = rand();
        cout << u << ' ' << v << ' ' << w << '\n';
    }
}
