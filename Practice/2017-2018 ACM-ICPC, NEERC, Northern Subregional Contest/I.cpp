#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("intel.in");
    ofstream out("intel.out");
    int n; in >> n;
    vector<pii> arr(n);
    for (auto &p : arr)
        in >> p.F >> p.S;
    LL sum = 0;
    LL minx = INF, maxx = -INF;
    LL miny = INF, maxy = -INF;
    for (int i = 0 ; i < n ; i++) {
        sum += abs(arr[i].F - arr[(i + 1) % n].F) + abs(arr[i].S - arr[(i + 1) % n].S);
        minx = min(minx, arr[i].F);
        maxx = max(maxx, arr[i].F);
        miny = min(miny, arr[i].S);
        maxy = max(maxy, arr[i].S);
    }
    out << sum - 2 * (maxx - minx + maxy - miny) << '\n';
}
