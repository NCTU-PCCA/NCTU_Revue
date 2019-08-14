#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
pii trim(pii x) {
    LL g = __gcd(x.F, x.S);
    x.F /= g, x.S /= g;
    if (x.F < 0)
        x.F *= -1, x.S *= -1;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    map<pii, set<double> > cnt;
    while (m--) {
        LL x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        pii M = {y2 - y1, x2 - x1};
        M = trim(M);
        LL a = y2 - y1;
        LL b = - (x2 - x1);
        LL c = - (a * x1 + b * y1);
        if (M.F == 0) {
            cnt[M].insert(-(double)c / b);
        } else if (M.S == 0) {
            cnt[M].insert(-(double)c / a);
        } else {
            cnt[M].insert(-(double)c / a);
        }
    }
    if (cnt.size() == 1) {
        if (n <= cnt.begin()->second.size() + 1) {
            cout << 0 << '\n';
        } else {
            cout << max(1, (n - 1) / 2 + 1 - (int)cnt.begin()->second.size()) << '\n';
        }
    } else {
        int sum = 0;
        for (auto &p : cnt)
            sum += p.second.size();
        if (n <= 2 * sum) {
            cout << 0 << '\n';
        } else {
            cout << (n - 1) / 2 + 1 - sum << '\n';
        }
    }
}
