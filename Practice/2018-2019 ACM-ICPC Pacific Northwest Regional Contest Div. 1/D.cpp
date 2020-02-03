#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define F first
#define S second
const int mod = 1e9+9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,b;
    cin >> k >> b;
    ll cnt[200][2000] = {};
    ll dp[200][2000] = {};
    cnt[0][0] = 1;
    int cur = 1;
    for(int i = 0 ; i < b ; i++){
        cur %= k;
        for(int j = 0 ; j < k ; j++){
            cnt[i+1][j] += cnt[i][j];
            cnt[i+1][j] %= mod;
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
            int nxt = (j + cur) % k;
            cnt[i+1][nxt] += cnt[i][j];
            cnt[i+1][nxt] %= mod;
            dp[i+1][nxt] += dp[i][j] + cnt[i][j];
            dp[i+1][nxt] %= mod;
        }
        cur *= 2;
    }
    cout << dp[b][0] << endl;
}
