#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
using namespace std;
typedef pair<double, ll> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 4e6;
    vector<pii> data;
    for (ll i = 1 ; i <= n ; i++) {
        data.push_back({sin(i * 10), i * 10});
    }
    sort(data.begin(), data.end());
    vector<int> LIS;
    vector<int> pre;
    int idx = 0;
    for (auto &p : data) {
        int it = lower_bound(LIS.begin(), LIS.end(), p.second) - LIS.begin();
        pre.push_back(it);
        if (it == LIS.size())
            LIS.push_back(p.second);
        else
            LIS[it] = p.second;
    }
    vector<ll> res;
    int tar = LIS.size() - 1;
    for (int i = n - 1;  i >= 0 ; i--) {
        if (pre[i] == tar) {
            res.push_back(data[i].second);
            tar--;
        }
    }
    reverse(res.begin(), res.end());
    int x; cin >> x;
    for (int i = 0 ; i < x ; i++)
        cout << res[i] << '\n';
}
