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
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >> n;
		int cont[n+5] = {};
		string s;
		cin >> s;
		s = " "+s;
		f1(n){
			if(s[i] == '*'){
				cont[i-1] = cont[i] = cont[i+1] = 1;
			}
		}
		int cnt = 0;
		f1(n){
			if(!cont[i]){
				cont[i] = cont[i+1] = cont[i+2] = 1;
				cnt++;
			}
		}
		cout << cnt << '\n';
 
	}
}
