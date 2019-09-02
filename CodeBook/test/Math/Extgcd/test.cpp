#include <bits/stdc++.h>
#include "../../../Math/Extgcd.cpp"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b; while (cin >> a >> b) {
        LL x, y;
        cout << extgcd(a, b, x, y);
        cout << ' ' << x << ' ' << y << '\n';
    }
}

