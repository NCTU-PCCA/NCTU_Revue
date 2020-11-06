#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> e(n), c(n);
    for (auto &v : e)
        cin >> v;
    for (auto &v : c)
        cin >> v;
    LL ans = max(0LL, e[n - 1] - c[n - 1]);
    if (k == 0) {               // k == 0
        LL sum = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            sum += e[i];
            ans = max(ans, sum - c[i]);
        }
    } else if (k == 1) {
        

    } else if (k >= 2) {
        LL sum = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            sum += e[i];
            ans = max(ans, sum - c[i]);
        }
        LL minV = INF;
        for (int i = n - 2 ; i >= 0 ; i--)
            minV = min(minV, c[i]);
        ans = max(ans, sum - minV);
    } else {
        
    }
    cout << ans << '\n';
}
