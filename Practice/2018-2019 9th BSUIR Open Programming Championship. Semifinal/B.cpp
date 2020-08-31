#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct SCC { int stamp, scc_num;
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
    void run() { stamp = scc_num = 0;
        for (int i = 0 ; i < N.size() ; i++)
            if (!~N[i].dfn) Tarjan(i);
    }
};
struct _2Sat : SCC {
    void init(int n) { SCC::init(2 * n); }
    bool check() {
        for (int i = 0 ; i < N.size() ; i += 2)
            if (N[i].scc == N[i ^ 1].scc) return false;
        return true;
    }
    vector<int> construct() { vector<int> ret;
        for (int i = 0 ; i < N.size() ; i += 2)
            ret.push_back(N[i].scc < N[i ^ 1].scc);
        return assert(check()), ret;
    }
} solver;
typedef pair<int, int> pii;
#define F first
#define S second
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<bitset<1000>> A, B;
    int n, m; cin >> n >> m;
    int k; cin >> k;
    int a, b; cin >> a >> b;
    vector<vector<int>> G(n, vector<int>(m));
    vector<pii> tar;
    for (int i = 0 ; i < n ; i++) {
        string sA = "", sB = "";
        for (int j = 0 ; j < m ; j++) {
            cin >> G[i][j];
            if (G[i][j] == 0)
                tar.push_back({i, j});
            if (G[i][j] == a) {
                sA += '1';
                sB += '0';
            } else if (G[i][j] == b) {
                sA += '0';
                sB += '1';
            } else
                sA += '0', sB += '0';
        }
        while (sA.size() != 1000)
            sA += '0', sB += '0';
        A.push_back(bitset<1000>(sA));
        B.push_back(bitset<1000>(sB));
    }
    solver.init(tar.size());
    for (int i = 0 ; i < tar.size() ; i++) {
        for (int j = i + 1 ; j < tar.size() ; j++) {
            int x = G[tar[i].F][tar[j].S];
            int y = G[tar[j].F][tar[i].S];
            if (x != y)
                continue;
            if (x == a) {
                solver.addEdge(i * 2 + 1, j * 2 + 0);
                solver.addEdge(j * 2 + 1, i * 2 + 0);
            } else if (x == b) {
                solver.addEdge(i * 2 + 0, j * 2 + 1);
                solver.addEdge(j * 2 + 0, i * 2 + 1);
            }
        }
        bitset<1000> sumA, sumB;
        for (int j = 0 ; j < n ; j++) {
            if (j == tar[i].F)
                continue;
            if (G[j][tar[i].S] == a)
                sumA |= A[j];
            if (G[j][tar[i].S] == b)
                sumB |= B[j];
        }
        sumA &= A[tar[i].F];
        sumB &= B[tar[i].F];
        if (sumA.count()) {
            solver.addEdge(2 * i + 1, 2 * i + 0);
        }
        if (sumB.count()) {
            solver.addEdge(2 * i + 0, 2 * i + 1);
        }
    }
    solver.run();
    if (solver.check()) {
        cout << "Yes\n";
        auto ans = solver.construct();
        reverse(ans.begin(), ans.end());
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (G[i][j])
                    continue;
                if (ans.back() == 0)
                    G[i][j] = a;
                else
                    G[i][j] = b;
                ans.pop_back();
            }
        }
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++)
                cout << G[i][j] << " \n"[j + 1 == m];
    } else {
        cout << "No\n";
    }
}
