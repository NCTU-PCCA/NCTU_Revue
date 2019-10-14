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
vector<int>g[100005];
ll sz[100005];
int dep[100005];
ll n;
ll ans;
void dfs(int now,int pre){
    dep[now]=dep[pre]+1;
    ll mi = 0;
    ll sum = 0;
    ll mi3 = 0;
    sz[now]=1;
    for(auto i:g[now]){
        if(i!=pre){
            dfs(i,now);
            sz[now]+=sz[i];
            mi+=sz[i]*(sz[i]-1)/2;
            sum += sz[i];
        }
    }
    ll rem = n-sz[now];
    sum +=rem;
    mi += rem*(rem-1)/2;
    /*
    cout<<"now"<<now<<endl;
    cout<<"dep"<<dep[now]<<endl;
    cout<<"sum"<<sum<<endl;
    cout<<"mi"<<mi<<endl;
    */
    // ans -= dep[now]*(dep[now]-1)/2;
    // cout<<dep[now]*(dep[now]-1)/2<<endl;
    ans -= (sum * (sum-1) / 2 - mi);
    // cout<<sum*(sum-1)/2 - mi<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ans = n*(n-1)*(n-2)/6;
    f(n-1){
        int add1,add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    dep[0]=-1;
    dfs(1,0);
    cout << ans << endl;
}
