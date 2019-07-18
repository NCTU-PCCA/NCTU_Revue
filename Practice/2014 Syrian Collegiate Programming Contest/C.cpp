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
struct s
{
	int num;
	int idx;
}cont[10005];
bool cmp(s x,s y){
	return x.num>y.num;
}
int main(){
	int t;
	cin >> t;
	for(int cc=1;cc<=t;cc++){
		ll n,m,c;
		cin >> n >> m >> c;
		ll mx = 0;
		f(m){
			cont[i].idx = i;
			cont[i].num = 0;
		}
		f1(n){
			int add;
			cin >> add;
			add--;
			cont[add].num++;
		}
		sort(cont,cont+m,cmp);
		ll cur = 0;
		int mi = 1e9;
		f(m){
			mi = min(mi,cont[i].num);
			cur += (cont[i].idx+1) * (cont[i].idx+1) % c;
			mx = max(mx,cur * mi);
		}
		printf("Case %d: %lld\n",cc,mx);
	}
}
