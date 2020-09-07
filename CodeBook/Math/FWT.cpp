#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
void FWT(vector<LL> &x, int inv = 0) { int n=x.size();
  for (int i = 1 ; i < n ; i <<= 1) {
    for (int j = 0 ; j < n ; j++) // or
      if (j & i)
        x[j] = inv ? x[j] - x[j ^ i] : x[j] + x[j ^ i];
    for (int j = 0 ; j < n ; j += (i << 1)) // and
      for (int k = 0 ; k < i ; k++)
        x[j + k] = inv ? x[j + k] - x[j + k + i] 
          : x[j + k] + x[j + k + i];
    for (int j = 0 ; j < n ; j += (i << 1)) // xor
      for (int k = 0 ; k < i ; k++) {
        int y = x[j + k], z = x[j + k + i];
        x[j + k] = inv ? (y + z) / 2 : y + z;
        x[j + k + i] = inv ? (y - z) / 2 : y - z;
      }
  }
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<LL> x{3, 2, 6, 1, 0, 0, 0, 0}, y{5, 2, 1, 5, 0, 0, 0, 0};
  FWT(x); FWT(y);
  for (int i = 0 ; i < 8 ; i++)
      x[i] *= y[i];
  FWT(x, 1);
  for (int i = 0 ; i < 8 ; i++)
      cout << x[i] << ' ';
  cout << '\n';
}
