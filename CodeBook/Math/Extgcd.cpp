#ifndef EXTGCD_H
#define EXTGCD_H
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
LL extgcd(LL a, LL b, LL &x, LL &y) {
  if (!b) return x = 1, y = 0, a;
  LL res = extgcd(b, a % b, y, x);
  return y -= a / b * x, res;
}
// LatexEnd
#endif
