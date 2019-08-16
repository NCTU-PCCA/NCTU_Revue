#include <bits/stdc++.h>
using namespace std;
// LatexBegin
struct BIT {
  vector<int> data; int n;
  BIT(int n) : n(n) {
    data.clear(); data.resize(n + 1, 0);
  }
  int lowbit(int x) { return x & -x; }
  int query(int x) { x++;
    int ret = 0;
    while (x > 0) ret += data[x], x -= lowbit(x);
    return ret;
  }
  void modify(int x, int d) { x++;
    while (x <= n) data[x] += d, x += lowbit(x);
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t, kase = 0; cin >> t; while (t--){
    cout << "Case " << ++kase << ":\n";
    int n; cin >> n;
    BIT *sol = new BIT(n);
    for (int i = 0 ; i < n ; i++) {
      int v; cin >> v;
      sol->modify(i, v);
    }
    string op; while (cin >> op){
      int a, b;
      if (op[0] == 'E') break;
      if (op[0] == 'Q'){
        cin >> a >> b; a--, b--;
        cout << sol->query(b) - sol->query(a - 1) << '\n';
      }
      if (op[0] == 'A'){
        cin >> a >> b; a--;
        sol->modify(a, b);
      }
      if (op[0] == 'S'){
        cin >> a >> b; a--;
        sol->modify(a, -b);
      }
    }
  }
}
