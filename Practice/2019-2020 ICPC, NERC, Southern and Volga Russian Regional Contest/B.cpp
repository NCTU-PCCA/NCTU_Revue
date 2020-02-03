#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, k; cin >> n >> k;
    vector<long long> cnt(k, 0);
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v, v--;
        cnt[v]++;
    }
    if (k == 1) {
        cout << n << '\n';
        exit(0);
    }
    sort(cnt.begin(), cnt.end());
    long long ans = INF;
    for (long long i = 1 ; i < k ; i += 2) {
        long long c = 0, sz = 0;
        long long x = 0, y = i;
        while (x < y) {
            sz = max(sz, cnt[x] + cnt[y]);
            x++, y--;
            c++;
        }
        c += k - (i + 1);
        sz = max(sz, cnt.back());
        ans = min(ans, c * sz);
    }
    cout << min(ans, cnt.back() * k) << '\n';
}
