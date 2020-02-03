#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod;
ll pm(ll x,ll p){
    ll ret = 1;
    ll now = x;
    while(p){
        if(p&1){
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        p >>= 1;
    }
    return ret;
}
ll cnt[18000000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll n ,m ,d;
    cin >> n >> m >> d;
    mod = d;
    //while(t--){
        
        ll num1 = n;
        ll num2 = m;
        ll num3 = n - m;
        for(int  i = 1 ; i <= d ; i++){
            cnt[i] += num1 / d;
            cnt[i] += (num1 % d >= i);
        }
        for(int  i = 1 ; i <= d ; i++){
            cnt[i] -= num2 / d;
            cnt[i] -= (num2 % d >= i);
        }
        for(int  i = 1 ; i <= d ; i++){
            cnt[i] -= num3 / d;
            cnt[i] -= (num3 % d >= i);
        }
        cout << "here"<<endl;
        for(int i = 1 ; i < d ; i++){
            cout << cnt[i] <<' '<<endl;
        }
        for(int  i = d-1 ; i > 1 ; i--){
            if(cnt[i]<0){
                ll left = -cnt[i];
                ll upp = d/i*i;
                cnt[i] = 0;
                while(left){
                    ll u = min(left,cnt[upp]);
                    cnt[upp] -= u;
                    cnt[upp/i] += u;
                    left -= u;
                    upp -= i;
                   // cout << upp <<' '<<left << endl;
                }
                
            }
        }
        ll ans = 1;
        for(int i = 2 ; i < d ; i++){
            cout << cnt[i] << '\n';
            ans *= pm(i,cnt[i]);
            ans %= mod;
        }
        cout << ans << endl;
   // }
}
