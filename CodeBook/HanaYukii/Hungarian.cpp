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
int k, match[505], check[505];
vector<int>g[505];
bool dfs(int x) {
  for (auto i : g[x]) { 
    if (check[i]) continue;
    check[i] = 1;
    if (!match[i])
      return match[i] = x, 1;
    else if (dfs(match[i]))
      return match[i] = x, 1;
  }
  return 0;
}
void solve() {
  memset(match, 0 ,sizeof(match));
  int n, m; cin >> n >> m;
  f1(n) g[i].clear();
  f(k) {
    int a, b; cin >> a >> b; g[a].pb(b);
  }
  int ans = 0;
  f1(n) { memset(check, 0, sizeof(check));
    if (dfs(i)) ans++;
  }
  cout << ans << '\n';
}
// LatexEnd
int main() {

}
