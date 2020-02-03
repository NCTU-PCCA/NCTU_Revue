#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; 
    cin >> n;
    vector<int> data(n), pre{0};
    int mx = 0;
    for (auto &v : data)
        cin >> v, pre.push_back(pre.back() + v), mx = max(mx, v);
    vector<ll> ans(pre.back() + 1, -1);
    int q; cin >> q; while (q--) {
        int v; cin >> v;
        if (v < mx) {
            cout << "Impossible\n";
            continue;
        }
        if (~ans[v]) {
            cout << ans[v] << '\n';
            continue;
        }
        int sum = 0;
        int cnt = 0;
        while (sum != pre.back()) {
            sum = *prev(upper_bound(pre.begin(), pre.end(), sum + v));
            cnt++;
        }
        ans[v] = cnt;
        cout << cnt << '\n';
    }
}
