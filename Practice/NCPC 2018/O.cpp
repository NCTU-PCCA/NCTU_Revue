#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while (t--) {
    ll n,p,q,i,j;
    cin >> n >> p >> q >> i >> j;
    ll ans = 0;
    for(int i=0;i<p;i++){
        if(i==0){
            ans += (n-(q+1)*(p-1))*(n+1-(n-(q+1)*(p-1)))*j;
        }
        else{
            ans += (q+1)*(n+1-q-1)*j;
        }
    }
    ans += i * n * (n-p);
    
    cout << ans*2 << endl;
    }
}
