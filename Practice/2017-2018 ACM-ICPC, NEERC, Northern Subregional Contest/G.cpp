#include <bits/stdc++.h>
using namespace std;
ifstream in("grand.in");
ofstream out("grand.out");
struct Graph {
    struct Node : vector<int> {
        int dfn, pa;
        int low1, low2;
        int s1, s2;
        Node() {
            dfn = low1 = low2 = pa = -1;
            s1 = s2 = -1;
        }
    };
    bool find;
    vector<Node> N; int stamp;
    vector<int> toNode;
    void init(int n) {
        N.clear(); N.resize(n); find = false;
        toNode.clear();
    }
    void addEdge(int u, int v) {
        N[u].push_back(v);
        N[v].push_back(u);
    }
    void Tarjan(int u, int pa) {
        N[u].low1 = N[u].low2 = N[u].dfn = stamp++;
        toNode.push_back(u);
        N[u].s1 = N[u].s2 = u;
        N[u].pa = pa;
        for (auto &v : N[u]) {
            if (!~N[v].dfn) {
                Tarjan(v, u);
                if (N[v].low1 <= N[u].low1) {
                    N[u].low2 = N[u].low1;
                    N[u].s2 = N[u].s1;
                    N[u].low1 = N[v].low1;
                    N[u].s1 = N[v].s1;
                } else if (N[v].low1 <= N[u].low2) {
                    N[u].low2 = N[v].low1;
                    N[u].s2 = N[v].s1;
                }
                // N[u].low = min(N[u].low, N[v].low);
            } else if (pa != v) {
                if (N[v].dfn <= N[u].low1) {
                    N[u].low2 = N[u].low1;
                    N[u].s2 = N[u].s1;
                    N[u].low1 = N[v].dfn;
                    N[u].s1 = u;
                } else if (N[v].dfn <= N[u].low2) {
                    N[u].low2 = N[v].dfn;
                    N[u].s2 = u;
                }
                // N[u].low = min(N[u].low, N[v].dfn);
            }
        }
        //       low1
        //       low2
        //      u
        //  s1   s2
        if (N[u].low2 < N[u].dfn && !find) {
            out << toNode[N[u].low2] + 1 << ' ' << u + 1 << '\n';
            auto path1 = go(toNode[N[u].low2], u);
            if (path1.back() != u)
                reverse(path1.begin(), path1.end());
            answer(path1);
            auto path2_1 = go(u, N[u].s1);
            auto path2_2 = go(toNode[N[u].low1], toNode[N[u].low2]);
            for (auto &v : path2_2)
                path2_1.push_back(v);
            if (path2_1.back() != u)
                reverse(path2_1.begin(), path2_1.end());
            answer(path2_1);
            auto path3 = go(u, N[u].s2);
            path3.push_back(toNode[N[u].low2]);
            if (path3.back() != u)
                reverse(path3.begin(), path3.end());
            answer(path3);
            find = true;
        }
        if (find)
            return ;
    }
    void answer(auto &path) {
        out << path.size();
        for (auto &v : path)
            out << ' ' << v + 1;
        out << '\n';
    }
    void print() {
        out << "idx     pa     low1     low2     s1     s2\n";
        for (int i = 0 ; i < N.size() ; i++) {
            out << "Node " << i + 1 << ": " << N[i].pa + 1 << ' ' << toNode[N[i].low1] + 1 << ' ' << toNode[N[i].low2] + 1 << ' ' << N[i].s1 + 1 << ' ' << N[i].s2 + 1 << endl;
        }
    }
    vector<int> go(int s, int t) {
        vector<int> path;
        while (t != s)
            path.push_back(t), t = N[t].pa;
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
    }
    void run() {
        stamp = 0;
        int n = N.size();
        for (int i = 0 ; i < n ; i++) {
            if (~N[i].dfn)
                continue;
            Tarjan(i, i);
            if (find)
                break;
        }
        if (!find) {
            out << -1 << '\n';
        }
    }
} solver;
void solve() {
    int n, m; in >> n >> m;
    solver.init(n);
    while (m--) {
        int u, v; in >> u >> v, u--, v--;
        solver.addEdge(u, v);
    }
    solver.run();
}
int main() {
    int t; in >> t; while (t--)
        solve();
}
