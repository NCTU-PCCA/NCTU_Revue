#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > data(n, vector<int>(3));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> data[i][j];
        }
        sort(data[i].begin(), data[i].end());
    }
    int maxV[3] = {0};
    for (auto &vv : data)
        for (int i = 0 ; i < 3 ; i++)
            maxV[i] = max(maxV[i], vv[i]);
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        if (data[i][1] > maxV[0] && data[i][2] > maxV[1])
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int i = 0 ; i < (int)ans.size() ; i++)
        cout << ans[i] + 1 << " \n"[i + 1 == (int)ans.size()];
    
}
