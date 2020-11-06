#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
struct SCC {
    int stamp, scc_num;
    struct Node : vector<int> {
        int dfn, low, scc; bool inS;
        Node() { dfn = low = scc = -1; inS = false; }
    };
    vector<Node> N; vector<int> stk;
    void init(int n) {
        N.clear(); N.resize(n); stk.clear();
    }
    void addEdge(int u, int v) { N[u].push_back(v); }
    void Tarjan(int u) { N[u].low = N[u].dfn = stamp++;
        stk.push_back(u); N[u].inS = true;
        for (auto &v : N[u]) if (!~N[v].dfn) Tarjan(v),
            N[u].low = min(N[u].low, N[v].low);
        else if (N[v].inS)
            N[u].low = min(N[u].low, N[v].dfn);
        if (N[u].dfn == N[u].low) {
            int v; do { v = stk.back(); stk.pop_back();
                N[v].scc = scc_num; N[v].inS = false;
            } while (v != u); scc_num++;
        }
    }
    void run() {
        stamp = scc_num = 0;
        for (int i = 0 ; i < N.size() ; i++)
            if (!~N[i].dfn) Tarjan(i);
    }
} solver, checker;
int dfs(int u, auto &G, auto &vis) {
    if (G[u].size() == 0) return u;
    for (auto &v : G[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        int x = dfs(v, G, vis);
        if (x != -1)
            return x;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        solver.init(n);
        checker.init(n);
        vector<pii> edges;
        while (m--) {
            int u, v; cin >> u >> v; u--, v--;
            solver.addEdge(u, v);
            edges.push_back({u, v});
            checker.addEdge(u, v);
        }
        solver.run();
        if (solver.scc_num == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> ind(solver.scc_num, 0), oud(solver.scc_num, 0);
        vector<int> lbl(solver.scc_num, -1);
        vector<vector<int>> G(solver.scc_num);
        for (int i = 0 ; i < n ; i++)
            lbl[solver.N[i].scc] = i;
        for (auto &e : edges) {
            int u = solver.N[e.F].scc;
            int v = solver.N[e.S].scc;
            if (u == v) continue;
            ind[v]++; oud[u]++;
            G[u].push_back(v);
        }
        vector<int> vis(solver.scc_num, 0);
        vector<pii> ms;
        vector<int> match(solver.scc_num, -1);
        for (int i = 0 ; i < solver.scc_num ; i++) {
            if (ind[i]) continue;
            vis[i] = 1;
            int v = dfs(i, G, vis);
            if (v != -1) {
                ms.push_back({i, v});
                match[i] = v;
                match[v] = i;
            }
        }
        vector<pii> ans;
        for (int i = 0 ; i < ms.size() ; i++) {
            ans.push_back({ms[i].S, ms[(i + 1) % ms.size()].F});
        }
        vector<int> I, O;
        int leaderI = -1, leaderO = -1;
        for (int i = 0 ; i < solver.scc_num ; i++) {
            if (ind[i] == 0) {
                if (match[i] == -1)
                    I.push_back(i);
                leaderI = i;
            }
            if (oud[i] == 0) {
                leaderO = i;
                if (match[i] == -1) {
                    O.push_back(i);
                }
            }
        }
        for (int i = 0 ; i < min(I.size(), O.size()) ; i++) {
            ans.push_back({O[i], I[i]});
        }
        for (int i = min(I.size(), O.size()) ; i < I.size() ; i++) {
            ans.push_back({leaderO, I[i]});
        }
        for (int i = min(I.size(), O.size()) ; i < O.size() ; i++) {
            ans.push_back({O[i], leaderI});
        }
        cout << ans.size() << '\n';
        for (int i = 0 ; i < ans.size() ; i++) {
            cout << lbl[ans[i].F] + 1 << ' ' << lbl[ans[i].S] + 1 << '\n';
            checker.addEdge(lbl[ans[i].F], lbl[ans[i].S]);
        }
        checker.run();
        assert(checker.scc_num == 1);
    }
}
