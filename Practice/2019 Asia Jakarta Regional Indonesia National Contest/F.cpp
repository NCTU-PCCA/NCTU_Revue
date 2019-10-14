#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        ans += v; ans %= 2;
    }
    if (ans)
        cout << "John\n";
    else
        cout << "Preston\n";

}
