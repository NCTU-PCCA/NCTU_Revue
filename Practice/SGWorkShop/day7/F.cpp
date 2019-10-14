#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
ll cont[1000005];
ll rem[1000005];
ll bwin[1000005];
ll awin[1000005];
ll pre[1000005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a,b,n;
    cin >> n >> a >> b;
    f1(n)cin >> cont[i];
    ll cur = a+b;
    f1(n){
        rem[i] = cur;
        cur -= cont[i];
    }
    f1(n){
        pre[i]=pre[i-1]+cont[i];
        if(pre[i]>a+b){
            n=i-1;
            break;
        }
    }
    ll mi = 0;
    if(cont[1]>a){
        cout<<"BOB"<<endl;
        exit(0);
    }
    for(int i=n;i>=1;i--){
        mi+=cont[i];
        awin[i]=max(mi,cont[i]);
        bwin[i]=rem[i]-awin[i]+1;
        mi = min(mi,bwin[i]);
    }
    int f = 0;
    f1(n){
       // cout<<awin[i]<<' '<<bwin[i]<<endl;
    }
    if(awin[1]<=a)f=1;
    
    if(f){
        cout<<"ALICE"<<endl;
    }
    else{
        cout<<"BOB"<<endl;
    }
}
