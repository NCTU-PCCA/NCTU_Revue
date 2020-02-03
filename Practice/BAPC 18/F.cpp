#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1);
#define pb push_back
using namespace std;
vector<pair<ll,ll> >v;
ll n, m;
bool check(ll x){
    ll sum = 0;
    for(auto i:v){
        sum += max(0LL,i.F * x - i.S);
        if(sum >= m){
            return 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    f(n){
        ll add1, add2;
        cin >> add1 >> add2;
        v.pb({add1,add2});
    }
    ll l = 0, r = 2e9+5;
    while(r- l > 1){
        ll m = (l+r) >> 1;
        if(check(m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r << endl; 
}
