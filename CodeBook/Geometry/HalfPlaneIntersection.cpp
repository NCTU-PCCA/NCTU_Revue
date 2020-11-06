#include <bits/stdc++.h>
#include "Basic.cpp"
using namespace std;
// LatexBegin
// availble area for L l is (l.p2-l.p1)^(p-l.p1)>0
bool check(L l1, L l2, L l3) {
  P p = l2.intersect(l3);
  return sign((l1.p2 - l1.p1) % (p - l1.p1)) < 0;
}
vector<P> HPI(vector<L> &ls) {
  sort(ls.begin(), ls.end(), [](L l1, L l2) {
    return sign(l1.o - l2.o) ? l1.o < l2.o :
      sign((l2.p2 - l2.p1) % (l1.p2 - l2.p1)) > 0;
  });
  vector<L> pls{ls[0]}; for (auto &l : ls)
    if (sign(l.o - pls.back().o)) pls.push_back(l);
  deque<int> dq{0, 1};
#define ex(a, b, c) \
  while (dq.size() > 1 && check(pls[a],pls[b],pls[c]))
  for (int i = 2 ; i < pls.size() ; i++) {
    ex(i,dq.back(),dq[dq.size()-2]) dq.pop_back();
    ex(i,dq[0],dq[1]) dq.pop_front();
    dq.push_back(i);
  }
  ex(dq[0],dq.back(),dq[dq.size()-2]) dq.pop_back();
  ex(dq.back(), dq[0], dq[1]) dq.pop_front();
  if (dq.size() < 3) return {};
  dq.push_back(dq[0]); vector<P> ret;
  for (int i = 1 ; i < dq.size() ; i++)
    ret.push_back(pls[dq[i-1]].intersect(pls[dq[i]]));
  return ret;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<P> ps(n);
  for (auto &p : ps)
    cin >> p.x >> p.y;
  vector<L> ls;
  ls.push_back(L(P(1e6, 1e6), P(0, 1e6)));
  ls.push_back(L(P(0, 1e6), P(0, 0)));
  ls.push_back(L(P(0, 0), P(1e6, 0)));
  ls.push_back(L(P(1e6, 0), P(1e6, 1e6)));
  for (int i = 1 ; i < n ; i++)
    ls.push_back(L(ps[i - 1], ps[i]));
  vector<P> ans = HPI(ls);
  T minV = 1e8;
  for (auto &p : ans)
      minV = min(minV, p.y);
  cout << fixed << setprecision(10) << minV << '\n';
}
