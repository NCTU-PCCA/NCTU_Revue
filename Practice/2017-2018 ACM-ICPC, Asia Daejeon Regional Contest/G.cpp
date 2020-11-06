#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pii> Lp;
    set<LL> _X;
    _X.insert(INF); _X.insert(-INF);
    LL Ly0, Uy0;
    cin >> Ly0;
    Lp.push_back({-INF, Ly0});
    for (int i = 0 ; i < n ; i++) {
        pii p; cin >> p.F >> p.S;
        Lp.push_back(p);
        _X.insert(p.F);
    }

    vector<pii> Up;
    cin >> Uy0;
    Up.push_back({-INF, Uy0});
    for (int i = 0 ; i < m ; i++) {
        pii p; cin >> p.F >> p.S;
        Up.push_back(p);
        _X.insert(p.F);
    }
    vector<LL> X;
    for (auto &v : _X)
        X.push_back(v);
    vector<LL> L, U;
    int L_ptr = 0, U_ptr = 0;
    for (int i = 1 ; i < X.size() ; i++) {
        LL l = X[i - 1], r = X[i];
        if (l == -INF) {
            L.push_back(Ly0);
            U.push_back(Uy0);
        } else if (r == INF) {
            L.push_back(Lp.back().S);
            U.push_back(Up.back().S);
        } else {
            while (L_ptr < Lp.size() && Lp[L_ptr].F < r)
                L_ptr++;
            L.push_back(Lp[L_ptr - 1].S);
            while (U_ptr < Up.size() && Up[U_ptr].F < r)
                U_ptr++;
            U.push_back(Up[U_ptr - 1].S);
        }
    }
    /*
    cout << "L\n";
    for (int i = 1 ; i < X.size() ; i++) {
        cout << X[i - 1] << ' ' << X[i] << ": " << L[i - 1] << '\n';
    }

    cout << "U\n";
    for (int i = 1 ; i < X.size() ; i++) {
        cout << X[i - 1] << ' ' << X[i] << ": " << U[i - 1] << '\n';
    }
    */
    vector<int> ok;
    for (int i = 0 ; i < L.size() ; i++) {
        if (U[i] > L[i])
            ok.push_back(1);
        else
            ok.push_back(0);
    }
    for (int i = 0 ; i < ok.size() ; i++) {
        if (ok[i] == 0)
            break;
        ok[i] = 0;
    }
    for (int i = (int)ok.size() - 1 ; i >= 0 ; i--) {
        if (ok[i] == 0)
            break;
        ok[i] = 0;
    }
    LL sum = 0;
    for (int i = 0 ; i < ok.size() ; i++) {
        if (ok[i])
            sum += (X[i + 1] - X[i]) * (U[i] - L[i]);
    }
    LL cnt = 0;
    for (int i = 1 ; i < ok.size() ; i++) {
        if (ok[i] && !ok[i - 1])
            cnt++;
    }
    cout << cnt << ' ' << sum << '\n';

}
