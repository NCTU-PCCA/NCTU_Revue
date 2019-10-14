#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data1(n), data2(n);
    for (auto &v : data1)
        cin >> v;
    for (auto &v : data2)
        cin >> v;
    for (int x = 0 ; ; x++) {
        if (data1 >= data2) {
            cout << x << '\n';
            return 0;
        }
        for (auto &v : data1)
            v++;
    }
}
