#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
using namespace std;
// LatexBegin
struct AC { struct Node; vector<Node> N; 
// LatexEnd
/*
// LatexBegin
  struct Node : map<char, int> { int p, nx; }; int r;
// LatexEnd
*/
  struct Node : map<char, int> { int p, dp, vis, nx; 
    vector<int> idx;
  }; int r;
// LatexBegin
  void init() { N.PB({{}}); r = newNode(); }
  int newNode() { N.PB({}); return N.size() - 1; }
  void addTrie(string &s) { int u = r;
    for (auto &c : s) { if (!N[u].count(c)) 
      N[u][c] = newNode(); u = N[u][c];
    }
// LatexEnd
    N[u].dp++;
// LatexBegin
  }
  void buildAC() { static queue<int> q; q.push(r);
    while (q.size()) { int u = q.front(); q.pop();
      for (auto &p : N[u])
        N[p.S].p = N[p.S].nx = trans(N[u].p, p.F),
        q.push(p.S);
    }
  }
  int trans(int u, char c) { if (!u) return r;
    if (!N[u].count(c)) N[u][c] = trans(N[u].p, c);
    return N[u][c];
  }
  int next(int u) {
    if (N[u].nx == 0) return r;
    if (N[N[u].nx].idx.size()) return N[u].nx;
    return N[u].nx = next(N[u].nx);
  }
} solver;
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t; while (t--) {
    solver.init();
    int n; cin >> n; while (n--) {
      string s; cin >> s; solver.addTrie(s);
    }
    solver.buildAC();
    string s; cin >> s;
    auto &N = solver.N; int u = solver.r, ans = 0;
    for (auto &c : s) {
      u = solver.trans(u, c);
      int p = u; while (p && !N[p].vis) {
        ans += N[p].dp;
        N[p].vis = 1;
        p = N[p].p;
      }
    }
    cout << ans << '\n';
  }
}
