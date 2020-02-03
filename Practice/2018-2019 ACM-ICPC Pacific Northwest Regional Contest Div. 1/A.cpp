#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
    string a, b; cin >> a >> b;
    int cnt=0,cnt2=0;
    int n = a.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i]==b[i]){
            if(k){
                ans++;
                k--;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i]!=b[i]){
            if(k){
                k--;
            }
            else{
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}
