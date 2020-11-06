#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
// LatexBegin
template <typename V> struct ODTree {
  map<pii, V> odt; int n;
  ODTree(int n, V v) : n(n) { odt[{0, n}] = v; }
  auto split(int x) { if (x == n) return odt.end();
    auto it = --odt.upper_bound({x, n});
    if (it->F.F == x) return it;
    int l = it->F.F, r = it->F.S; V v = it->S;
    odt.erase(it); odt[{l, x}] = odt[{x, r}] = v;
    return odt.lower_bound({x, r});
  }
  void assign(int l, int r, V v) {
    auto itr = split(r), itl = split(l);
    odt.erase(itl, itr); odt[{l, r}] = v;
  }
  void perform(int l, int r) {
    auto itr = split(r), itl = split(l);
    for (auto &it = itl ; it != itr ; it++) {
      // do
    }
  }
};
// LatexEnd
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
}
