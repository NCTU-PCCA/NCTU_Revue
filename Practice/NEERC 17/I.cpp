#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
map<pii, string> ops;
string query(int L, int R) {
    if (ops.count({L + 1, R + 1}))
        return ops[{L + 1, R + 1}];
    cout << "? " << L + 1 << ' ' << R + 1 << endl;
    string res; cin >> res;
    return ops[{L + 1, R + 1}] = res;
}
pair<vector<int>, vector<int>> solve(auto &L, auto &R) {
    if (L.size() == 0) {
        if (R.size() >= 2) {
            return {{}, R};
        } else {
            return {{}, {}};
        }
    } else if (R.size() == 0) {
        if (L.size() >= 2) {
            return {L, {}};
        } else {
            return {{}, {}};
        }
    }
    int l = L[0], r = R[0];
    vector<int> Lm, Lb;
    for (int i = 0 ; i < L.size() ; i++) {
        if (query(L[i], r) == ">")
            Lb.push_back(L[i]);
        else
            Lm.push_back(L[i]);
    }
    vector<int> Rm, Rb;
    for (int i = 0 ; i < R.size() ; i++) {
        if (query(l, R[i]) == "<")
            Rb.push_back(R[i]);
        else
            Rm.push_back(R[i]);
    }
    auto xm = solve(Lm, Rm);
    
    for (auto &v : xm.F)
        Lb.push_back(v);
    for (auto &v : xm.S)
        Rb.push_back(v);

    auto xb = solve(Lb, Rb);
    return xb;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> L, R;
    for (int i = 0 ; i < n / 2 ; i++)
        L.push_back(i);
    for (int i = 0 ; i < n / 2 + n % 2 ; i++)
        R.push_back(i);
    auto res = solve(L, R);
    assert(res.F.size() == 0 && res.S.size() == 0);

}
