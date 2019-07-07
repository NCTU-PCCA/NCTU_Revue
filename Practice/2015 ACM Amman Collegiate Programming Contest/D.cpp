#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
const int maxn = 120005;
struct e{
	int x,y,w;
};
bool cmp(e x,e y){
	return x.w < y.w;
}
int d[maxn];
int fi(int x){
	return d[x] == x ? x : d[x] = fi(d[x]);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		s = " "+s;
		int dp[n+5] = {0};
		int l[n+5] = {},r[n+5] = {};
		f1(n){
			dp[i] = 1e6;
		}
		f1(n){
			l[i] = i-k;
		}
		r[1] = -1;
		fr(i,2,n+1){
			if(s[i] != s[i-1]){
				r[i] = r[i-1];
			}
			else{
				r[i] = i-2;
			}
		}
		f1(n){
			dp[i] = dp[i-1] + 1;
			for(int j = max(0,l[i]) ; j<= r[i] ; j++){
				dp[i] = min(dp[i],dp[j]+1);
			}
		}
		cout << dp[n]-1 << endl;
	}
}
