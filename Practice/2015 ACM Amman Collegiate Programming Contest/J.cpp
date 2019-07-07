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
		map<int,int>mp1,mp2;
		cin >> n >> m;
		f(n){
			int add;
			cin >> add;
			mp1[add]++;
		}
		f(m){
			int add;
			cin >> add;
			mp2[add]++;
		}
		vector<int>v1,v2;
		for(auto i:mp1){
			v1.pb(i.second);
		}
		for(auto i:mp2){
			v2.pb(i.second);
		}
		int p1 = 0 ,p2 = 0;
		while(p1<v1.size()&&p2<v2.size()){
			if(v1[p1] <= v2[p2]){
				p1++,p2++;
			}
			else{
				p2++;
			}
		}
		if(p1==v1.size()){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
