#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define fr(i,j,k) for (int i = j ; i < k ; i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int ed[3];
vector<pair<int,int>>g[3][55];
ll dp[3][51][125001];
int h[3][51];
ll solve(int x,int pos,int day) {
    if (~dp[x][pos][day]) {
         return dp[x][pos][day];
    }
    if (day == 0) {
        if (pos == 1) {
            return dp[x][pos][day] = 0;
        }
        else {
            return dp[x][pos][day] = 1e10;
        }
    }
    else {
        ll mi = 1e18;
        for (auto &i : g[x][pos]) {
            mi = min(mi, solve(x, i.F,day - 1) + i.S);
        }
        mi = min(mi, solve(x,pos,day - 1) + h[x][pos]);
        return dp[x][pos][day] = mi;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int z;
    cin >> z;
    memset(dp, -1, sizeof(dp));
    f(z) {
        int n, m;
        cin >> n >> m;
        fr(j,1,n+1) {
            cin >> h[i][j];
        }
        fr(j,0,m) {
            int x, y, z;
            cin >> x >> y >> z;
            g[i][y].pb({x,z});
        }
        //dij(i);
        //cout << "HERE" << endl;
        cin >> ed[i];
        //cout << ed[i] << endl;
    }
    ll mi = 9e18;
    fr(j,0,125001) {
        ll sum = 0;
        for (int k = 0 ; k < z ; k++) 
            sum += solve(k,ed[k],j);
        mi = min(mi, sum);
    }
    cout << mi << '\n';
}
