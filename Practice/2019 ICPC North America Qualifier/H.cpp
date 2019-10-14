#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
vector<vector<int> > G;
vector<vector<int> > dp;
int solve(int L, int R) {
    if (~dp[L][R]) return dp[L][R];
    if (R - L == 0 || R - L == 1)
        return dp[L][R] = 0;
    int mx = solve(L + 1, R);
    for (int i = L + 1 ; i < R ; i++) {
        if (!G[i][L])
            continue;
        mx = max(mx, 1 + solve(L + 1, i) + solve(i + 1, R));
    }
    return dp[L][R] = mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    G.clear(); G.resize(n, vector<int>(n));
    dp.clear(); dp.resize(n + 5, vector<int>(n + 5, -1));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    cout << solve(0, n) << '\n';
}
