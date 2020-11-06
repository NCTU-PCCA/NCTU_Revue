#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int S = 0, counter = 1, f = 1;
    cout << 1;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x >> x;
        if (i == 0)
            S = x;
        if (x == 0) break;
        if (S == x) {
            cout << ' ' << counter;
        } else {
            cout << ' ' << 1;
            S = x;
        }
        counter++;
    }
    cout << '\n';
}
