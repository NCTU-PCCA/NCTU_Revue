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
    int n;
    cin >> n;
    int u[n+5]={};
    int mod = n;
    int left = n;
    set<int>st;
    int cur = 0;
    f(mod){
        st.insert((ll)i*i%mod);
    }
    while(left){
        int x = cur*cur % mod;
       // if(!st.count(x)){
         //   st.insert(x);
            for(auto i:st){
                int nxt = (i+x)%mod;
                if(!u[nxt]){
                    left--;
                    if(!left){
                        cout<<cur<<endl;
                        exit(0);
                    }
                    u[nxt]=1;
                }
            }
       // }
        cur++;
    }
}
