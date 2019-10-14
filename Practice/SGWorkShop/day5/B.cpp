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
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct E { int u, v; LL w; };
void solve(int L, int R, vector<int> &data, vector<E> &edges) {
    if (R - L == 1) return ;
    int M = (R + L) >> 1;
    LL maxV = -INF, minV = INF;
    int maxIdx = -1, minIdx = -1;
    for (int i = L ; i < M ; i++)
        if (data[i] > maxV)
            maxV = data[i], maxIdx = i;
    for (int i = M ; i < R ; i++)
        if (data[i] < minV)
            minV = data[i], minIdx = i;
    for (int i = L ; i < M ; i++)
        edges.push_back({i, minIdx, minV - data[i]});
    for (int i = M ; i < R ; i++)
        edges.push_back({i, maxIdx, data[i] - maxV});
    solve(L, M, data, edges);
    solve(M, R, data, edges);
}
int find(int x, vector<int> &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        vector<E> edges;
        solve(0, n, data, edges);
        sort(edges.begin(), edges.end(), [](E a, E b) {
            return a.w < b.w;
        });
        LL ans = 0;
        vector<int> pa(n, -1);
        for (auto &e : edges) {
            int x = find(e.u, pa);
            int y = find(e.v, pa);
            if (x == y) continue;
            ans += e.w;
            pa[x] += pa[y];
            pa[y] = x;
        }
        cout << ans << '\n';
    }
}
