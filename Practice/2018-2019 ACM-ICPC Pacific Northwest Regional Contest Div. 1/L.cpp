#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data) {
        cin >> p.first >> p.second;
    }
    for (int i = n ; i >= 1 ; i--) {
        int cnt = 0;
        for (auto &p : data) {
            if (p.first <= i && i <= p.second)
                cnt++;
        }
        if (cnt != i)
            continue;
        cout << i << '\n';
        exit(0);
    }
    cout << -1 << '\n';

}
