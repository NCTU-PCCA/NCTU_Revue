#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
vector<double>v;
double ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    v.clear();
    f(n){
        double add;
        cin >> add;
        add /= 100;
        v.pb(add);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    double dp[n+5][n+5]={};
    dp[0][0]=1.0-v[0];
    dp[0][1]=v[0];
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]*(1.0-v[i]);
        for(int j=1;j<=i+1;j++){
            dp[i][j]+=dp[i-1][j-1]*v[i];
            dp[i][j]+=dp[i-1][j]*(1-v[i]);
        }
        
    }
    double ans = 0;
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=1;j<=i+1;j++){
            sum += pow((double)j,double(j)/double(i+1))*dp[i][j];
        }
        ans = max(ans,sum);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
