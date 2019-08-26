#include <bits/stdc++.h>
using namespace std;
// LatexBegin
/*  1: n is square-free with even # of prime factor.
 * -1: n is square-free with odd  # of prime factor.
 * 0: n has a squared prime factor. ex. 18 = 2 * 3 * 3.
 */
const int MAXN = 1e5 + 5;
vector<int> isP, mu, ps;
void mobius() { isP.clear(); isP.resize(MAXN, 1); 
  mu.resize(MAXN); isP[0] = isP[1] = 0; mu[1] = 1;
  for (int i = 2 ; i < MAXN ; i++) {
    if (isP[i]) ps.push_back(i), mu[i] = -1;
    for (auto p : ps) { if (i * p >= MAXN) break;
      isP[i * p] = mu[i * p] = false;
      if (i % p == 0) break; mu[i * p] = -mu[i];
    }
  }
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  mobius();
  int x; while (cin >> x) cout << mu[x] << '\n';
}
