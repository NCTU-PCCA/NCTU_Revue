#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll extgcd(ll a,ll b,ll &x, ll &y){
    if(!b){
        return x = 1, y = 0, a;
    }
    ll res = extgcd(b,a%b,y,x);
    return y -= a/b*x,res;
}
ll modinv(ll a,ll m){
    ll x,y,d = extgcd(a,m,x,y);
    return d == 1 ? (x + m) % m : -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll K, L;
        cin >> K >> L;
        vector<ll>v;
        if(L >= 2000){
            cout << -1 << '\n';
            continue;
        }
        for(ll a = 2 ; a < 2000 ; a++ ){
            for(ll b = a - 1 ; b >= 1 ; b--){
                ll k = K % a;
                ll tar = (a - k + a)%a;
                ll g = __gcd(a,b);
                if(tar % g)continue;
                tar /= g;
                ll ta = a / g;
                ll tb = b / g;
                ll inv = modinv(tb, ta);
                //cout << a <<' ' <<b<<' '<<ta<<' '<<tb<<endl;
                inv *= tar * g;
                inv %= a;
                ll lb = -1, rb = (1000000 * b -inv)/a;
                while(rb - lb > 1){
                    ll m = (rb+lb)/2;
                    ll bs = m * a + inv;
                    ll as = (bs * b + K )/ a;
                    if(as < bs){
                        rb = m;
                    }
                    else{
                        lb = m;
                    }
                }
                ll bs = rb * a + inv;
                ll as = (bs * b + K) / a;
                //cout << inv <<' '<<bs<<' '<<as<<' '<<a<<' '<<b<<endl;
                if(as < bs){
                    ll dif = bs - as;
                    if(dif > (a-b)*1000000)continue;
                    for(int z = 0 ; z < a - b ;z++){
                        v.push_back(-min(dif,(ll)1000000));
                        dif -= min(dif,(ll)1000000);
                    }
                    reverse(v.begin(),v.end());
                    for(int z = 0 ; z < b ; z++){
                        v.push_back(min(bs,(long long)1000000));
                        bs -= v.back();
                    }
                    goto gg;
                }

            }
        }
gg:;
        if(v.size()){
            cout << max((ll)v.size(),L) << '\n';
            for(int  i=v.size() ; i<L ; i++){
                cout << -1000000 <<' ';
            }
            for(auto i:v){
                cout << i <<' ';
            }
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}
