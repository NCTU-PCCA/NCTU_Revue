#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL solve(int n, LL r, LL p, auto &ans) {
    if (ans.count(n)) return ans[n];
    if (n == 1) return ans[n] = 0;
    ans[n] = INF;
    for (int i = 1 ; i < n ; i++) {
        ans[n] = min(ans[n], solve((n - 1) / (i + 1) + 1, r, p, ans) + i * p + r);
    }
    return ans[n];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL r, p; cin >> n >> r >> p;
    map<int, LL> ans;
    cout << solve(n, r, p, ans) << '\n';
}
