#include <bits/stdc++.h>
#define F first
#define S second
#define sq(x) (x)*(x)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
// LatexBegin
vector<LL> h, dp;
LL C;
LL a(int i) { return -2 * h[i]; }
LL b(int i) { return dp[i] + sq(h[i]); }
LL x(int i) { return h[i]; }
LL c(int i) { return sq(h[i]) + C; }
bool check(int X, int Y, int Z) {
    return (b(Z) - b(Y)) * (a(X) - a(Z)) <= (b(Z) - b(X)) * (a(Y) - a(Z));
}
void marmot0814() {
    int n; cin >> n >> C;
    h.resize(n);
    for (auto &v : h) cin >> v;
    dp.clear(); dp.resize(n, 0);
    // dp[i] = min{0<=j<i}(dp[j] + sq(h[i] - h[j]) + C)
    //       = min{0<=j<i}(dp[j] + sq(h[i]) + sq(h[j]) + C - 2 * h[i] * h[j]
    //       = min{0<=j<i}( -2*h[j] * h[i] + dp[j]+sq(h[j]) ) + sq(h[i])+C
    vector<int> dq{0};
    for (int i = 1 ; i < n ; i++) {
        int L = 0, R = dq.size();
        while (R - L > 2) {
            int M  = (R + L) >> 1;
            int MM = (R + M) >> 1;
            if (a(dq[M]) * x(i) + b(dq[M]) >= a(dq[MM]) * x(i) + b(dq[MM]))
                L = M;
            else
                R = MM;
        }
        L = dq[L], R = dq[R - 1];
        dp[i] = min(a(L) * x(i) + b(L), a(R) * x(i) + b(R)) + c(i);
        while (dq.size() >= 2 && check(dq[dq.size() - 2], dq[dq.size() - 1], i))
            dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n - 1] << '\n';
}
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}
