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
const int maxn = 100005;
int pa[100005][18];
vector<int>g[100005];
int dep[100005];
int n;
void dfs(int now, int pre){
    pa[now][0] = pre;
    for(auto i:g[now]){
        if (i == pre) {
            continue;
        }
        dep[i] = dep[now] + 1;
        dfs(i, now);
    }
}
int lca(int x,int y){
    if(dep[x] < dep[y]){
        swap(x,y);
    }
    int left = dep[x] - dep[y];
    for(int i=17;i>=0;i--){
        if(left >= (1<<i)){
            x = pa[x][i];
            left -= (1<<i);
        }
    }
    if(x==y)return x;
    for(int i=17;i>=0;i--){
        if(pa[x][i]!=pa[y][i]){
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}
int dis(int x,int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int getpa(int x, int k) {
    int cur = x;
    int i = 0;
    while (k) {
        if (k & 1) {
            cur = pa[cur][i];
        }
        k >>= 1;
        i++;
    }
    return cur;
}
vector<int>bfs(int st) {
    vector<int>dis(n+5, -1);
    dis[st] = 0;
    queue<int>q;
    q.push(st);
    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (auto &i : g[now]) {
            if (~dis[i])continue;
            dis[i] = dis[now] + 1;
            q.push(i);
        }
    }
    return dis;
}
void go() {
    cin >> n;
    f(n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    f1(17) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    auto dis1 = bfs(1);
    int mx = 1;
    for(int i = 1 ; i <= n ; i++) {
        //cout << dis1[i] <<' ';
        if (dis1[i] > dis1[mx]) {
            mx = i;
        }
    }
    auto dis2 = bfs(mx);
    int mx2 = 1;
    f1(n) {
        if (dis2[i] > dis2[mx2]) {
            mx2 = i;
        }
    }
    f1(n) {
        cout << max(dis(i,mx),dis(i,mx2)) <<' ';
    }
    cout << '\n';
}
int main() {
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
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
