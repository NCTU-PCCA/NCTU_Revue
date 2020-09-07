#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
// LatexBegin
// finds all numbers x such that x^k = a (mod n)
vector<LL> discreteRoot(LL k, LL a, LL n) {
  if (a == 0) return {0};
  int g = getPrimativeRoot(n);
  // Baby-step giant-step discrete logarithm algorithm
  LL sq = (LL) sqrt (n + .0) + 1;
  vector<pair<int, int>> dec(sq);
  for (int i = 1; i <= sq; ++i)
    dec[i-1] = {modPow(g, i * sq * k % (n - 1), n), i};
  sort(dec.begin(), dec.end()); int any_ans = -1;
  for (int i = 0; i < sq; ++i) {
    int my = modPow(g, i * k % (n - 1), n) * a % n;
    auto it = lower_bound(
      dec.begin(), dec.end(), make_pair(my, 0)
    );
    if (it != dec.end() && it->first == my) {
      any_ans = it->second * sq - i;
      break;
    }
  }
  if (any_ans == -1) return {};
  // Print all possible answers
  int del = (n-1) / gcd(k, n-1);
  vector<LL> ans;
  for (int cur = any_ans % del; cur < n-1; cur += del)
    ans.push_back(modPow(g, cur, n));
  return sort(ans.begin(), ans.end()), ans;
}
// LatexEnd
int main() {
  int n, k, a; cin >> n >> k >> a;
  discreteRoot(k, a, n);
}
