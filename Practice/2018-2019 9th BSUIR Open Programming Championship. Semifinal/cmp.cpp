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
