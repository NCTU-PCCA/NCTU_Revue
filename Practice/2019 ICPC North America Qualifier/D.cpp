#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int mx = 0;
    vector<int> cnt(205, 1);
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        cnt[v] = 0;
        mx = max(mx, v);
    }
    int ok = 1;
    for (int i = 1 ; i <= mx ; i++) {
        if (cnt[i]) {
            ok = 0;
            cout << i << '\n';
        }
    }
    if (ok)
        cout << "good job\n";
    

}
