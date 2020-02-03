#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e7 + 5;
vector<int> isP, mu, ps;
void mobius() {
    isP.clear(); isP.resize(MAXN, 1);
    mu.resize(MAXN); isP[0] = isP[1] = 0; mu[1] = 1;
    for (int i = 2 ; i < MAXN ; i++) {
        if (isP[i]) ps.push_back(i), mu[i] = -1;
        for (auto &p : ps) {
            if (i * p >= MAXN) break;
            isP[i * p] = mu[i * p] = false;
            if (i % p == 0) break;
            mu[i * p] = -mu[i];
        }
    }
}

ll solve(ll a,ll b){
    ll ret = 0;
    for(int i = 1 ; i <= 10000000 ; i++){
        ret += mu[i] * (a / i) * (b / i);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,c,d;
    mobius();
    cin >> a >> b >> c >> d;
    cout << solve(b,d) - solve(a-1,d) - solve(c-1,b) + solve(a-1,c-1) << endl;
}
