#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll way[30+5][30+5][15000];
ll dp[30+5][30+5][15000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m; ll k;
    cin >> n >> m >> k;
    int b[n+5][m+5]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> b[i][j];
        }
    }
    int now = 0;
    for(int i=1;i<=n;i++){
        now += b[i][1];
        dp[i][1][now]=1;
    }
    now = 0;
    for(int i=1;i<=m;i++){
        now += b[1][i];
        dp[1][i][now]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            for(int k=b[i][j];k<=14000;k++){
                dp[i][j][k]=dp[i-1][j][k-b[i][j]]+dp[i][j-1][k-b[i][j]];
            }
        }
    }
   /* 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<i<<' '<<j<<endl;
            for(int k = 1 ;k<=30;k++){
                cout<<dp[i][j][k]<<' ';
            }
            cout << '\n';
        }
    }
    */
    ll pre[15000]={};
    ll tar,th;
    for (int i=14000;i>=0;i--){
        pre[i]=pre[i+1]+dp[n][m][i];
        if(pre[i]>=k){
            tar = i;
            th = k-pre[i+1];
            break;
        }
    }
    //cout<<tar<<' '<<th<<endl;
    way[n][m][tar]=1;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            for(int k=b[i][j];k<=14000;k++){
                way[i-1][j][k-b[i][j]]+=way[i][j][k];
                way[i][j-1][k-b[i][j]]+=way[i][j][k];
            }
        }
    }
    ll tot[n+5][m+5]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=14000;k++){
                //tot[i][j]+=way[i][j][k]*dp[i][j][k];
                tot[i][j]+=way[i][j][k];
            }
        }
    }
    
    int sum = b[1][1];
    int nx = 1,ny = 1;
    int t = n+m-2;
    string ans;
    while(t--){
        if(way[nx+1][ny][sum+b[nx+1][ny]]<th){
            th -= way[nx+1][ny][sum+b[nx+1][ny]];
            ans+="R";
            sum += b[nx][ny+1];
            ny++;
        }
        else{
            ans+="D";
            sum += b[nx+1][ny];
            nx++;
        }
    }
    cout << ans << endl;
}

