#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<long long, long long> pii;
double dist(pii a, pii b) {
    return (int)(sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S)) * 100) / 100.0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<pii> data(n);
        for (auto &p : data)
            cin >> p.F >> p.S;
        double minV = 1e18;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < i ; j++) 
                minV = min(minV, dist(data[i], data[j]));
        cout << fixed << setprecision(2) << minV << '\n';
    }
}
