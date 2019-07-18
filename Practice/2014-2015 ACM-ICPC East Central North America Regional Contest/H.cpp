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
	for(int c = 1 ; c <= t ; c++){
		int a,b;
		cin >> a;
		string op;
		cin >> op;
		cin >> b;
		if(op=="after"){
			int now = 360 - b * 30;
			int goal = a - now;
 
			if(goal <= 0)goal += 360;
			//cout<<now<<' '<<goal<<endl;
			int sec = goal * 120;
			if(sec % 11 >= 6){
				sec = sec/11 +1;	
			}
			else{
				sec = sec/11;
			}
			int h = b + sec/3600;
			sec %= 3600;
			int m = sec/60;
			sec %= 60;
			if(h>12){
				h-=12;
			}
			printf("Case %d: %d:%02d:%02d\n",c,h,m,sec);
		}
		else{
			int now = 360 - b * 30;
			int goal = now - a;
			if(goal <= 0)goal += 360;
			int sec = goal * 120;
			if(sec % 11 >= 6){
				sec = sec/11 +1;	
			}
			else{
				sec = sec/11;
			}
			int h = b - 2;
			sec = 7200 - sec;
			h += sec/3600;
			sec %= 3600;
			int m = sec/60;
			sec %= 60;
			if(h<=0){
				h+=12;
			}
			printf("Case %d: %d:%02d:%02d\n",c,h,m,sec);
		}
	}
}
