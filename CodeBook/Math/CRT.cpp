#include <bits/stdc++.h>
#include "Extgcd.cpp"
#include "ModInv.cpp"
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
// LatexBegin
pLL CRT(vector<LL> &A, vector<LL> &B, vector<LL> &M) {
  // A[i]x = B[i] (mod M[i]); F : ans, S : lcm of M;
  LL x = 0, m = 1; for (int i = 0; i < A.size(); i++) {
    LL a = A[i] * m, b = B[i] - A[i] * x;
    LL d = __gcd(M[i], a); if (b % d) return pLL(0,-1);
    LL t = b / d * modInv(a / d, M[i] / d) % (M[i]/d);
    x = x + m * t; m *= M[i] / d;
  }
  return x = (x % m + m) % m, pLL(x, m);
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int kase = 0; while (1) {
    vector<LL> A, B, M; 
    vector<LL> mod{23, 28, 33};
    for (int i = 0 ; i < 3 ; i++) {
      LL input; cin >> input; if (input == -1) exit(0);
      A.push_back(1); B.push_back(input); M.push_back(mod[i]);
    }
    LL D; cin >> D;
    pLL ans = CRT(A, B, M);
    while (ans.first <= D) ans.first += ans.second;
    cout << "Case " << ++kase << ": the next triple peak occurs in ";
    cout << ans.first - D << " days.\n";
  }
}
