#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;
vector<int> rk, st, pt;
vector<LL> sum, ans;
void init(int n) {
    rk.assign(MAXN, 1);
    sum.assign(MAXN, 0);
    st.assign(MAXN, -1);
    pt.assign(n, 0);
    ans.assign(n, 0);
}
void update(auto &mp, int time) {

    for (auto &p : mp)
        for (auto &v : p.S) {
            int ptv = pt[v];
            ans[v] += sum[ptv] + 1ll * (time - st[ptv] - 1) * rk[ptv];
            ptv++;
            ans[v] -= sum[ptv] + 1ll * (time - st[ptv] - 1) * rk[ptv];
        }
    for (auto &p : mp) {
        sum[p.F] += 1ll * (time - st[p.F]) * rk[p.F] + p.S.size();
        st[p.F] = time;
        for (auto &v : p.S) {
            rk[pt[v]]++;
            pt[v]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; init(n);
    for (int i = 0 ; i < m ; i++) {
        map<int, vector<int>> mp;
        int x; cin >> x; while (x--) {
            int v; cin >> v; v--;
            mp[pt[v]].push_back(v);
        }
        update(mp, i);
    }
    for (int i = 0 ; i < ans.size() ; i++)
        cout << fixed << setprecision(10) << double(ans[i] + sum[pt[i]] + 1ll * (m - 1 - st[pt[i]]) * rk[pt[i]]) / m << '\n';
}
