#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
vector<LL> LinearModInv(int n, LL m) {
  vector<LL> inv{1, 1};
  for (int i = 2 ; i <= n ; i++)
    inv.push_back((m - m / i * inv[m % i] % m) % m);
  return inv;
}
// LatexEnd
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  LL mod = 1e9 + 7;
  vector<LL> inv = LinearModInv(10, mod);
  for (int i = 1 ; i <= 10 ; i++)
    cout << inv[i] * i % mod << '\n';
}
