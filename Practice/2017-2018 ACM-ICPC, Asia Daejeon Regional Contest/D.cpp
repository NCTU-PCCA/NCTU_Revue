#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
LL next(LL x) {
    LL ret = 0;
    while (x) {
        LL y = x % 10;
        ret += y * y;
        x /= 10;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    set<LL> st;
    while (1) {
        LL nx = next(n);
        if (st.count(nx))
            break;
        if (nx == 1) {
            cout << "HAPPY\n";
            return 0;
        }
        st.insert(nx);
        n = nx;
    }
    cout << "UNHAPPY\n";
}
