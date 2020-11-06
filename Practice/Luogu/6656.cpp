#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
using namespace std;
using VI = vector<int>;
// LatexBegin
#define NX(x) ((x+k)%n)
#define C(a,b) (V[a]==V[b]?V[NX(a)]<V[NX(b)]:V[a]<V[b])
#define go(XD) V2[sa[0]]=N=0; \
  for(int i=1;i<n;i++) N+=XD, V2[sa[i]]=N; V=V2;
#define RSP sa, n, N+1
void RS(auto &sa, int n, int N, auto &V) { 
  VI B(N), t(n); for (auto &v : sa) B[V[v]]++;
  partial_sum(ALL(B), B.begin()); int i = n;
  while (i--) t[--B[V[sa[i]]]] = sa[i]; sa = t;
}
VI SA(string &s) { int n = s.size(), k = 0, N = 255;
  VI sa(n), V(n), V2(n); iota(ALL(sa), 0); 
  RS(RSP, s); go(s[sa[i - 1]] != s[sa[i]]);
  for (int k = 1 ; N + 1 < n ; k <<= 1, k %= n) { 
    for (auto &v : sa) (v += n - k) %= n; RS(RSP, V);
    go(C(sa[i - 1], sa[i]) || C(sa[i], sa[i - 1]));
  } return sa; 
}
VI LCP(string &s, auto &sa) { int n = s.size();
  VI lcp(n), ra(n); for (int i=0;i<n;i++) ra[sa[i]]=i;
  for (int i = 0, k = 0 ; i < n ; i++) {
    if (ra[i]) while(s[i+k] == s[sa[ra[i]-1]+k]) k++;
    lcp[ra[i]] = k; k = max(0, k - 1);
  } return lcp; 
}
// LatexEnd
int magic(int v, vector<int> &pre) {
  return --upper_bound(pre.begin(), pre.end(), v) - pre.begin();
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin >> s; s += '$';
  auto sa = SA(s);
  auto lcp = LCP(s, sa);
  for (int i = 0 ; i < sa.size() ; i++)
    cout << lcp[i] << ' ' << s.substr(sa[i]) << '\n';
}
