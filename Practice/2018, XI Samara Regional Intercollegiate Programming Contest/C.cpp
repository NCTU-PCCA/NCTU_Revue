#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    sort(data.begin(), data.end(), [](pii a, pii b) {
        return a.S < b.S;
    });
    vector<LL> ans;
    for (int i = 0 ; i < n ; i++) {
        if (ans.size() == 0 || ans.back() < data[i].F)
            ans.push_back(data[i].S);
    }
    cout << ans.size() << '\n';
    for (int i = 0 ; i < (int)ans.size() ; i++)
        cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
}
