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
int p = 1e5+7;
struct s{
	int a,b,c;
	bool operator< (const s &rhs )const{
		if(a!=rhs.a){
			return a < rhs.a;
		}
		else if(b!=rhs.b){
			return b < rhs.b;
		}
		else{
			return c < rhs.c;
		}
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	for(int c=1;c<=t;c++){
		int n;
		cin >> n;
		vector<int>v;
		set<s>st;
		f(n){
			int add;
			cin >> add;
			v.pb(add);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int a = v[i],b = v[j],c = v[k];
					if(a+b>c){
						st.insert({a,b,c});
					}
				}
			}
		}
		cout<<"Case #"<<c<<": "<<st.size()<<endl;
	}
}
