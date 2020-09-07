#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define F first
#define S second
// LatexBegin
const ll mod = 998244353;
ll pre[maxn], inv[maxn], prei[maxn];
void build(int n){
  pre[1]=pre[0]=inv[1]=inv[0]=prei[1]=prei[0]=1;
  for (int i = 2 ; i <= n ; i++) {
    pre[i] = pre[i-1] * i % mod;
    inv[i] = (mod - mod / i * inv[mod % i] % mod)%mod;
    prei[i] = prei[i-1] * inv[i] % mod;
  }
}
ll C(int n, int k){
  return pre[n] * prei[k] % mod * prei[n-k] % mod;
}
ll P(int n, int k) {
  return pre[n] * prei[n - k] % mod;
}
ll pm(int n,int p){
  ll ret = 1, now = n; while (p) {
    if (p & 1) ret *= now, ret %= mod;
    now *= now, now %= mod, p >>= 1;
  }
  return ret;
}
// LatexEnd
int main() {

}
