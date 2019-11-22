#include <bits/stdc++.h>
#include "Point.cpp"
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<P> ps(n);
        for (auto &p : ps)
            cin >> p.x >> p.y;
        cout << Annealing(ps) << '\n';
    }
}
