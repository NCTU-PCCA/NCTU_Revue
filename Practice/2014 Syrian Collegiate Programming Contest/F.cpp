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
 
int main(){
	int t;
	cin >> t;
	for(int cc=1;cc<=t;cc++){
		ll n,m;
		cin >> n >> m;
		if(m==1){
			printf("Case %d: 0 0\n",cc);
		}
		else{
			ll now = 0;
			for(ll i = 1LL<<31;i ; i>>=1){
				ll cur = now + i;
				if(cur*(cur+1)/2<m){
					now = cur;
				}
			}
			printf("Case %d: %lld %lld\n",cc,now,m-1-(now+1)*now/2);
		}
	}
}
