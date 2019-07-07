#include<iostream>
#include<queue>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
const int maxn = 20005;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		s = " "+s;
		int pre[n+5][3] = {};
		f1(n){
			pre[i][0] = pre[i-1][0];
			pre[i][1] = pre[i-1][1];
			pre[i][2] = pre[i-1][2];
			if(s[i]=='P'){
				pre[i][1]++;
			}
			else if(s[i]=='S'){
				pre[i][2]++;
			}
			else{
				pre[i][0]++;
			}
		}
		int ans = 0;
		for(int i=0;i<=n;i++){
			for(int j=i;j<=n;j++){
				int mp = pre[i][2]-pre[0][2] + pre[j][0] - pre[i][0] + pre[n][1] - pre[j][1];
				int opp = pre[i][1]-pre[0][1] + pre[j][2] - pre[i][2] + pre[n][0] - pre[j][0];
				if(mp>opp)ans++;
 
			}
		}
		cout << ans << '\n';
	}
}
