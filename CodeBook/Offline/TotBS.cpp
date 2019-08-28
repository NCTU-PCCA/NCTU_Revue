#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct BIT {
  vector<LL> d; int n;
  BIT(int n) : n(n) { d.assign(n + 1, 0); }
  void _(int &x, int v) { x += v * (x & -x); }
  LL Q(int x) { LL ret = 0;
    while (x > 0) ret += d[x], _(x, -1);
    return ret;
  }
  void M(int x, LL v) { x++;
    while (x <= n) d[x] += v, _(x, 1);
  }
};
// LatexBegin
struct TotBS {
  struct Q { int qT, id, l, r; LL v, cal, buf; };
  vector<Q> qs; vector<LL> data, ans;
  TotBS(int n) { data.assign(n, 0); qs.clear(); }
  BIT *bit;
  void addQ(int qT, int id, int l, int r, LL v) {
    qs.push_back({qT, id, l, r, v, 0});
  }
  void run(int q) {  ans.assign(q, 0); 
    bit = new BIT(data.size()); 
    solve(0, qs.size(), 0, INF); delete bit;
  }
  void solve(int qL, int qR, LL L, LL R) {
    if (qL == qR || R - L == 1) {
      for (int i = qL ; i < qR ; i++)
        if (~qs[i].id) ans[qs[i].id] = R;
      return ;
    }
    LL M = (R + L) >> 1;
    go(qL, qR, M,  1); go(qL, qR, M, -1);
    int lsz = split(qL, qR, M);
    solve(qL, qL + lsz, L, M); 
    solve(qL + lsz, qR, M, R);
  }
  void go(int qL, int qR, LL M, int t) {
    for (int i = qL ; i < qR ; i++) {
      if (!~qs[i].id && qs[i].v <= M)
        bit->M(qs[i].l, qs[i].qT * t);
      else if (~qs[i].id && ~t)
        qs[i].buf = bit->Q(qs[i].r) - bit->Q(qs[i].l);
    }
  }
  int split(int qL, int qR, LL M) { vector<Q> L, R;
    for (int i = qL ; i < qR ; i++) {
      if (!~qs[i].id)
        (qs[i].v <= M ? L : R).push_back(qs[i]);
      else {
        if (qs[i].cal + qs[i].buf >= qs[i].v)
          L.push_back(qs[i]);
        else
          qs[i].cal += qs[i].buf, R.push_back(qs[i]);
      }
    }
    for (int i = 0 ; i < L.size() ; i++) 
      qs[qL + i] = L[i];
    for (int i = 0 ; i < R.size() ; i++)
      qs[qL + L.size() + i] = R[i];
    return L.size();
  }
};
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  TotBS *sol = new TotBS(n);
  vector<LL> data(n); for (int i = 0 ; i < n ; i++) {
    cin >> data[i];
    sol->addQ(1, -1, i, -1, data[i]);
  }
  int qid = 0; while (q--) {
    string op; cin >> op;
    if (op[0] == 'Q') {
      int l, r; LL k; cin >> l >> r >> k; l--;
      sol->addQ(0, qid++, l, r, k);
    } else {
      int x; LL v; cin >> x >> v; x--;
      sol->addQ(-1, -1, x, -1, data[x]);
      sol->addQ( 1, -1, x, -1, v);
      data[x] = v;
    }
  }
  sol->run(qid);
  for (auto &v : sol->ans)
    cout << v << '\n';
}
// LatexEnd
