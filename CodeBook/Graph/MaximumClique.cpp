#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
// LatexBegin
int best, n, num[MAXN], path[MAXN], G[MAXN][MAXN];
bool dfs(int *adj, int total, int cnt) { int t[MAXN];
  if (total == 0)
    return best < cnt ? best = cnt, true : false;
  for (int i = 0 ; i < total ; i++){
    if (cnt + (total - i) <= best) return false;
    if (cnt + num[adj[i]] <= best) return false;
    int k = 0;
    for (int j = i + 1; j < total ; j++)
      if (G[adj[i]][adj[j]])
        t[k++] = adj[j];
    if (dfs(t, k, cnt + 1)) return true;
  }
  return false;
}
int MaximumClique() { int adj[MAXN]; best = 0;
  if (n <= 0) return 0;
  for (int i = n - 1 ; i >= 0 ; i--) { int k = 0;
    for (int j = i + 1; j < n ; j++)
      if (G[i][j]) adj[k++] = j;
    dfs(adj, k, 1); num[i] = best;
  }
  return best;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m; cin >> n >> m;
  memset(G, 0, sizeof(G));
  while (m--) {
    int u, v; cin >> u >> v;
    G[u][v] = G[v][u] = 1;
  }
  cout << MaximumClique() << '\n';
}
