#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> ans;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        if (v == 0)
            cnt++;
        else if (v > 0) {
            mp[v]++;
        } else {
            v = -v;
            if (mp.count(v)) {
                mp[v]--;
                if (mp[v] == 0)
                    mp.erase(v);
            } else if (cnt != 0) {
                cnt--;
                ans.push_back(v);
            } else {
                cout << "No\n";
                return 0;
            }
        }
    }
    while (cnt--) {
        ans.push_back(1);
    }
    cout << "Yes\n";
    for (int i = 0 ; i < ans.size() ; i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
}
