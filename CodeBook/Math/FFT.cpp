#include <bits/stdc++.h>
using namespace std;
// LatexBegin
const double PI = acos(-1.0);
#define O operator
#define CCC (const C& c) const 
struct C { double x,y; 
  C(double x = 0, double y = 0) : x(x), y(y) {}
  C O+CCC { return C(x + c.x, y + c.y); }
  C O-CCC { return C(x - c.x, y - c.y); }
  C O*CCC { return C(x*c.x - y*c.y, x*c.y + y*c.x); }
};
void FFT(vector<C> &c, int T) { int n = c.size();
  for (int i = 1, j = 0 ; i < n ; i++) {
    for (int k = (n >> 1) ; k > (j ^= k) ; k >>= 1);
    if (i < j) swap(c[i], c[j]);
  }
  for (int m = 2 ; m <= n ; m <<= 1) {
    C wm(cos(2 * PI * T / m), sin(2 * PI * T / m));
    for (int k = 0 ; k < n ; k += m) { C w(1.0, 0.0);
      for (int j = 0; j < (m >> 1); j++, w = w * wm) {
        C u = c[k + j], t = w * c[k + j + (m >> 1)];
        c[k + j] = u + t; c[k + j + (m >> 1)] = u - t;
      }
    }
  }
  if (!~T) for (int i = 0 ; i < n ; i++) 
    c[i].x /= n, c[i].y /= n;
}
// LatexEnd
typedef long long LL;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; while (cin >> n) {
    int len = 1; while (len < 2 * n) len <<= 1;
    vector<C> A(len), B(len);
    for (int i = 0 ; i < n ; i++)
      cin >> A[i].x;
    for (int i = 0 ; i < n ; i++)
      cin >> B[i].x;
    FFT(A, 1); FFT(B, 1);
    vector<C> C(len);
    for (int i = 0 ; i < len ; i++)
      C[i] = A[i] * B[i];
    FFT(C, -1);
    for (int i = 0 ; i < 2 * n - 1 ; i++)
      cout << LL(C[i].x + 0.5) << " \n"[i + 1 == 2 * n - 1];
  }
}
