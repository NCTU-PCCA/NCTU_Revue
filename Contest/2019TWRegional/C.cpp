#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    int f = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j) continue;
            for (int k = 0 ; k < n ; k++) {
                if (j == k) continue;
                if (i == k) continue;
                if (abs(data[i] - data[j]) % abs(data[k]) != 0) {
                    f = 1;
                }
            }
        }
    }
    if (f)
        cout << "no\n";
    else
        cout << "yes\n";
}
