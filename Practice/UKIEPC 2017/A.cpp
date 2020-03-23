#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, pair<int, int> > > day(n);
    int M = 0;
    for (auto &d : day)
        cin >> d.first >> d.second.first >> d.second.second, M = max(M, d.first);

    for (int i = 0 ; i < 1825 * M ; i++) {
        bool ok = true;
        for (auto &d : day) {
            int h = i % d.first;
            if (d.second.first < d.second.second) {
                if (d.second.first < h && h < d.second.second)
                    ok = false;
            } else {
                if (d.second.first < h || h < d.second.second)
                    ok = false;
            }
        }
        if (ok) {
            cout << i << '\n';
            exit(0);
        }
    }
    cout << "impossible\n";
}
