#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> data(m);
    for (auto &v : data)
        cin >> v;
    vector<pii> t(n, {0, 0});
    for (int i = 0 ; i < n ; i++)
        t[i].second = i + 1;
    for (int i = 0 ; i < n ; i++) {
        int cnt = 0;
        for (int j = 0 ; j < m ; j++) {
            int v; cin >> v;
            if (data[j] == v)
                cnt++;
        }
        t[i].first = -cnt;
    }
    sort(t.begin(), t.end());
    cout << t.front().second << '\n';

}
