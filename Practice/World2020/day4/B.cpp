#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

struct Blossom { int stamp;
  struct Node : vector<int> {
    int f, p, v, m, S; Node() { m = v = -1; }
  };
  vector<Node> N; queue<int> q;
  void init(int n) {
    N.clear(); N.resize(n); stamp = 0;
  }
  void addEdge(int u, int v) {
    N[u].push_back(v); N[v].push_back(u);
  }
  int find(int x) {
    return x == N[x].f ? x : N[x].f = find(N[x].f);
  }
  int lca(int x, int y) {
    for (stamp++, x=find(x), y=find(y);; swap(x, y)) {
      if (!~x) continue; if (N[x].v == stamp) return x;
      N[x].v = stamp; x = N[x].m; if (!~x) continue;
      x = N[x].p; if (!~x) continue; x = find(x);
    }
  }
  inline void qpush(int x) { q.push(x); N[x].S = 0; }
  void flower(int x, int y, int l) {
    while (find(x) != l) {
      N[x].p = y; y = N[x].m; qpush(y);
      if (N[x].f == x) N[x].f = l;
      if (N[y].f == y) N[y].f = l;
      x = N[y].p;
    }
  }
  void match(int s) {  while (q.size()) q.pop();
    for (int i = 0 ; i < N.size() ; i++)
      N[i].f = i, N[i].S = -1;
    qpush(s); while (q.size()) {
      int u = q.front(), l; q.pop();
      for (auto v : N[u]) if (!~N[v].S) {
        N[v].p = u; N[v].S = 1;
        if (!~N[v].m) { swap(u, v);
          for (; ~v ; u = l, v = ~u ? N[u].p : u)
            l = N[v].m, N[v].m = u, N[u].m = v;
          return ;
        } qpush(N[v].m);
      } else if (!N[v].S && find(v) != find(u))
        l = lca(v, u), flower(v,u,l), flower(u,v,l);
    }
  }
  void run() {
    for (int i = 0 ; i < N.size() ; i++)
      random_shuffle(N[i].begin(), N[i].end());
    for (int i = 0 ; i < N.size() ; i++)
      if (!~N[i].m) match(i);
  }
} solver;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    solver.init(n);
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        solver.addEdge(u, v);
    }
    solver.run();
    for (int i = 0 ; i < n ; i++) {
        if (solver.N[i].m == -1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
