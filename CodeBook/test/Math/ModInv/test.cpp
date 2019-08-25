#include <bits/stdc++.h>
#include "../../../Math/ModInv.cpp"
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b; while (cin >> a >> b)
        cout << modInv(a, b) << '\n';
}
