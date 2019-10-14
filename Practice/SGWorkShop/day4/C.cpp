// NCTU_Revue
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
const int MAXN = 1000005;
int nxt[25][MAXN];
LL _data[MAXN];
unordered_map<LL, int> pos;
char readchar(){
    static const int bufsize = 1<<16;
    static char buf[bufsize], *p=buf, *e=buf;
    return (p==e &&
        (e=(p=buf)+fread(buf,1,bufsize,stdin),p==e)?0:*p++);
}
void print(LL x) {
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void read_int(int &x) {
    int f=1;x=0;char s=readchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=readchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=readchar();}
    x*=f;
}
void read(LL &x) {
    LL f=1;x=0;char s=readchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=readchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=readchar();}
    x*=f;
}
int main() {
    int n, k; LL m;
    read_int(n); read_int(k); read(m);
    pos.clear();
    f1 (n) {
        read(_data[i]);
        pos[_data[i]] = i;
    }
    int l = 1,r = k + 2;
    nxt[0][1]=k+1;
    fr (i,2,n+1) {
        LL v = _data[i];
        while(r<=n&&abs(_data[r]-v)<abs(_data[l]-v)){
            l++;
            r++;
        }
        if(abs(_data[r-1]-v)<=abs(_data[l]-v)){
            nxt[0][i]=pos[_data[l]];
        }
        else{
            nxt[0][i] = pos[_data[r - 1]];
        }
    }
    
    vector<int> d(n + 1, 0), deg(n + 1, 0);
    vector<vector<int> > G(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        G[i].push_back(nxt[0][i]);
        deg[nxt[0][i]]++;
    }
    queue<int> q;
    for (int i = 1 ; i <= n ; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        int p = q.front(); q.pop();
        d[p] = -1;
        for (auto &v : G[p]) {
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (d[i] == 0) {
            int cnt = 1, cur = nxt[0][i];
            while (cur != i) {
                cur = nxt[0][cur];
                cnt++;
            }
            cur = nxt[0][i]; d[i] = cnt;
            while (cur != i) {
                d[cur] = cnt;
                cur = nxt[0][cur];
            }
        }
    }

    f1(24){
        fr(j,1,n+1){
               nxt[i][j]=nxt[i-1][nxt[i-1][j]];
            // nxt[j][i]=nxt[nxt[j][i-1]][i-1];
        }
    }
    f1(n){
        ll left = m;
        int pp = i;
        if(left<(1<<20)){
            for(int i=24;i>=0;i--){
                if(left&(1LL<<i)){
                    pp = nxt[i][pp];
                    // pp = nxt[pp][i];
                }
            }
        }
        else{
            ll tmp = left - (1<<20);
            left = (1<<20);
            for(int i=24;i>=0;i--){
                if(left&(1LL<<i)){
                    pp = nxt[i][pp];
                    // pp = nxt[pp][i];
                }
            }
            tmp %= d[pp];
            left = tmp;
            for(int i=24;i>=0;i--){
                if(left&(1LL<<i)){
                    pp = nxt[i][pp];
                    // pp = nxt[pp][i];
                }
            }
        }
        print(pp); printf(" ");
    }
    printf("\n");
}
