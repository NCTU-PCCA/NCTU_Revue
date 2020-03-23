#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
struct ST {
    LL (*op)(LL a, LL b);
    vector<vector<LL> > data;
    ST(vector<LL> &arr, LL (*_op)(LL a, LL b)) {
        op = _op;
        int n = (int)arr.size(), lgN = __lg(n) + 1;
        data.resize(lgN);
        for (int i = 0 ; i < n ; i++)
            data[0].push_back(arr[i]);
        for (int h = 1 ; h < lgN ; h++) {
            int len = 1 << (h - 1), i = 0;
            for (; i + len < n ; i++)
                data[h].push_back(op(data[h - 1][i], data[h - 1][i + len]));
            if (!i) break;
            for (; i < n ; i++)
                data[h].push_back(data[h - 1][i]);
        }
    }
    LL query(int l, int r) {
        int h = __lg(r - l), len = 1 << h;
        return op(data[h][l], data[h][r - len]);
    }
}*maxV, *minV;
bool check1(LL M) {
    int L = 0, R = data.size();
    while (R - L > 1) {
        int M = (R + L) >> 1;
        maxV->query(0, M)
    }
}
LL getMax(LL a, LL b) { return a > b ? a : b; }
LL getMin(LL a, LL b) { return a < b ? a : b; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<LL, LL> > data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    sort(data.begin(), data.end());
    vector<LL> l;
    for (auto &p : data)
        l.push_back(p.S);
    maxV = ST(l, getMax);
    minV = ST(l, getMin);

    LL L = -1, R = 1e9 + 5; while (R - L > 1) {
        LL M = (R + L) >> 1;
        if (check(M))
            M = L;
        else
            M = R;
    }
    
}
