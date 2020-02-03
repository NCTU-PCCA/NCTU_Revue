#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
using ll = long long;
struct s{
    int x,l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
int cnt[200000];
int tot[200000];
void pushup(int x,int l,int r){
    if(cnt[x]){
        tot[x] = r - l + 1;
    }
    else{
        if(r-l){
            tot[x] = tot[x<<1] + tot[x<<1|1];
        }
        else{
            tot[x] = 0;
        }
    }
}
void update(int x,int l,int r,int ql,int qr,int del){
    if(ql <= l && qr >= r){
        cnt[x] += del;
        pushup(x,l,r);
        return;
    }
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1,l,mid,ql,qr,del);
    }
    if(qr > mid){
        update(x<<1|1,mid+1,r,ql,qr,del);
    }
    pushup(x,l,r);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int w,L,n;
    while(cin >> w >> L >> n && w){
        vector<s>v;
        int lx, ly, x, y;

        cin >> lx >> ly;
        lx += 10000,ly += 10000;
        while(--n){
            cin >> x >> y;
            x += 10000,y += 10000;
            if(y==ly){
                int r = max(x,lx)+w;
                int l = min(x,lx);
                int u = y;
                int d = y + L;
                l++;
//                cout << l <<' '<<r <<' '<<u << ' '<<d<<endl;
                v.push_back({u,l,r,1});
                v.push_back({d,l,r,-1});
            }
            else{
                int l = x;
                int r = x + w;
                int u = min(y,ly);
                int d = max(y,ly) + L;
                l++;
                v.push_back({u,l,r,1});
                v.push_back({d,l,r,-1});
//                cout << l <<' '<<r<<' '<<u<<' '<<d<<endl;
            }
            lx = x,ly = y;
        }
        sort(v.begin(),v.end(),cmp);
        memset(tot,0,sizeof(tot));
        memset(cnt,0,sizeof(cnt));
        ll ans = 0;
        ll last = 0;
        for(auto i:v){
            ans += ll(i.x-last)*tot[1];
            update(1,1,40000,i.l,i.r,i.del);
            last = i.x;
        }
        cout << ans << endl;
    }
}
