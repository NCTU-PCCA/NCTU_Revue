#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
LL modMul(LL a, LL b, LL m) { a %= m, b %= m;
  LL y = (LL)((double)a * b / m + .5);
  LL r = (a * b - y * m) % m;
  return r < 0 ? r + m : r;
}
LL pow(LL a, LL b, LL m) { LL ret = 1;
  for (; b; a = modMul(a, a, m), b >>= 1)
    if (b % 2) ret = modMul(ret, a, m);
  return ret;
}
bool isPrime(LL n) {
  LL sprp[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  if (n == 2) return true; if (n < 2 || n % 2 == 0) return false;
  LL t = 0, u = n - 1; for (; u % 2 == 0; t++) u >>= 1;
  for (int i = 0 ; i < 7 ; i++){ LL a = sprp[i] % n;
    if (a == 0 || a == 1 || a == n-1) continue;
    LL x = pow(a, u, n); if (x == 1 || x == n-1) continue;
    for (int j = 1 ; j < t ; j++){ x = modMul(x, x, n);
      if (x == 1) return false; if (x == n - 1) break;
    }
    if (x == n - 1) continue; return false;
  }
  return true;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  LL x; while (cin >> x) cout << isPrime(x) << '\n';
}
