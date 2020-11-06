#include <bits/stdc++.h>
#define MEM(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
template <typename T=LL> struct Graph { vector<int> pa;
    LL minCut;
    struct Node : vector<int> {};
    struct Edge { int u, v; T w; };
    vector<Edge> E; vector<Node> N;
    void init(int n) { N.resize(n); }
    void addEdge(int u, int v, T w) { int m = E.size();
        E.push_back({u, v, w}); N[u].push_back(m++);
    }
    int find(int x, auto &pa) {
        return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
    }
    bool isConnected() {
        vector<int> pa(N.size(), -1); int n = N.size();
        for (auto e : E) {
            int u = e.u, v = e.v;
            int x = find(u, pa);
            int y = find(v, pa);
            if (x == y)
                continue;
            if (pa[x] > pa[y]) swap(x, y);
            pa[x] += pa[y]; pa[y] = x;
            n--;
        }
        return n == 1;
    }
    void run() {
        if (!isConnected()) return minCut = 0, void();
        int t = __lg(N.size()) + 1; minCut = INF;
        while (t--) { pa.assign(N.size(), -1);
            minCut = min(minCut, getMinCut(N.size(), pa));
        }
    }
    T getMinCut(int n, auto &pa) {
//        cout << n << endl;
        double p = 1;
        while (p > 0.5) {
            int x, y; do {
                int u = rand() % N.size(), v = rand() % N.size();
                x = find(u, pa), y = find(v, pa);
            } while (x == y);
            if (pa[x] > pa[y]) swap(x, y);
            pa[x] += pa[y], pa[y] = x;
            p *= double(n - 2) / n;
            n--;
        }
        if (n > 2) {
            auto s = clock();
            Graph<LL> G1; G1.init(n);
            Graph<LL> G2; G2.init(n);
            int st = 0;
            for (auto &p : mp)
                p.second = st++;
            for (int i = 0 ; i < N.size() ; i++) {
                if (pa[i] < 0) {
                    for (auto &_e : N[i])
                        G1.addEdge(mp[E[_e].u], mp[E[_e].v], E[_e].w),
                        G2.addEdge(mp[E[_e].u], mp[E[_e].v], E[_e].w);
                }
            }
            G1.run();
            G2.run();
            auto t = clock();
            cout << t - s << endl;
            return min(G1.minCut, G2.minCut);
        } else {
            T sum = 0;
            for (auto &e : E) {
                if (find(e.u, pa) == find(e.v, pa))
                    continue;
                sum += e.w;
            }
            return sum;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    int n, m; cin >> n >> m;
    Graph<LL> solver;
    solver.init(n);
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w; u--, v--;
        solver.addEdge(u, v, w);
    }
    solver.run();
    cout << solver.minCut << '\n';
}
