#include <bits/stdc++.h>
#define F first
#define S second
#define sqr(x) ((x) * (x))
using namespace std;
typedef pair<double, double> pii;
double dist(pii a, pii b) {
    return sqrt(sqr(a.F - b.F) + sqr(a.S - b.S));
}
double cross(pii o, pii a, pii b) {
    pii x = {a.F - o.F, a.S - o.S};
    pii y = {b.F - o.F, b.S - o.S};
    return x.F * y.S - y.F * x.S;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        vector<pii> arr(20);
        for (auto &v : arr)
            cin >> v.F >> v.S;
        vector<double> res;
        int a = -1, b = -1, c = -1;
        for (int i = 0 ; i < 20 ; i++) {
            double d = dist(arr[i], arr[(i + 1) % 20]);
            if (abs(d - 9) < 1e-5) {
                a = (i - 1 + 20) % 20;
                b = i;
                c = (i + 1) % 20;
            }
        }
        // dist(b, c) -> 9
        if (abs(dist(arr[a], arr[b]) - 6) < 1e-5) {
            a = (c + 1) % 20;
            swap(b, c);
        }
        if (cross(arr[b], arr[a], arr[c]) > 0) {
            cout << "right\n";
        } else {
            cout << "left\n";
        }
    }
}
