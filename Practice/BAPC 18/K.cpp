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
int mx[maxn];
int tot;
vector<int>st[maxn];
void dfs2(int now,int pre,int gp){
    if(g[now].size() == 1){
        st[gp].pb(now);
        return;
    }
    for(auto i:g[now]){
        if(i!=pre){
            dfs2(i,now,gp);
        }
    }
}
int dfs(int now,int pre){
    if(g[now].size() == 1){
        mx[now] = tot;
        return dp[now] = 1;
    }
    int cur = 0;
    int m = 0;
    for(auto i:g[now]){
        if (i != pre) {
            dfs(i,now);
            cur += dp[i];
            dp[now] += dp[i];
            m = max(m,dp[i]);
        }
    }
    m = max(m,tot-cur);
    mx[now] = m;
    return dp[now];
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
    if (n == 2) {
        cout << 1 << '\n';
        cout << "0 1\n";
        exit(0);
    }
    int rt = 0;
    f(n){
        tot += (g[i].size() == 1);
        if(g[i].size() > 1){
            rt = i;
        }
    }
    dfs(rt, -1);
    int mxx = 1e5;
    int idx = 0;
    f(n){
        if(mx[i] < mxx){
            mxx = mx[i];
            idx = i;
        }
    }
    int sz = g[idx].size();
    for(int i = 0 ; i <sz ; i++){
        dfs2(g[idx][i],idx,i);
    }
    priority_queue<pii> pq;
    for (int i = 0 ; i < sz ; i++) {
        pq.push({st[i].size(), i});
    }
    vector<pii> ans;
    while (pq.size() > 1) {
        pii a = pq.top(); pq.pop();
        pii b = pq.top(); pq.pop();
        ans.push_back({st[a.S].back(), st[b.S].back()});
        st[a.S].pop_back(); st[b.S].pop_back();
        if (st[a.S].size()) pq.push({st[a.S].size(), a.S});
        if (st[b.S].size()) pq.push({st[b.S].size(), b.S});
    }
    if (pq.size()) {
        pii last = pq.top();
        for (auto &v : st[last.S])
            ans.push_back({idx, v});
    }
    cout << ans.size() << '\n';
    for (auto &p : ans)
        cout << p.F << ' ' << p.S << '\n';
}
