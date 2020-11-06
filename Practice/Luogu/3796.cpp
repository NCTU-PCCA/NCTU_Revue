#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
using namespace std;
struct AC { struct Node; vector<Node> N; int r, st;
  struct Node : map<char, int> { int p, nx; vector<int> id; };
  void init() { N.PB({{}}); r = newNode(); st = 0; }
  int newNode() { N.PB({{}}); return N.size() - 1; }
  void addTrie(string &s) { int u = r;
    for (auto &c : s) { if (!N[u].count(c))
      N[u][c] = newNode(); u = N[u][c];
    }
    N[u].id.push_back(st++);
  }
  void buildAC() { static queue<int> q; q.push(r);
    while (q.size()) { int u = q.front(); q.pop();
      for (auto &p : N[u])
        N[p.S].p = N[p.S].nx = trans(N[u].p, p.F), q.push(p.S);
    }
  }
  int trans(int u, char c) { if (!u) return r;
    if (!N[u].count(c)) N[u][c] = trans(N[u].p, c);
    return N[u][c];
  }
  int next(int u) { if (!N[u].nx) return r;
    return N[N[u].nx].id.size() ? N[u].nx : N[u].nx = next(N[u].nx);
  }
} solver;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  solver.init();
  vector<string> S;
  vector<int> cnt(n, 0);
  for (int i = 0 ; i < n ; i++) {
    string s; cin >> s; solver.addTrie(s);
    S.push_back(s);
  }
  solver.buildAC();
  string t; cin >> t;
  auto &N = solver.N; int u = solver.r;
  for (auto &c : t) {
    u = solver.trans(u, c);
    int v = u; while (v != solver.r) {
      if (N[v].id.size() && !cnt[N[v].id[0]])
        for (auto &x : N[v].id)
          cnt[x] = 1;
      v = solver.next(v);
    }
  }
  int sum = 0;
  for (int i = 0 ; i < n ; i++)
    sum += cnt[i];
  cout << sum << '\n';
}
