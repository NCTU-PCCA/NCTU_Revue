// NCTU_Revue
#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
vector<int>v[1000005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >>n;
    f1(n){
        int add;
        cin >> add;
        v[add].pb(i);
    }
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int>vv;
        f(k){
            int add;
            cin >> add;
            vv.pb(add);
        }
        int pos = 0;
        int f = 0;
        for(auto i:vv){
            if(upper_bound(v[i].begin(),v[i].end(),pos)==v[i].end()){
                f=1;
                break;
            }
            else{
                pos = *upper_bound(v[i].begin(),v[i].end(),pos);
            }
        }
        if(f){
            cout<<"NIE"<<'\n';
        }
        else{
            cout<<"TAK"<<'\n';
        }
    }
}
