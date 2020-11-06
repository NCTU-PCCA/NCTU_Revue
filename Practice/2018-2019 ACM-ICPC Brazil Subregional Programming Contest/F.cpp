#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
vector<int>d;
int dp[1005][1025];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int,int>,pair<int,int>>>v;
    for (int i = 0 ; i < n ; i++) {
        int k;
        cin >> k;
        while (k--) {
            int st, ed, val;
            cin >> st >> ed >> val;
            v.push_back({{ed, st},{i,val}});
        }
    }
    memset(dp, -1, sizeof(dp));
    v.push_back({{0,0},{0,0}});
    sort(v.begin(), v.end());
    dp[0][0] = 0;
    for (int i = 0 ; i < v.size() - 1; i++) {
        for (int j = 0 ; j < (1<<n) ; j++) {
            if (dp[i][j] == -1)continue;
            for (int k = i + 1 ; k < v.size() ; k++) {
                if (v[k].F.S >= v[i].F.F) {
                    dp[k][j|(1<<v[k].S.F)] = max(dp[k][j|(1<<v[k].S.F)],dp[i][j] +v[k].S.S);
                }
            }
        }
    }
    int mx = -1;
    for(int i = 0 ; i < v.size() ; i++) {
        mx = max(mx, dp[i][(1<<n)-1]);
    }
    cout << mx << '\n';
}
