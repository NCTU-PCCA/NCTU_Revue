#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const int MAXN = 4005;
const double PI = acosl(-1);
struct B {
    double x, y;
    LL g;
};
bool ang(double x, double y) {
    double diff = y - x;
    while (diff < 0) {
        diff += 2 * PI;
    }
    return diff <= PI;
}
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    B data[MAXN];
    for (int i = 0 ; i < n ; i++) {
        cin >> data[i].x >> data[i].y >> data[i].g;
    }
    if (n == 2) {
        cout << 0 << '\n';
        exit(0);
    }
    LL minV = INF;
    for (int i = 0 ; i < n ; i++) {
        vector<pair<double, LL> > vec;
        for (int j = 0 ; j < n ; j++) {
            if (i == j)
                continue;
            vec.push_back({atan2(data[j].y - data[i].y, data[j].x - data[i].x), data[j].g});
        }
        sort(vec.begin(), vec.end());
        LL sum = 0;
        for (int i = 0 ; i < vec.size() ; i++)
            sum += vec[i].S;
        int R = 0; LL cur = 0;
        for (int L = 0 ; L < vec.size() ; cur -= vec[L].S, L++) {
            if (L == R)
                cur = vec[R].S, R++;
            if (R == vec.size())
                R = 0;
            while (R != L && ang(vec[L].F, vec[R].F)) {
                cur += vec[R].S, R++;
                if (R == vec.size())
                    R = 0;
            }
            minV = min(minV, abs((sum - cur) - (cur - vec[L].S)));
        }
    }
    cout << minV << '\n';
}
