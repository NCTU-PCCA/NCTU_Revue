#include <bits/stdc++.h>
#define F first
#define S second
#define sq(x) (x) * (x)
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<LL, LL> pii;
double cal(vector<pii> L, vector<pii> R) {
    LL lmax = -INF, rmin = INF;
    for (auto &p : L)
        lmax = max(lmax, p.F);
    for (auto &p : R)
        rmin = min(rmin, p.F);
    for (auto &p : R)
        p.F -= rmin, p.F += lmax;
    double minV = INF;
    {
        set<pii> st;
        for (auto &p : L)
            st.insert({p.S, p.F});
        for (auto &p : R) {
            auto it = st.lower_bound({p.S, -INF});
            pii u, d;
            if (it != st.begin()) {
                u = *prev(it);
                d = *it;
            } else {
                u = *it;
                d = *next(it);
            }
            swap(u.F, u.S);
            swap(d.F, d.S);
            pii v = {u.F - d.F, u.S - d.S};
            double r = double(p.S - d.S) / (u.S - d.S);
            double x = d.F + r * (u.F - d.F);
            minV = min(minV, p.F - x);
        }
    }
    {
        set<pii> st;
        for (auto &p : R)
            st.insert({p.S, p.F});
        for (auto &p : L) {
            auto it = st.lower_bound({p.S, -INF});
            pii u, d;
            if (it != st.begin()) {
                u = *prev(it);
                d = *it;
            } else {
                u = *it;
                d = *next(it);
            }
            swap(u.F, u.S);
            swap(d.F, d.S);
            pii v = {u.F - d.F, u.S - d.S};
            double r = double(p.S - d.S) / (u.S - d.S);
            double x = d.F + r * (u.F - d.F);
            minV = min(minV, x - p.F);
        }
    }
    return minV;
}
double solve(int S, int u, auto &d, auto &dp) {
    if (dp[S][u] != -1) return dp[S][u];
    if (__builtin_popcount(S) == 1)
        return dp[S][u] = 0;
    S ^= (1 << u);
    int n = d.size();
    double maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        if (!(S & (1 << i))) continue;
        maxV = max(maxV, solve(S, i, d, dp) + d[u][i]);
    }
    S ^= (1 << u);
    return dp[S][u] = maxV;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<pii>> L(n), R(n);
    double sum = 0;
    for (int i = 0 ; i < n ; i++) {
        int m; cin >> m;
        vector<pii> ps(m);
        LL minV = INF, maxV = -INF;
        for (auto &p : ps) {
            cin >> p.F >> p.S;
            minV = min(minV, p.F);
            maxV = max(maxV, p.F);
        }
        sum += maxV - minV;
        int ptr = 0;
        for (int j = 0 ; j < m - 1 ; j++)
            if (ps[j].S - ps[j + 1].S == 0)
                ptr = j;
        for (int j = 1 ; j <= ptr ; j++)
            R[i].push_back(ps[j]);
        for (int j = ptr + 1 ; j < m ; j++)
            L[i].push_back(ps[j]);
        L[i].push_back(ps[0]);
        reverse(L[i].begin(), L[i].end());
    }
    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (i == j)
                continue;
            d[i][j] = cal(R[i], L[j]);
        }
    }
    double ans = 0;
    for (int i = 0 ; i < n ; i++) {
        vector<vector<double>> dp(1 << n, vector<double>(n, -1));
        ans = max(ans, solve((1 << n) - 1, i, d, dp));
    }
    cout << fixed << setprecision(3) << sum - ans << '\n';
}
