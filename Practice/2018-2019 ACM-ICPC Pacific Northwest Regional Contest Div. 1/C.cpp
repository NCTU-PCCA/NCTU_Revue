#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int,int>mp;
    int n,k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int add;
        cin >> add;
        mp[add]++;
    }
    long long dp[1005][1005] = {};
    dp[0][0] = 1;
    int cur = 1;
    for(auto i:mp){
        for(int j = 0 ; j <= k ; j++){
            if(j==0){
                dp[cur][0] = 1;
            }
            else{
                dp[cur][j] = (dp[cur-1][j] + dp[cur-1][j-1] * i.second) % mod;
            }
        }
        cur++;
    }
    cout << dp[mp.size()][k] << '\n';
}
