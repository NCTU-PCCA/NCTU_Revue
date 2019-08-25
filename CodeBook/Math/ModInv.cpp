#include <bits/stdc++.h>
#include "Extgcd.cpp"
using namespace std;
typedef long long LL;
// LatexBegin
LL modInv(LL a, LL m) {
    LL x, y, d = extgcd(a, m, x, y);
    return d == 1 ? (x + m) % m : -1;
}
// LatexEnd
