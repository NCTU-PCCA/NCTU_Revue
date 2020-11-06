#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    LL sum = 0;
    for (auto &v : arr)
        cin >> v, sum += v;
    if (sum == 100) {
        cout << "Yes\n";
    } else if (sum > 100) {
        int cnt = 0;
        for (auto &v : arr)
            if (v != 0)
                cnt++;
        if (sum - cnt / 2 <= 100)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else {
        if (n % 2) {
            if (sum + n / 2 >= 100) {
                cout << "Yes\n";
            } else
                cout << "No\n";
        } else {
            if (sum + n / 2 > 100) {
                cout << "Yes\n";
            } else 
                cout << "No\n";
        }
    }
}
