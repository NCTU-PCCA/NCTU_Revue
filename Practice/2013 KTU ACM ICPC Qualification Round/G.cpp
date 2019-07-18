#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
const int mod = 1e9+7;
ll pm(ll x){
	int p = mod-2;
	ll ret = 1;
	ll now = x;
	while(p){
		if(p&1){
			ret *= now;
			ret %= mod;
		}
		now *= now;
		now %= mod;
		p >>= 1;
	}
	return ret;
}
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >>t;
	for(int c=1;c<=t;c++){
		int n;
		int ans = 0;
		map<int,int>mp;
		map<int,int>inv;
		cin >> n;
		f1(n){
			int add;
			cin >> add;
			inv[add] = pm(add);
			mp[add]++;
		}
		for(auto i:mp){
			int num = i.first;
			int in = inv[num];
			ans += min(mp[num],mp[in]);
		}
		ans >>= 1;
		printf("Case #%d: %d\n",c,ans);
	}
}
