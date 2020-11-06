// LatexBegin
// Minimum Weight Perfect Matching (Perfect Match)
const int MAXN = 105;
struct Graph { vector<int> stk;
  int n,e[MAXN][MAXN],match[MAXN],d[MAXN],onstk[MAXN];
  void init(int _n) { n = _n;
    for (int i = 0 ; i < n ; i++)
      for (int j = 0 ; j < n ; j++)
        e[i][j] = 0;
  }
  void add_edge(int u, int v, int w) {
    e[u][v] = e[v][u] = w;
  }
  bool SPFA(int u){
    if (onstk[u]) return true;
    stk.push_back(u); onstk[u] = 1;
    for (int v = 0 ; v < n ; v++) {
      if (u != v && match[u] != v && !onstk[v] ) {
        int m = match[v];
        if (d[m] > d[u] - e[v][m] + e[u][v]) {
          d[m] = d[u] - e[v][m] + e[u][v];
          stk.push_back(v); onstk[v] = 1;
          if (SPFA(m)) return true;
          stk.pop_back(); onstk[v] = 0;
        }
      }
    }
    return onstk[u] = 0, stk.pop_back(), false;
  }
  int solve() {
    for (int i = 0 ; i < n ; i += 2)
      match[i] = i + 1, match[i + 1] = i;
    while (1) { int found = 0;
      for (int i = 0 ; i < n ; i++) onstk[i]=d[i]=0;
      for (int i = 0 ; i < n ; i++) { stk.clear();
        if (!onstk[i] && SPFA(i)) { found = 1;
          while (stk.size() >= 2) {
            int u = stk.back(); stk.pop_back();
            int v = stk.back(); stk.pop_back();
            match[u] = v; match[v] = u;
          }
        }
      }
      if (!found) break;
    }
    int ret = 0;
    for ( int i = 0 ; i < n ; i++ )
      ret += e[i][match[i]];
    ret /= 2;
    return ret;
  }
} graph;
// LatexEnd
