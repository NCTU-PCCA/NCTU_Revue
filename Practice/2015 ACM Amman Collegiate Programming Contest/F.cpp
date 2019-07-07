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
		int n,m;
		cin >> n >> m;
		int left = n-1;
		vector<e>v;
		f(m){
			int add1,add2,w;
			cin >> add1 >> add2 >> w;
			v.pb({add1,add2,w});
		}
		sort(v.begin(),v.end(),cmp);
		f1(n){
			d[i] = i;
		}
		for(auto i:v){
			int x = fi(i.x);
			int y = fi(i.y);
			if(x!=y){
				d[x] = y;
				left--;
				if(!left){
					cout<<i.w<<'\n';
					break;
				}
			}
		}
	}
}
