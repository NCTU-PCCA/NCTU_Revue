#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int maxV; cin >> maxV;
    int n; cin >> n;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    int m; cin >> m;
    vector<pair<int, pair<int, int> > > item(m);
    for (int i = 0 ; i < m ; i++) {
        cin >> item[i].S.F >> item[i].F; item[i].F--;
        item[i].S.S = i;
    }
    sort(item.begin(), item.end());
    vector<int> ans;
    while (1) {
        bool chg = false;
        if (item.back().F == n - 1)
            item.pop_back();
        if (item.size() == 0)
            break;
        for (int i = 0 ; i < item.size() ; i++) {
            bool legal = true;
            if (i > 0) {
                if (data[item[i].F + 1] - data[item[i - 1].F] > maxV)
                    legal = false;
            }
            if (i < item.size() - 1) {
                if (data[item[i + 1].F] - data[item[i].F + 1] < max(item[i].S.F, item[i + 1].S.F))
                    legal = false;
            }
            if (legal) {
                chg = true;
                ans.push_back(item[i].S.S + 1);
                item[i].F++;
            }
        }
        if (!chg) {
            cout << "impossible\n";
            exit(0);
        }
    }
    for (int i = 0 ; i < ans.size() ; i++)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
}
