#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
// does not work when n is prime
LL modit(LL x, LL mod) {
  while (x < 0) x += mod; return x % mod;
}
LL mult(LL x, LL y, LL mod) { LL s = 0, m = x % mod;
  while (y) { if (y & 1) s = modit(s + m, mod);
	y >>= 1; m = modit(m + m, mod);
  }
  return s;
}
LL f(LL x, LL mod) {
  return modit(mult(x, x, mod) + 1, mod);
}
LL pollardRho(LL n) { if(!(n & 1)) return 2; 
  while (1) {
    LL y = 2, x = rand() % (n - 1) + 1, res = 1;
    for (int sz = 2 ; res == 1 ; sz *= 2) {
      for (int i = 0 ; i < sz && res <= 1 ; i++)
        x = f(x, n), res = __gcd(abs(x - y), n); y = x;
    }
    if (res != 0 && res != n) return res;
  }
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << pollardRho(28374985) << '\n';
}
