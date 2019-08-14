#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> data(n);
    LL minV = INF;
    for (auto &v : data)
        cin >> v, minV = min(minV, v);
    LL cur = 0, ans = 0;
    for (int i = 0 ; i < k - 1 ; i++)
        cur += data[i];
    for (int i = k - 1 ; i < n ; i++) {
        cur += data[i];
        if (cur >= 0) {
            ans += cur + 1;
            int pos = i; LL v = cur + 1;
            while (v > 0) {
                LL tmp = data[pos] - minV;
                data[pos] -= min(tmp, v);
                v -= min(tmp, v);
                pos--;
            }
            cur = -1;
        }
        cur -= data[i - k + 1];
    }
    cout << ans << '\n';
    for (int i = 0 ; i < n ; i++)
        cout << data[i] << " \n"[i + 1 == n];
}
