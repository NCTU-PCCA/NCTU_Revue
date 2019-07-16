#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n; LL c, x; cin >> n >> c >> x;
        vector<LL> data(n);
        for (auto &v : data)
            cin >> v;
        sort(data.begin(), data.end());
        LL sum = 0, minV = n * c, cnt = 0;
        for (auto &v : data) {
            cnt++;
            minV = min(minV, cnt * x * v + c * (n - cnt));
        }
        cout << minV << '\n';
    }

}
