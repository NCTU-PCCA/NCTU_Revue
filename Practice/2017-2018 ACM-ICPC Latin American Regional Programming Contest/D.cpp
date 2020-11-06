#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
template <typename V>
struct ODTree {
  map<pii, V> odt; int n;
  ODTree(int n, V v) : n(n) { odt[{0, n}] = v; }
  auto split(int x) {
    if (x == n) return odt.end();
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
  int sum(int l, int r) {
    auto itr = split(r), itl = split(l);
    int ret = 0;
    for (auto &it = itl ; it != itr ; it++) {
      if (it->S == 0) continue;
      ret += it->F.S - it->F.F;
    }
    return ret;
  }
  void repair(int l, int r, int rest) {
    int R = l;
    auto itr = split(r), itl = split(l);
    for (auto &it = itl ; it != itr ; it++) {
      if (it->S == 1) continue;
      int curr = min(rest, it->F.S - it->F.F);
      if (rest)
        R = it->F.F + curr;
      rest -= curr;
    }
    if (R - l != 0)
      assign(l, R, 1);
  }
  int qmax(int l, int r) {
    int maxV = 0, sum = 0;
    auto itr = split(r), itl = split(l);
    for (auto &it = itl ; it != itr ; it++) {
      if (it->S == 1) {
        sum = 0;
        continue;
      }
      sum += it->F.S - it->F.F;
      maxV = max(maxV, sum);
    }
    return maxV;
  }
  void print() {
      for (auto &p : odt)
          cout << "[" << p.F.F << ", " << p.F.S << "): " << p.S << endl;
      cout << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  ODTree<int> odt(n, 1);
  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int l, r; cin >> l >> r; l--;
      odt.assign(l, r, 0);
    } else if (op == 1) {
      int l0, r0, l1, r1; cin >> l0 >> r0 >> l1 >> r1;
      l0--, l1--;
      int rest = odt.sum(l0, r0);
      odt.assign(l0, r0, 0);
      odt.repair(l1, r1, rest);
    } else {
      int l, r; cin >> l >> r; l--;
      cout << odt.qmax(l, r) << '\n';
    }
  }
}

