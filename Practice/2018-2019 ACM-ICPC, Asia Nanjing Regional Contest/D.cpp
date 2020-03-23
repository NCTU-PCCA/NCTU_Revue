#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct P {
    double x, y, z;
};
double dist(P a, P b) {
    return sqrt((a.x - b.x) * (a.x - b.x)
              + (a.y - b.y) * (a.y - b.y)
              + (a.z - b.z) * (a.z - b.z));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<P> Ps(n);
    for (auto &p : Ps)
        cin >> p.x >> p.y >> p.z;
    P ans = {0, 0, 0};
    double lr = 10000, preR = 1e18;
    int t = 10000;
    while (t--) {
        vector<double> dists;
        for (auto &p : Ps)
            dists.push_back(dist(p, ans));
        int M = 0;
        for (int i = 0 ; i < n ; i++) {
            if (dists[M] < dists[i])
                M = i;
        }
        P delta = {Ps[M].x - ans.x, Ps[M].y - ans.y, Ps[M].z - ans.z};
        double len = dist(delta, {0, 0, 0});
        delta.x /= len;
        delta.y /= len;
        delta.z /= len;
        delta.x *= lr;
        delta.y *= lr;
        delta.z *= lr;
        ans.x += delta.x;
        ans.y += delta.y;
        ans.z += delta.z;
        double R = 0;
        for (auto &p : Ps)
            R = max(R, dist(p, ans));
//        cout << ans.x << ' ' << ans.y << ' ' << ans.z << '\n';
        // cout << fixed << setprecision(10) << R << ' ' << lr << '\n';
        preR = R;
        lr *= 0.99;
    }
    cout << fixed << setprecision(20) << preR << '\n';
}
