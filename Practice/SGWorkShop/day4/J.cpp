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
const int INF = 0x3f3f3f3f;
vector<int> bfs(vector<vector<int> > &G, int s) {
    vector<int> d(G.size(), INF); d[s] = 0;
    queue<int> q; q.push(s); while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (d[v] != INF) continue;
            d[v] = d[p] + 1;
            q.push(v);
        }
    }
    return d;
}
LL solve(vector<LL> &cnt) {
    return cnt[0] + cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[3]
         + cnt[0] * (cnt[0] - 1) / 2
         + cnt[1] * (cnt[1] - 1) / 2
         + cnt[2] * (cnt[2] - 1) / 2
         + cnt[3] * (cnt[3] - 1) / 2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > G(n);
    for (int i = 0 ; i < m ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> d0 = bfs(G, 0);
    vector<int> d1 = bfs(G, 1);
    LL ans = 0;
    vector<LL> cnt(4, 0);
    for (int i = 2 ; i < n ; i++) {
        if (d0[i] == 1)
            cnt[0]++;
        else if (d0[i] == 2)
            cnt[1]++;
        else if (d0[i] == 3)
            cnt[2]++;
        else
            cnt[3]++;
    }
    ans = max(ans, solve(cnt));
    cnt.clear(); cnt.resize(4, 0);
    for (int i = 2 ; i < n ; i++) {
        if (d0[i] == 1)
            cnt[0]++;
        else if (d0[i] == 2)
            cnt[1]++;
        else if (d1[i] == 1)
            cnt[3]++;
        else
            cnt[2]++;
    }
    ans = max(ans, solve(cnt));
    cnt.clear(); cnt.resize(4, 0);
    for (int i = 2 ; i < n ; i++) {
        if (d0[i] == 1)
            cnt[0]++;
        else if (d1[i] == 2)
            cnt[2]++;
        else if (d1[i] == 1)
            cnt[3]++;
        else
            cnt[1]++;
    }
    ans = max(ans, solve(cnt));
    cnt.clear(); cnt.resize(4, 0);
    for (int i = 2 ; i < n ; i++) {
        if (d1[i] == 3)
            cnt[1]++;
        else if (d1[i] == 2)
            cnt[2]++;
        else if (d1[i] == 1)
            cnt[3]++;
        else
            cnt[0]++;
    }
    ans = max(ans, solve(cnt));
    cout << ans - m << '\n';
}
