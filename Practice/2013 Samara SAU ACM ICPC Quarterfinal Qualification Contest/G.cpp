#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<long long> data;
    for (long long i = 0 ; i * i < 1e10 ; i++)
        data.insert(i * i);
    int n; cin >> n;
    for (auto &p : data) {
        if (p > n)
            break;
        if (data.count(n - p)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

}
