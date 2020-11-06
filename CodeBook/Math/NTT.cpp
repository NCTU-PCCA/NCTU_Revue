#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
// LatexBegin
int fpow(int a, int n, int P) {
  int r = 1; while (n) {
    if (n & 1) 
      r = 1ll * r * a % P;
    a = 1ll * a * a % P; n >>= 1;
  }
  return r;
}
const int P = 998244353, R = 3, MAXN = (1 << 23);
// Remember coefficient are mod P
/*
p=a*2^n+1 degree(poly) <= 2^n
n 2^n   p     a  root
16 65536  65537    1  3
20 1048576  7340033    7  3
23    998244353   119  3   
*/
struct Poly : vector<int> { int n; 
  Poly (int n) : n(n) { this->resize(n); }
  int extend(int x) { 
    int N = 1; while (N < x) N <<= 1; return N;
  }
  Poly operator * (const Poly &rhs) {
    Poly a = *this, b = rhs;
    int N = extend(n + rhs.n - 1);
    a.resize(a.n = N); a.ntt(1);
    b.resize(b.n = N); b.ntt(1);
    for (int i = 0 ; i < N ; i++) 
      a[i] = 1ll * a[i] * b[i] % P;
    return a.ntt(-1), a.n = n + rhs.n, a;
  }
  void ntt(int op) { static Poly r(MAXN);
    for (int i = 0 ; i < n ; i++) {
      r[i] = (i & 1) * (n >> 1) + (r[i >> 1] >> 1);
      if (r[i] < i) std::swap(at(i), at(r[i]));
    }
    for (int m = 2 ; m <= n ; m <<= 1) {
      int k = m >> 1, gn = fpow(R, (P - 1) / m, P);
      for (int i = 0 ; i < n ; i += m) { int g = 1;
        for (int j = 0 ; j < k ; j++, g = 1ll * g * gn % P) {
          int tmp = 1ll * at(i + j + k) * g % P;
          at(i + j + k) = (at(i + j) - tmp + P) % P;
          at(i + j) = (at(i + j) + tmp) % P;
        }
      }
    }
    if (op == -1) { 
      reverse(begin() + 1, end());
      int inv = fpow(n, P - 2, P);
      for (int i = 0 ; i < n ; i++)
        at(i) = 1ll * at(i) * inv % P;
    }
  }
  bool operator < (const Poly &b) const {
    return n > b.n;
  }
};
// LatexEnd
int main() {

}
