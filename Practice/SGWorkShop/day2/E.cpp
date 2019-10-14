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
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        LL a, b; cin >> a >> b;
        if (a == 0 && b != 0) { 
            cout << "No\n";
            continue;
        }
        if (b == 0) {
            cout << "Yes\n";
            continue;
        }
        while (b % 2 == 0) b >>= 1;
        bool legal = false;
        vector<int>v1;
        vector<int>v2;
        while(a){
            v1.pb(a%2);
            a>>=1;
        }
        while(b){
            v2.pb(b%2);
            b>>=1;
        }
        int f = 0;
        for(int i=0;i<=(int)v1.size()-(int)v2.size();i++){
            int n = 0;
            for(int j=0;j<(int)v2.size();j++){
                if(v1[i+j]!=v2[j]){
                    n=1;
                    break;
                }
            }
            if(n==0){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
