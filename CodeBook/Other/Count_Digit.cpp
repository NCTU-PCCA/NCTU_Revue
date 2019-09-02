#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// LatexBegin
LL CountDigit(LL n, int x) {
  LL ret = 0;
  for (LL m = 1; m <= n; m *= 10) {
    if (x != 0)
      ret += (n / m + 9 - x) / 10 * m
          + (n / m % 10 == x) * (n % m + 1);
    else
      ret += (n / m - 1) / 10 * m
          + (n / m % 10 == 0) * (n % m + 1);
  }
  return ret;
}
// LatexEnd

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while (T --) {
        LL n; cin >> n;
        int state = 0;
        for (int i = 0; i < 10; i ++) {
            if (state) cout << ' ';
            cout << CountDigit(n, i);
            state = 1;
        }
        cout << '\n';
    }
}
