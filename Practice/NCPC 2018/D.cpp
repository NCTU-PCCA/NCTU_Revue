#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
ll cal(ll x){
    ll ret = 0;
    for(auto i:v){
        ret += x/i+1;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        v.clear();
        for(int i=0;i<n;i++){
            int add;
            cin >> add;
            v.push_back(add);
        }
        ll mi = -1;
        for(ll i = 1LL<<45;i>=0;i>>=1){
            ll now = mi + i;
            if(cal(now)<m){
                mi = now;
            }
            if(i==0)break;
        }
        m-=cal(mi);
        mi++;
        //cout<<mi<<' '<<m<<endl;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(mi%v[i]==0){
                cnt++;
                if(cnt==m){
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }

}
