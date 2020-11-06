#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
LL modPow(LL a, LL x, LL m){
  if (x == 0) return 1; LL k = modPow(a, x / 2, m);
  if (x & 1) return k * k % m * a % m;
  else return k * k % m;
}
const int MAXN = 1e9 + 5;
const int sqrtN = sqrt(MAXN) + 5;
vector<bool> isPrime(sqrtN, true);
vector<int> Prime;
void prime(){ isPrime[0] = isPrime[1] = false;
  for (int i = 2 ; i < sqrtN ; i++) {
      if (isPrime[i]){ Prime.push_back(i);
      for (int j = 2 * i ; j < sqrtN ; j += i)
        isPrime[j] = false;
    }
  }
}
bool isPrimativeRoot(int a, int x){
  vector<int> primeFactor; int target = x - 1;
  for (auto p : Prime) { if (target < p) break;
    bool _find = false;
    while (target % p == 0) target /= p, _find = true;
    if (_find) primeFactor.push_back(p);
  }
  for (auto p : primeFactor)
    if (modPow(a, (x - 1) / p, x) == 1) return false;
  return true;
}
int getPrimativeRoot(int n) {
  prime(); int ans = 0; while (1) {
    ans++; if (!isPrimativeRoot(ans, n)) continue;
    return ans;
  }
}
// LatexEnd
int main() {
    prime();
    int t; cin >> t; while (t--) {
        int n, d; cin >> n >> d;
        vector<int> res;
        for (int i = 1 ; i < n ; i++)
            if (isPrimativeRoot(i, n))
                res.push_back(i);
        cout << res.size() << '\n';
    }
  
}
