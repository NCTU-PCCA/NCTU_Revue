#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 100, m = 100; cout << n << ' ' << m << '\n';
    set<pair<int, int> > app;
    while (m--) {
        int u = rand() % n, v = rand() % n;
        if (u == v) { 
            m++; continue;
        }
        if (u > v) swap(u, v);
        if (app.count({u, v})) {
            m++;
            continue;
        }
        cout << u << ' ' <<  v << '\n';
        app.insert({u, v});
    }
}
