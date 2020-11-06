#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
const LL INF = 0x3f3f3f3f3f3f3f3f;
typedef struct Edge { int v; LL w;
    bool operator > (const Edge &b) const {
        return w > b.w;
    }
} S;
void dij(vector<vector<Edge>> &G, vector<LL> &d) {
    priority_queue<S, vector<S>, greater<S>> pq;
    int n = G.size();
    for (int i = 0 ; i < n ; i++)
        pq.push({i, d[i]});
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (d[p.v] < p.w) continue;
        for (auto &e : G[p.v]) {
            if (d[e.v] > d[p.v] + e.w) {
                d[e.v] = d[p.v] + e.w;
                pq.push({e.v, d[e.v]});
            }
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<pii> arr(m);
    for (auto &p : arr)
        cin >> p.F >> p.S;
    vector<vector<Edge>> G(m);
    for (int i = 0 ; i < m ; i++) {
        for (int j = i + 1 ; j < m ; j++) {
            LL I = arr[i].F, J = arr[j].F;
            LL minV = INF;
            while (1) {
                minV = min(minV, abs(J - I));
                if (I < J)
                    I += arr[i].S;
                else
                    J += arr[j].S;
                if (max(I, J) >= n)
                    break;
            }
            G[i].push_back({j, minV});
            G[j].push_back({i, minV});
        }
    }
    vector<LL> d(m, INF);
    for (int i = 0 ; i < m ; i++)
        d[i] = arr[i].F;
    if (m != 0) dij(G, d);
    map<int, LL> res; res[0] = 0;
    for (int i = 0 ; i < m ; i++) {
        int p = arr[i].F;
        while (1) {
            if (!res.count(p)) {
                res[p] = d[i];
            } else {
                res[p] = min(res[p], d[i]);
            }
            p += arr[i].S;
            if (p >= n)
                break;
        }
    }
    vector<pii> pool;
    for (auto &p : res)
        pool.push_back(p);
    if (pool.back().F != n - 1)
        pool.push_back({n - 1, pool.back().S + n - 1 - pool.back().F});
    int maxV = 0, idx = 0;
    for (int i = 1 ; i < pool.size() ; i++) {
        int L = pool[i - 1].F, R = pool[i].F;
        while (R - L > 2) {
            int M  = (L + R) >> 1;
            int MM = (M + R) >> 1;
            int M_d  = min(pool[i - 1].S +  M - pool[i - 1].F, pool[i].S + pool[i].F -  M);
            int MM_d = min(pool[i - 1].S + MM - pool[i - 1].F, pool[i].S + pool[i].F - MM);
            if (M_d < MM_d)
                L = M;
            else
                R = MM;
        }
        int M = (L + R) >> 1;
        int L_d = min(pool[i - 1].S + L - pool[i - 1].F, pool[i].S + pool[i].F - L);
        int M_d = min(pool[i - 1].S + M - pool[i - 1].F, pool[i].S + pool[i].F - M);
        int R_d = min(pool[i - 1].S + R - pool[i - 1].F, pool[i].S + pool[i].F - R);
        if (maxV < L_d)
            maxV = L_d, idx = L;
        if (maxV < M_d)
            maxV = M_d, idx = M;
        if (maxV < R_d)
            maxV = R_d, idx = R;
    }
    cout << maxV << ' ' << idx << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        solve();
    }
}
