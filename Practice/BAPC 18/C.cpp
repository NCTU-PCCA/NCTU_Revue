#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<ll>fac;
    for(int i = 1 ; i <= n ; i++){
        if(n%i==0){
            fac.push_back(i);
        }
    }
    ll mi = 1e18;
    for(auto i:fac){
        for(auto j:fac){
            if(n % (i * j) == 0){
                ll k = n / i / j;
                mi = min(mi,i*j*2+j*k*2+i*k*2);
            }
        }
    }
    cout << mi << endl;
}
