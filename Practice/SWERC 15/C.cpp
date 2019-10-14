#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        priority_queue<LL, vector<LL>, greater<LL> > pq;
        for (int i = 0 ; i < n ; i++) {
            LL v; cin >> v;
            pq.push(v);
        }
        LL ans = 0;
        while (pq.size() > 1) {
            LL x = pq.top(); pq.pop();
            LL y = pq.top(); pq.pop();
            pq.push(x + y);
            ans += x + y;
        }
        cout << ans << '\n';
    }
}
