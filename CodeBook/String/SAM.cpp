#include <bits/stdc++.h>
#define PB push_back
using namespace std;
using VI = vector<int>;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int maxV = -INF, ansl = -1, ansr = -1;
int f(int n, int l, int r) { return r - l + 1 - max(l, n - r - 1); }
// LatexBegin
struct SAM { struct Node : map<char,int> {int p,len;};
  vector<Node> N; int last; void init() { N.clear(); }
  void build(string s) { N.PB({{}, -1, last = 0});
    int len = 0; for (auto &c : s) { 
      int p = last, r = N.size(); N.PB({{}, 0, ++len});
      while (~p&&!N[p].count(c)) N[p][c]=r,p=N[p].p;
      if (~p) { int q = N[p][c]; 
        if (N[p].len + 1 != N[q].len) {
          N.PB(N[q]); N.back().len = N[p].len + 1;
          int qq = N.size() - 1; N[q].p = N[r].p = qq;
          while (~p&&N[p][c]==q) N[p][c]=qq,p=N[p].p;
      } else N[r].p = q; } last = r;
    }
  }
  void search(string &t) { int u = 0, len = 0;
    for (int r = 0 ; r < t.size() ; r++) {
      char c = t[r]; if (!N[u].count(c)) {
        while (~u && !N[u].count(c)) u = N[u].p;
        bool x = (~u && N[u].count(c));
        if (x) len = N[u].len + 1, u = N[u][c];
        else u = max(u, 0), len = N[u].len;
      } else len++, u = N[u][c]; // t[r-len+1, r+1)
// LatexEnd
      if (len == 0) continue; int l = r - len + 1;
      if (maxV < f(t.size(), l, r))
        ansl = l, ansr = r, maxV = f(t.size(), l, r);
// LatexBegin
    }
  }
} solver;
// LatexEnd
int main() {
  solver.init(); string s, t; cin >> s >> t;
  solver.build(t); solver.search(s);
  cout << ansl << ' ' << ansr << '\n';
}
