#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; vector<LL> data(n);
    for (auto &v : data)
        cin >> v;
    vector<LL> res(n);
    res[0] = data[0];
    for (int i = 1 ; i < n ; i++)
        res[i] = data[i] - res[i - 1];
    LL Omin = INF;
    for (int i = 0 ; i < n ; i += 2)
        Omin = min(Omin, res[i]);
    LL Emax = 0;
    for (int i = 1 ; i < n ; i += 2)
        Emax = max(Emax, -res[i]);
    cout << max(0LL, Omin - Emax + 1) << '\n';
}
