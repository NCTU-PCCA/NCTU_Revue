#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int minV = INF;
    for (int i = 1 ; i <= n ; i++) {
        if (n % i != 0)
            continue;
        minV = min(minV, 2 * (i + n / i));
    }
    cout << minV << '\n';
}
