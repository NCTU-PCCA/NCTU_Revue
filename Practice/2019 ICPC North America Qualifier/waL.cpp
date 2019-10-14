#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
int mx[100005]={};
int mi[100005]={};
int v[100005]={};
int a[100005]={};
int del[7]={0,1,2,3,2,1,0};
const int maxn = 1e5 + 5;
struct seg{
    int v[7];
    int lsum[7];
    int rsum[7];
    int msum[7];
}tree[maxn<<2];
int getv(int x,int tp){
    return v[x]+del[(x-tp+7)%7]*a[x];
}
void pushup(int x){
    f(7){
        tree[x].v[i]=max(tree[x<<1].v[i],tree[x<<1|1].v[i]);
    }
}
void update(int x,int l,int r,int tar,int k,int v){
    if(l==r){
        tree[x].v[k]=v;
        return ;
    }
    int mid = (l+r)>>1;
    if(tar<=mid){
        update(x<<1,l,mid,tar,k,v);
    }
    else{
        update(x<<1|1,mid+1,r,tar,k,v);
    }
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr,int k){
    if(ql<=l&&qr>=r){
        return tree[x].v[k];
    }
    int mid = (l+r)>>1;
    int mx = 0;
    if(ql<=mid){
        mx = max(mx,query(x<<1,l,mid,ql,qr,k));
    }
    if(qr>mid){
        mx = max(mx,query(x<<1|1,mid+1,r,ql,qr,k));  
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    f(n){
        int add1,add2;
        cin >> add1 >> add2;
        v[i]=add1;
        a[i]=add2;
        if(add2>0){
            mx[i]=add1+3*add2;
            mi[i]=add1;
        }
        else{
            mx[i]=add1;
            mi[i]=add1+3*add2;
        }
    }
    f(n){
        fr(j,0,7){
            update(1,0,n-1,i,j,mx[i]-getv(i,j));
            // cout << mx[i] << "-" << getv(i, j) << "=" << mx[i] - getv(i, j) << ' ';
        }
        cout << '\n';
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int tp = l%7;
        int mx = 0;
        if(r>=l+7){
            mx = query(1,0,n-1,l,r-7,tp);
        }
        for(int i = max(l,r-6);i<=r;i++){
            int v = getv(i,tp);
//            cout << i << ": " << v << '\n';
            int t = r-i;
            int ntp = tp;
            while(t--){
                ntp--;
                ntp += 7;
                ntp %= 7;
                int vv = getv(i,ntp);
                mx = max(mx,vv-v);
                cout<<v<<' '<<vv<<endl;
            }
        }
        cout << mx << '\n';
    }
}
