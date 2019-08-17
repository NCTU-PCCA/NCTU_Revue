double MMC(vector<vector<Edge> > &G) {
  int n = G.size(); G.resize(n + 1);
  for (int i = 0 ; i < n ; i++)
    G[n].push_back({i, 0});
  n++;
  vector<vector<LL> > d(n, vector<LL>(n + 1, INF));
  d[n - 1][0] = 0;
  for (int k = 1 ; k <= n ; k++)
    for (int i = 0 ; i < n ; i++)
      for (auto &e : G[i])
        d[e.v][k] = min(d[e.v][k], d[i][k - 1] + e.w);
  double minW = INF;
  for (int i = 0 ; i < n ; i++) {
    double maxW = -INF;
    for (int k = 0 ; k < n ; k++)
      maxW = max(maxW, (d[i][n] - d[i][k]) / double(n - k));
    minW = min(minW, maxW);
  }
  return minW;
}
