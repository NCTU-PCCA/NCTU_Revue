#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
bool isDAG(vector<vector<int> > &G, vector<int> deg) {
    int n = G.size();
    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    set<int> ok;
    while (q.size()) {
        int p = q.front(); q.pop();
        ok.insert(p);
        for (auto &v : G[p]) {
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }
    return ok.size() == n;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pii> R(n);
    for (auto &p : R)
        cin >> p.F >> p.S, p.F--, p.S--;
    vector<vector<int> > G(n), revG(n);
    vector<int> inDeg(n, 0), outDeg(n, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        revG[v].push_back(u);
        inDeg[v]++;
        outDeg[u]++;
    }
    if (!isDAG(G, inDeg)) {
        cout << -1 << '\n';
        exit(0);
    }
    
    queue<int> q;
    for (int i = 0 ; i < n ; i++) {
        if (outDeg[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : revG[p]) {
            R[v].S = min(R[v].S, R[p].S - 1);
            outDeg[v]--;
            if (outDeg[v] == 0)
                q.push(v);
        }
    }

    vector<int> deg(n, 0);
    for (int i = 0 ; i < n ; i++)
        for (auto &v : G[i])
            deg[v]++;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<vector<int> > ready(n);
    for (int i = 0 ; i < n ; i++) {
        if (deg[i] == 0)
            ready[R[i].F].push_back(i);
    }
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        for (auto &v : ready[i])
            pq.push({R[v].S, v});
        if (pq.size() == 0) {
            cout << -1 << '\n';
            exit(0);
        }
        auto p = pq.top(); pq.pop();
        if (p.F < i) {
            cout << -1 << '\n';
            exit(0);
        }
        ans.push_back(p.S);
        for (auto &v : G[p.S]) {
            deg[v]--;
            if (deg[v] == 0) {
                if (R[v].F > i)
                    ready[R[v].F].push_back(v);
                else
                    pq.push({R[v].S, v});
            }
        }
    }
    for (auto &v : ans)
        cout << v + 1 << '\n';
}
