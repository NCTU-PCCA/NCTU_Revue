#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
struct Mo {
  struct Q { int qT, id, l, r, b; LL v;
    bool operator < (const Q &q) const {
      return b == q.b ? r < q.r : l < q.l;
    }
  };
  vector<Q> qs; vector<LL> ans, data;
  Mo (vector<LL> &data, int q) : data(data) {
    ans.assign(q, 0);
  }
// LatexEnd
  unordered_map<int, LL> cnt; LL cur;
// LatexBegin
  void run() { int sqqs = sqrt(data.size());
    for (auto &q : qs) q.b = q.l / sqqs;
    sort(qs.begin(), qs.end());
// LatexEnd
    cur = 0;
// LatexBegin
    int l = 0, r = 0; for (auto &q : qs) {
      while (r < q.r) update(data[r++], 1);
      while (r > q.r) update(data[--r], -1);
      while (l > q.l) update(data[--l], 1);
      while (l < q.l) update(data[l++], -1);
// LatexEnd
/*
// LatexBegin
      ans[q.id] += solve();
// LatexEnd
*/
      ans[q.id] += q.v * solve();
// LatexBegin
    }
  }
  void addQ(int qT, int id, int l, int r, LL v) {
    qs.push_back({qT, id, l, r, 0, v});
  }
// LatexEnd
/*
// LatexBegin
  void update(LL v, int T) { }
  LL solve() { }
// LatexEnd
*/
  void update(LL v, int T) {
    cur -= cnt[v] * (cnt[v] - 1) / 2;
    if (T == 1)
      cnt[v]++;
    else
      cnt[v]--;
    cur += cnt[v] * (cnt[v] - 1) / 2;
  }
  LL solve() { return cur; }
// LatexBegin
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n; vector<LL> data(n);
  for (auto &v : data) cin >> v;
  int q; cin >> q; 
  Mo *mo = new Mo(data, q);
  for (int i = 0 ; i < q ; i++) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    l1--, l2--;
    mo->addQ(0, i, l1, l2, -1);
    mo->addQ(0, i, r1, r2, -1);
    mo->addQ(0, i, l1, r2, 1);
    mo->addQ(0, i, r1, l2, 1);
  }
  mo->run();
  for (auto &v : mo->ans)
    cout << v << '\n';
  delete mo;
}
