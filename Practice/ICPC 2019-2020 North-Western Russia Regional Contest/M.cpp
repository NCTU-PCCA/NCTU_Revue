#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int val[n+5] = {};
        f1(n){
            cin >> val[i];
        }
        map<int,int>mp;
        ll ans = 0;
        mp[val[1]]++;
        for(int i=2;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int tar = val[i] * 2 - val[j];
                if(mp.count(tar))
                    ans += mp[tar];
            }
            mp[val[i]]++;
        }
        cout << ans << endl;
    }

}
