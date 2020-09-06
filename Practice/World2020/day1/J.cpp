#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 500005;
int cnt[maxn][26];
int R[maxn][26];
string s;
int n;
void pull(int x) {
    for (int i = 0 ; i < 26 ; i++) {
        cnt[x][i] = cnt[x<<1][i] + cnt[x<<1|1][i];
        R[x][i] = max(R[x<<1][i], R[x<<1|1][i]);
    }
}
void build(int x, int l ,int r) {
    if (l == r) {
        R[x][s[l]-'a'] = l;
        cnt[x][s[l]-'a'] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pull(x);
}
void modify(int x,int l, int r, int p, char c) {
    if (l == r) {
        R[x][s[l]-'a'] = 0;
        cnt[x][s[l]-'a'] = 0;
        cnt[x][c-'a'] = 1;
        R[x][c-'a'] = l;
        s[l] = c;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
        modify(x<<1,l,mid,p,c);
    }
    else {
        modify(x<<1|1,mid+1,r,p,c);
    }
    pull(x);
}
pair<int,int> query(int x, int l, int r, int ql, int qr, int tar) {
    if (ql <= l && qr >= r) {
        //cout << cnt[x][tar] <<' '<<R[x][tar] << endl;
        return {cnt[x][tar],R[x][tar]};
    }
    int mid = (l + r) >> 1;
    pair<int,int>ans;
    ans.F = ans.S = 0;
    if (ql <= mid) {
        auto node = query(x<<1,l,mid,ql,qr,tar);
        ans.F += node.F;
        ans.S = max(ans.S,node.S);
    }
    if (qr > mid) {
        auto node = query(x<<1|1,mid+1,r,ql,qr,tar);
        ans.F += node.F;
        ans.S = max(ans.S,node.S);
    }
    return ans;
    
}
void solve(int l, int r, int x) {
    int now = 0;
    int ptr = l;
    for (int i = 25 ; i >= 0 ; i--) {
        //cout << ptr <<' '<<r<<endl;
        //cout << ptr <<' '<<r<<'\n';
        //cout << 1 <<' '<<1<<' '<<n<<' '<<ptr<<' '<<r<<' '<<i<<endl;
        auto tar = query(1,1,n,ptr,r,i);
        
        //cout << tar.F <<' '<<tar.S << endl;
        if (tar.F == 0)continue;
        if (now + tar.F >= x) {
            cout << char('a'+i) << '\n';
            return;
        }
        now += tar.F;
        ptr = tar.S + 1;
        if (ptr > r) break;
    }
    cout << '-' << '\n';
}
void go() {
    cin >> s;
    n = s.size();
    s = " " + s;
    int k;
    cin >> k;
    build(1,1,n);
    f(26) {
        //cout << 1 <<' '<<1<<' '<<n<<' '<<1<<' '<<n<<' '<<i<<endl;
        //cout << query(1,1,n,1,n,i).F <<' '<< query(1,1,n,1,n,i).S<< '\n';
    }
    while(k--) {
        int op;
        cin >> op;
        if (op == 2) {
            int pos;
            char c;
            cin >> pos >> c;
            modify(1,1,n,pos,c);
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            solve(l,r,x);
            //cout << endl;
        }
    }
}
int main() {
    freopen("joining.in","r",stdin);
    freopen("joining.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
