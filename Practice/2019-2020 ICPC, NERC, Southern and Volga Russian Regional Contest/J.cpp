#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
vector<ll>v;
ll k;
bool check(ll x){
    vector<ll>t = v;
    ll ans = 0;
    for(int i=1;i<v.size();i++){
        ll cur = (t[i] + t[i-1]) / x;
        ll rem = (t[i]+t[i-1]) % x;
        ans += cur;
        t[i] = min(t[i],rem);
        t[i - 1] = rem - t[i];
    }
    ans += t[0] / x;
    return ans >= k;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> k;
        v.clear();
        f(n){
            ll add;
            cin >> add;
            v.pb(add);
        }
        ll l = 0,r = 2e12+5;
        while(l+1<r){
            ll m = (l+r) >> 1;
            if(check(m)){
                l = m;
            }
            else{
                r = m;
            }
        }
        cout << l * k<< endl;
    }

}
