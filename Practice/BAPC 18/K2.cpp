#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define pb push_back
const int maxn = 1e5+5;
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
vector<int>g[maxn];
int dp[maxn];
vector<int>v;
void dfs(int now,int pre){
    if(g[now].size() == 1){
        v.pb(now);
        if(now!=pre){
            return;
        }
    }
    for(auto i:g[now]){
        if(i!=pre){
            dfs(i,now);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    f(n-1){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    if(n==2){
        cout << 1 << endl;
        cout << 0 <<' '<<1<<endl;
        exit(0);
    }
    int rt = 0;
    f(n){
        if(g[i].size() >1){
            rt = i;
            break;
        }
    }
    dfs(rt,rt);
    vector<pair<int,int> >ans;
    int pl = (v.size()+1)/2;
    for(int i = 0 ; i < v.size()/2 ; i++){
        ans.pb({v[i],v[i+pl]});
    }
    if(v.size()&1){
        ans.pb({v[v.size()/2],k});
    }
    cout << ans.size() << endl;
    for(auto i:ans){
        cout << i.F << ' ' << i.S << '\n';
    }
}
