#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
template <typename T> struct DirectedMST {
  struct Node { int u, v, l, r; T w, tag; };
  vector<Node> N; T w; vector<int> st, id, pq, E;
	void init(int n) { st.assign(n * 2, 0); w = 0;
    iota(st.begin(), st.begin() + n, 0); id = st;
    N.push_back({}); pq.assign(n * 2, 0); E = pq;
	}
  int copy(int u, int v, T w) { int m = N.size();
    return N.push_back({u, v, 0, 0, w, 0}), m;
  }
  void addEdge(int u, int v, T w) {
    if (u != v) pq[v] = merge(pq[v], copy(u, v, w));
  }
  int merge(int a, int b) {
    if (!a || !b) return a ? a : b;
    if (N[push(b)].w < N[push(a)].w)
        return merge(b, a); swap(N[a].l, N[a].r);
    return N[a].l = merge(b, N[a].l), a;
  }
  int find(int x, auto &st) {
    return st[x] == x ? x : st[x] = find(st[x], st);
  }
  int push(int u) { N[u].w += N[u].tag;
    if (N[u].l) N[N[u].l].tag += N[u].tag;
    if (N[u].r) N[N[u].r].tag += N[u].tag;
    return N[u].tag = 0, u;
  }
  void run(int rt) { int p = pq.size() / 2, all = p;
    for (int i = 0 ; i < p ; i++) {
      if (i == rt || !pq[i]) continue;
      while (pq[i]) { push(pq[i]), E[i] = pq[i];
        pq[i] = merge(N[pq[i]].l, N[pq[i]].r);
        if (find(N[E[i]].u, id) != find(i, id)) break;
      }
      if (find(N[E[i]].u, id) == find(i, id)) continue;
      w += N[E[i]].w;
      if (find(N[E[i]].u, st) == find(i, st)) {
        if (pq[i]) N[pq[i]].tag -= N[E[i]].w;
        pq[++p] = pq[i], id[p] = p;
        int u = find(N[E[i]].u, id); while (u != i) {
          if (pq[u]) N[pq[u]].tag -= N[E[u]].w;
          pq[p] = merge(pq[p], pq[u]);
          id[find(u, id)] = p; u = find(N[E[u]].u, id);
        }
        st[p] = find(i, st); id[find(i, id)] = p;
      } else
        st[find(i, st)] = find(N[E[i]].u, st), --all;
    }
    if (all != 1) w = -INF;
  }
};
// LatexEnd
DirectedMST<LL> solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    solver.init(n);
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w; u--, v--;
        solver.addEdge(u, v, w);
    }
    solver.run(0);
    if (solver.w == -INF)
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << solver.w << '\n';
    }
}
