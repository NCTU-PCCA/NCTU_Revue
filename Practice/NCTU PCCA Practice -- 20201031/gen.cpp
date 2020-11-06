#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 1000;
    for (int i = 1 ; i <= t ; i++) {
        double x = (double)(rand() % 1000000) / 1000000;
        cout << i << ' ' << 1000000 << ' ' << x << '\n';
    }
}
