#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e10;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<ll> data;
    for (int i = 0 ; i < 35 ; i++) {    // 2
        ll now = 1;
        int t = i;
        while(t--){
            now *= 2;
        }
        data.push_back(now);
        for (int j = 0 ;; j++) {    // 3
            now*=3;
            if(now<inf){
                data.push_back(now);
            } else break;
        }
    }
    sort(data.begin(), data.end());
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        auto it = upper_bound(data.begin(), data.end(), n);
        double pre = *prev(it) / (double)n;
        double suf = (double)n / *it;
        if (pre > suf)
            cout << *prev(it) << '\n';
        else
            cout << *it << '\n';
    }
}
