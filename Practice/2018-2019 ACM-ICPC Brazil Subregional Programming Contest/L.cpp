#include <bits/stdc++.h>
#define fr(i,j,k) for (int i = j ; i < k ; i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define ll long long
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
vector<int>g[maxn];
int pa[maxn][17];
int dep[maxn];
void dfs(int now, int pre) {
    for (auto &i : g[now]) {
        if (i ^ pre) {
            dep[i] = dep[now] + 1;
            pa[i][0] = now;
            dfs(i, now);
        }
    }
}
int getpa(int x,int k) {
    int cnt = 0;
    while (k) {
        if (k & 1) {
            x = pa[x][cnt];
        }
        k >>= 1;
        cnt++;
    }
    return x;
}
int lca(int x,int y) {
    if (dep[y] > dep[x]) {
        swap(x, y);
    }
    int dif = dep[x] - dep[y];
    int cnt = 0;
    while (dif) {
        if (dif & 1) {
            x = pa[x][cnt];
        }
        cnt++;
        dif >>= 1;
    }
    if (x == y) return x;
    for (int i = 16 ; i >= 0 ; i--) {
        if (pa[x][i] != pa[y][i]) {
            x = pa[x][i];
            y = pa[y][i];
        }
    }
    return pa[x][0];
}
int dis(int x,int y) {
    return dep[x] + dep[y] - 2 *dep[ lca(x, y)];
}

void solve(int a,int b,int c,int d) {
    int lca1 = lca(a, b);
    int lca2 = lca(c, d);
    if (dep[lca1] > dep[lca2]) {
        swap(lca1,lca2);
    }
    if (getpa(lca2,dep[lca2] - dep[lca1]) != lca1) {
        cout << 0 << '\n';
        return;
    }
    vector<int>v1{a,b},v2{c,d};
    int f = 0;
    int ans = 0;
    for (auto &i : v1) {
        for (auto &j : v2) {
            int l = lca(i, j);
            if (dep[l] < dep[lca2])continue;
            if (getpa(l,dep[l]-dep[lca2])!= lca2)continue;
            f = 1;
            ans += dep[l] - dep[lca2];
        }
    }
    if (f) ans++;
    cout << ans << '\n';
}
int main() {
    int n, q;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    f(n-1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    f1(16) {
        fr(j,1,n+1) {
            pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
}
