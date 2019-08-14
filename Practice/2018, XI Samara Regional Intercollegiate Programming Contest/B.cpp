#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL area(pii a, pii b, pii c) {
    return a.F * b.S + b.F * c.S + c.F * a.S - (a.S * b.F + b.S * c.F + c.S * a.F);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    data.push_back(data[0]);
    data.push_back(data[1]);
    LL minV = INF;
    for (int i = 0 ; i < n ; i++)
        minV = min(minV, area(data[i], data[i + 1], data[i + 2]));
    cout << minV << '\n';
}
