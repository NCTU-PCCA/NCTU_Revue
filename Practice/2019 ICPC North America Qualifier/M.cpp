#include <bits/stdc++.h>
using namespace std;
double solve(double a, double b) {
    return sqrt(a * a + b * b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        double w, g, h, r; cin >> w >> g >> h >> r;
        cout << fixed << setprecision(10) << solve(w, max(h, g) - min(g, h)) << ' ' << solve(w, g + h - 2 * r) << '\n';
    }


}
