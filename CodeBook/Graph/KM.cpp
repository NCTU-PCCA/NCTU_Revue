#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 1e3 + 5;
typedef long long LL;
typedef pair<LL, LL> pLL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
// LatexBegin
struct KM { LL W[MAXN][MAXN]; int V;
  LL mx[MAXN], my[MAXN]; LL lx[MAXN], ly[MAXN];
  bool x[MAXN], y[MAXN];
  KM(int V) : V(V) { memset(W, 0, sizeof(W)); }
  bool augment(int u) { x[u] = 1;
    for (int i = 0 ; i < V ; i++)
      if (!y[i] && W[u][i] == lx[u]+ly[i] && (y[i]=1))
         if (!~my[i] || augment(my[i]))
          return my[i] = u, true;
    return false;
  }
  LL run() { memset(mx, -1, sizeof(mx)); 
    memset(my, -1, sizeof(my));
    for (int i = 0 ; i < V ; i++) 
      lx[i] = -INF, ly[i] = 0;
    for (int i = 0 ; i < V ; i++)
      for (int j = 0 ; j < V ; j++)
        lx[i] = max(lx[i], W[i][j]);
    for (int i = 0 ; i < V ; i++) { while (1) {
        memset(x, false, sizeof(x));
        memset(y, false, sizeof(y));
        if (augment(i)) break; LL d = INF;
        for (int j = 0 ; j < V ; j++) {
          if (!x[j]) continue;
          for (int k = 0 ; k < V ; k++) {
            if (y[k]) continue;
            d = min(d, lx[j] + ly[k] - W[j][k]);
          }
        }
        if (d == INF) break;
        for (int j = 0 ; j < V ; j++) {
          if (x[j]) lx[j] -= d; if (y[j]) ly[j] += d;
        }
      }
    }
    LL ret = 0; for (int i = 0 ; i < V ; i++)
      if (~my[i]) ret += W[my[i]][i];
    return ret;
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int R, N; while (cin >> R >> N) {
    KM *km = new KM(max(R, N));
    vector<pLL> r(R), n(N);
    for (auto &p : r)
      cin >> p.F >> p.S;
    for (auto &p : n)
      cin >> p.F >> p.S;
    for (int i = 0 ; i < R ; i++)
      for (int j = 0 ; j < N ; j++)
        km->W[i][j] = -(abs(r[i].F - n[j].F) + abs(r[i].S - n[j].S));
    cout << -km->run() << '\n';
    delete km;
  }
}
