#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
struct KeyHasher {
    size_t operator() (const pii &b) const {
        return b.F + b.S * 100000;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int g; cin >> g;
    int ans = g;
    unordered_map<pii, int, KeyHasher> mp;
    while (g--) {
        pii p; cin >> p.F >> p.S;
        mp[p]++;
    }
    int m; cin >> m;
    while (m--) {
        pii x; cin >> x.F >> x.S; LL r; cin >> r;
        for (int i = -r ; i <= r ; i++) {
            for (int j = -r ; j <= r ; j++) {
                if (i * i + j * j <= r * r) {
                    pii t = {x.F + i, x.S + j};
                    if (mp.count(t)) {
                        ans -= mp[t];
                        mp.erase(t);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
