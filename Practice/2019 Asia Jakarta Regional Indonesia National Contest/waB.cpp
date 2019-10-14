#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<LL, int> pii;
bool small(pii a, pii b) {
    return a.F * b.S < b.F * a.S;
}
bool large(pii a, pii b) {
    return a.F * b.S > b.F * a.S;
}
bool equal(pii a, pii b) {
    return a.F * b.S == b.F * a.S;
}
bool check(LL M, LL h, vector<pii> data) {
    LL sumM = 0, sumH = 0;
    int n = data.size();
    while (1) {
        vector<vector<pii> > list(n);
        for (int i = 0 ; i < n ; i++) {
            list[i].push_back({0, 0});
            LL power = data[i].F;
            LL value = data[i].S;
            while (value) {
                LL cost = (value - 1) / 2 + 1;
                list[i].push_back({list[i].back().F + power, list[i].back().S + cost});
                value /= 2;
                power *= 2;
            }
        }
        for (auto &vv : list) {
            for (auto &p : vv)
                cout << "(" << p.F << "," << p.S << "),";
            cout << '\n';
        }
        int idx = -1; pii maxV = {0, 1};
        if (M == 31) {
            for (auto &v : data)
                cout << v.F << ' ' << v.S << '\n';
        }
        for (int i = 0 ; i < data.size() ; i++) {
            if (data[i].S == 0)
                continue;
            int cost = (data[i].S - 1) / 2 + 1;
            if (sumM + cost > M)
                continue;
            if (small(maxV, {data[i].F, cost})) {
                maxV = {data[i].F, cost};
                idx = i;
            } else if (equal(maxV, {data[i].F, cost})) {
                if (maxV.S > cost) {
                    idx = i;
                    maxV = {data[i].F, cost};
                }
            }
        }
        if (M == 31) {
            cout << "find: " << idx << '\n';
            cout << "maxV: " << maxV.F << ' ' << maxV.S << '\n';
        }
        if (idx == -1) return false;
        sumH += maxV.F;
        sumM += maxV.S;
        data[idx].F *= 2;
        data[idx].S /= 2;
        if (sumH >= h || sumM > M)
            break;
    }
    return sumM <= M;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL h; cin >> n >> h;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    vector<pii> test = data;
    LL sum = 0;
    for (int i = 0 ; i < n ; i++) {
        while (test[i].S) {
            test[i].S /= 2;
            sum += test[i].F;
            test[i].F *= 2;
            if (sum >= h)
                break;
        }
        if (sum >= h)
            break;
    }
    if (sum < h) {
        cout << -1 << '\n';
        exit(0);
    }
    LL L = 0, R = INF;
    while (R - L > 1) {
        LL M = (L + R) >> 1;
        cout << M << endl;
        if (check(M, h, data))
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}
