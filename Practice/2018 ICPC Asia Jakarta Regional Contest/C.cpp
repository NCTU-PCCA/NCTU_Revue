#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int b[15];
int n,m,k;
unordered_set<ll>st;
ll mul = 20190823;
ll mod = 1e9+7;
ll __hash(string s){
	ll ret = 0;
	for(auto i:s){
		ret *= mul;
		ret += i-'0';
		ret %= mod;
	}
	return ret;
}
/*
ll fpow(ll x,ll mul){
	ll ret = 1;
	ll xx = mul;
	while(x){
		if(x&1){
			ret *= xx;
			ret %= mod;
		}
		xx *= xx;
		xx %= mod;
		x >>= 1;
	}
	return ret;
}
*/
ll fpow(ll x, ll n) {
	if (n == 0) return 1;
	ll k = fpow(x, n / 2);
	if (n % 2)
		return k * k % mod * x % mod;
	else
		return k * k % mod;
}
int main(){
	cin >> n >> m >> k;
	f(m){
		cin >> b[i];
	}
	string s;
	f(n){
		s += b[rand()%m]+'0';
	}
	string ans = s;
	ll h = __hash(s);
	st.insert(h);
	f(k-1){
		h -= fpow(mul, n - 1) * (ans[i]-'0') % mod;
		while(h<0){
			h += mod;
		}
		h *= mul;
		h %= mod;
		int rnd;
		while(1){
			rnd = rand()%m;
			if(st.find((h+b[rnd])%mod)==st.end()){
				break;
			}
		}
		h += b[rnd];
		h %= mod;
		ans += b[rnd] + '0';
		st.insert(h);
	}
	cout << ans << endl;
}
