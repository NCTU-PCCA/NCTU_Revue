#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    while(cin >> n >> m&&n){
        vector<ll>v1,v2;
        ll cont[n+5]={};
        int h = n/2;
        int h2 = n-h;
        for(int i=0;i<n;i++){
            cin >> cont[i];
        }
        for(int i=0;i<(1<<h);i++){
            ll add = 0;
            for(int j=0;j<h;j++){
                if(i&(1<<j)){
                    add += cont[j];
                }
            }
            v1.push_back(add);
        }
        
        for(int i=0;i<(1<<h2);i++){
            ll add = 0;
            for(int j=0;j<h2;j++){
                if(i&(1<<j)){
                    add += cont[h+j];
                }
            }
            v2.push_back(add);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ll ans = 0;
        for(auto i:v1){
            ll tar = m-i;
            ans += upper_bound(v2.begin(),v2.end(),tar)-v2.begin();
        }
        cout << ans << endl;
    }
}
