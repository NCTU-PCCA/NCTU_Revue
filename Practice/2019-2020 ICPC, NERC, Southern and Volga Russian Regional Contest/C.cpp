#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
const int maxn = 3e5+5;
using namespace std;
ll k;
struct s{
    int l,r;
    ll p; int idx;
};
bool cmp(s x,s y){
    return x.r < y.r;
}
ll mi[maxn<<2];
ll miid[maxn<<2];
ll lz[maxn<<2];
void pushup(int x){
    if (mi[x<<1] > mi[x<<1|1])
        miid[x] = miid[x<<1];
    else
        miid[x] = miid[x<<1|1];
    mi[x] = max(mi[x<<1],mi[x<<1|1]);
}
void pushdown(int x){
    if(!lz[x])return ;
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    mi[x<<1] += lz[x];
    mi[x<<1|1] += lz[x];
    lz[x] = 0;
}
void build(int x,int l,int r){
    if(l==r){
        mi[x] = (l) * k;
        miid[x] = l;
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr,ll val){
    if(ql <= l&& qr >= r){
        mi[x] += val;
        lz[x] += val;
        return;
    }
    int mid = (l+r) >> 1;
    pushdown(x);
    if(ql <= mid)
    update(x<<1,l,mid,ql,qr,val);
    if(qr > mid)
    update(x<<1|1,mid+1,r,ql,qr,val);
    pushup(x);
}
pair<ll,ll> query(int x,int l,int r,int ql,int qr){
    if(ql <= l && qr >= r){
        return {mi[x], miid[x]};
    }
    ll ret = -8e18;
    int mid = (l+r) >> 1;
    ll idx;
    pushdown(x);
    if(ql <= mid){
        pair<ll, ll> res = query(x<<1, l, mid, ql, qr);
        if (res.F > ret)
            ret = res.F, idx = res.S;
    }
    if(qr > mid){
        pair<ll, ll> res = query(x<<1|1, mid+1, r, ql, qr);
        if (res.F > ret)
            ret = res.F, idx = res.S;
    }
    pushup(x);
    return {ret, idx};
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> k;
    vector<s>v;
    f(n){
        int add1,add2;
        ll p;
        cin >> add1 >> add2 >> p;
        v.pb({add1,add2+1,p,i+1});
    }
    sort(v.begin(),v.end(),cmp);
    build(1,1,200005);
    ll mx = 0, L=1, R=1;
    for(auto i:v){
        update(1,1,200005,1,i.l,i.p);
        pair<ll,ll> now = query(1,1,200005,i.r,i.r);
        pair<ll,ll> mi = query(1,1,200005,1,i.r-1);
        if (mi.F - now.F > mx) {
            R = i.r;
            L = mi.S;
            mx = mi.F - now.F;
        }
    }
    vector<int> data;
    for (int i = 0 ; i < n ; i++) {
        if (L <= v[i].l && v[i].r <= R)
            data.pb(v[i].idx);
    }
    if (mx == 0) {
        cout << 0 << '\n';
        exit(0);
    }
    cout << mx << ' ' << L << ' ' << R - 1 << ' ' << data.size() << '\n';
    for (int i = 0 ; i < data.size() ; i++)
        cout << data[i] << " \n"[i + 1 == data.size()];
}
