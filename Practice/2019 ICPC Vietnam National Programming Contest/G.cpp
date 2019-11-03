#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
#define ll long long
ll solve(vector<ll>v){
    map<ll,ll>mp;
    ll last = 0;
    for(auto i:v){
        mp[-i] -= 2;
        mp[-i*2]++;
        last = max(last,i*2);
    }
    ll mx = 0;
    ll cur = 0;
    ll del = 0;
    for(auto i:mp){
        ll now = -i.first;
        cur += (last-now)*del;
        mx = max(mx,cur);
        del += i.second;
        last = now;
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<ll>v1,v2;
    ll ans = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll add;
        cin >> add;
        if(add>0){
            v1.push_back(add);
        }
        else if(add<0){
            v2.push_back(-add);
        }
        ans += abs(add);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ans -= max(solve(v1),solve(v2));
    cout << ans << endl;
}
