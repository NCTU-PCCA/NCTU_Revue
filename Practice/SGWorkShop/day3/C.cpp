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
int cnt[200005];
vector<pair<int,int> >g[200005];
vector<int>st[200005];
struct s{
    int cur;
    int pre;
    int dis;
    int from;
    bool operator > (const s &rhs) const {
        return dis == rhs.dis ? from > rhs.from : dis > rhs.dis; 
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    f(m){
        int add1,add2,add3;
        cin >> add1 >> add2 >> add3;
        g[add1].pb({add2,add3});
        g[add2].pb({add1,add3});
    }
    priority_queue<s, vector<s>, greater<s> > pq;
    int ok[n+5] ={};
    vector<int>v;
    f(k){
        int add;
        cin >> add;
        v.pb(add);
        ok[add]=-1;
        pq.push({add,0,0,add});
    }
    while(!pq.empty()){
        s now = pq.top();
        pq.pop();
        if(st[now.cur].size()==2)continue;
        if(st[now.cur].size()==1&&st[now.cur][0]==now.from)continue;
        st[now.cur].pb(now.from);
        if(ok[now.cur]&&now.cur!=now.from){
            //cout<<now.cur<<' '<<now.from<<' '<<now.dis<<' '<<' '<<ok[now.cur]<<endl;
            if(ok[now.cur]==-1){
                 //cout<<now.from<<endl;
                 ok[now.cur]=now.from;
                 //cout<<now.cur<<' '<<ok[now.cur]<<' '<<now.from<<endl;
            }
            continue;
        }
        cnt[now.cur]++;
        for(auto i:g[now.cur]){
            if(i.F==now.pre)continue;
            pq.push({i.F,now.cur,now.dis+i.S,now.from});
        }
    }
    for(auto i:v){
        cout<<ok[i]<<'\n';
    }
}
