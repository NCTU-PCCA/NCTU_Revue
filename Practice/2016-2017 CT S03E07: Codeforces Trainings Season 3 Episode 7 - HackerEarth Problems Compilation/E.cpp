#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> w(n), h(n);
        for (auto &v : w)
            cin >> v;
        for (auto &v : h)
            cin >> v;
        reverse(w.begin(), w.end());
        sort(h.begin(), h.end());
        int sum = w.back() * h.back();
        w.pop_back();
        h.pop_back();
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        bool ok = true;
        for (int i = 0 ; i < n - 1 ; i++) 
            if (w[i] * h[i] >= sum)
                ok = false;
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
