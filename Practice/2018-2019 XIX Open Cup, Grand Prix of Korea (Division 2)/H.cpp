#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> data(n);
    for (auto &v : data)
        cin >> v;
    int q; cin >> q;
    vector<int> Q(q);
    map<int, pair<int, int> > s;
    for (auto &v : Q)
        cin >> v, s[v] = {0, 0};
    vector<int> dec(n, 1), inc(n, 1);
    for (int i = n - 2 ; i >= 0 ; i--) {
        if (data[i] <= data[i + 1])
            inc[i] = inc[i + 1] + 1;
        if (data[i] > data[i + 1])
            dec[i] = dec[i + 1] + 1;
    }
    for (auto &p : s) {
        int v = p.F, cur = 0;
        while (cur < n) {
            if (inc[cur] < dec[cur]) {
                if (dec[cur] < v && cur + dec[cur] != n)
                    p.S.S += min(n - cur - dec[cur], v - dec[cur]);
                p.S.F++;
                cur += max(v, dec[cur]);
            } else {
                if (inc[cur] < v && cur + inc[cur] != n)
                    p.S.S += min(n - cur - inc[cur], v - inc[cur]);
                p.S.F++;
                cur += max(v, inc[cur]);
            }
        }
    }
    for (auto &v : Q)
        cout << s[v].F << ' ' << s[v].S << '\n';
}
