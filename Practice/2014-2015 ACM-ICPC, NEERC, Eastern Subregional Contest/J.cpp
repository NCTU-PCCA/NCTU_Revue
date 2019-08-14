#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> t1, t2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        t1.push_back({v, i});
        sum1 += v;
    }
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        t2.push_back({v, i});
        sum2 += v;
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (sum1 < sum2) {
        reverse(t1.begin(), t1.end());
    } else {
        reverse(t2.begin(), t2.end());
    }
    for (int i = 0 ; i < n ; i++) {
        cout << t1[i].second + 1 << ' ' << t2[i].second + 1 << '\n';
    }
}
