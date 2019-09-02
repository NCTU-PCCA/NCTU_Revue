#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222;
const int MAXM = 222;
const double EPS = 1e-10;
// LatexBegin
double a[MAXN][MAXM], b[MAXN], c[MAXM], d[MAXN][MAXM];
double x[MAXM];
int ix[MAXN + MAXM]; // !!! array all indexed from 0
// max{cx} subject to {Ax<=b,x>=0}
// n: constraints, m: vars !!!
// x[] is the optimal solution vector
//
// usage : 
// value = simplex(a, b, c, N, M);
double simplex(double a[MAXN][MAXM], double b[MAXN], double c[MAXM], int n, int m) {
  ++m; int r = n, s = m - 1; memset(d, 0, sizeof(d));
  for (int i = 0; i < n + m; ++i) ix[i] = i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j)
      d[i][j] = -a[i][j];
    d[i][m - 1] = 1; d[i][m] = b[i];
    if (d[r][m] > d[i][m]) r = i;
  }
  for (int j = 0; j < m - 1; ++j) d[n][j] = c[j];
  d[n + 1][m - 1] = -1;
  for (double dd;; ) { 
    if (r < n) { int t = ix[s];
      ix[s] = ix[r + m]; ix[r + m] = t;
      d[r][s] = 1.0 / d[r][s];
      for (int j = 0; j <= m; ++j)
        if (j != s) d[r][j] *= -d[r][s];
      for (int i = 0; i <= n + 1; ++i)
        if (i != r) { for (int j = 0; j <= m; ++j)
            if (j != s) d[i][j] += d[r][j]*d[i][s];
          d[i][s] *= d[r][s];
        }
    }
    r = -1; s = -1;
    for (int j = 0; j < m; ++j)
      if (s < 0 || ix[s] > ix[j]) {
        if (d[n + 1][j] > EPS || (d[n + 1][j] > -EPS 
         && d[n][j] > EPS)) s = j;
      }
    if (s < 0) break;
    for (int i=0; i<n; ++i) if (d[i][s] < -EPS) {
      if (r < 0 || (dd = d[r][m] / d[r][s] - d[i][m] / d[i][s]) < -EPS || (dd < EPS && ix[r + m] > ix[i + m])) r = i;
    }
    if (r < 0) return -1; // not bounded
  }
  if (d[n + 1][m] < -EPS) return -1; // not executable
  double ans = 0;
  for(int i=0; i<m; i++) x[i] = 0;
  for (int i = m; i < n + m; ++i) { // the missing enumerated x[i] = 0
    if (ix[i] < m - 1) {
      ans += d[i - m][m] * c[ix[i]]; 
      x[ix[i]] = d[i-m][m];
    }
  }
  return ans; 
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; while (cin >> n >> m) {
    for (int i = 0 ; i < n ; i++) cin >> c[i];
    for (int i = 0 ; i < m ; i++) {
      for (int j = 0 ; j < n ; j++)
        cin >> a[i][j];
      cin >> b[i];
    }
    cout << "Nasa can spend " << ceil(simplex(a, b, c, m, n) * m) << " taka.\n";
  }
}
