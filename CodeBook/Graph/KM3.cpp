// Maximum Bipartite Weighted Matching (Perfect Match)
struct KM{
  //static const int MXN = 650;
  const LL INF = 1112147483647ll; // long long
  int px[MAXN],py[MAXN],match[MAXN],par[MAXN],n;
  LL g[MAXN][MAXN],lx[MAXN],ly[MAXN],slack_y[MAXN];
  // ^^^^ long long
  void init(int _n) { n = _n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) g[i][j]=0;
  }
  void add_edge(int x, int y, LL w){ // long long
    g[x][y] = w;
  }
  void adjust(int y){match[y]=py[y];
    if(px[match[y]]!=-2)adjust(px[match[y]]);
  }
  bool dfs(int x){
    for (int y = 0 ; y < n ; ++y) {
      if (py[y]!=-1) continue;
      LL t = lx[x] + ly[y] - g[x][y];
      if (t == 0) { py[y] = x;
        if (match[y] == -1)
          return adjust(y), true;
        if (px[match[y]] != -1) continue;
        px[match[y]] = y;
        if (dfs(match[y])) return 1;
      } else if(slack_y[y] > t)
        slack_y[y]=t, par[y]=x;
    }
    return 0;
  }
  LL solve(){ fill(match,match+n,-1); fill(ly,ly+n,0);
    for (int x = 0 ; x < n ; ++x) { lx[x] = -INF;
      for (int y = 0 ; y < n ; ++y)
        lx[x] = max(lx[x], g[x][y]);
    }
    for (int x = 0 ; x < n ; ++x) {
      for (int y = 0 ; y < n ; ++y) slack_y[y] = INF;
      fill(px, px+n, -1); fill(py, py+n, -1); px[x]=-2;
      if(dfs(x)) continue;
      bool flag = 1; while(flag) {
        LL cut = INF; //long long
        for (int y = 0 ; y < n ; ++y)
          if (py[y] == -1) cut = min(cut, slack_y[y]);
        for (int j = 0 ; j < n ; ++j) {
          if (px[j] != -1) lx[j] -= cut;
          if (py[j] != -1) ly[j] += cut;
          else slack_y[j] -= cut;
        }
        for (int y = 0 ; y < n ; ++y) {
          if (py[y] == -1 && slack_y[y] == 0) {
            py[y] = par[y];
            if (match[y] == -1) {
              adjust(y); flag=0; break;
            }
            px[match[y]] = y;
            if (dfs(match[y])) {
              flag=0; break;
            }
          }
        }
      }
    }
    LL res = 0;
    for (int i = 0 ; i < n ; ++i) res+=g[match[i]][i];
    return res;
  }
}graph;
