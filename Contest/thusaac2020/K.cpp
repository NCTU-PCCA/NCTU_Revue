#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL MOD = 998244353;
struct SegmentTree {
  #define lson L, R, N[u].l
  #define rson L, R, N[u].r
  #define OUT R <= N[u].L || N[u].R <= L
  #define IN  L <= N[u].L && N[u].R <= R
  struct Node {
      int L, R, l, r; LL sum, add;
  };
  vector<Node> N; int p; vector<int> rt; int n;
  inline void init(int _n) { n = _n; N.resize(n * 8); p = 1;
    rt.clear(); rt.push_back(build(0, n));
  }
  inline int copy(Node u) { return N[p] = u, p++; }
  int build(int L, int R) {
    int u = copy({L, R}), M = (L + R) >> 1;;
    if (R - L == 1) return u;
    return pull(u, build(L, M), build(M, R));
  }
  inline int push(int u) {
    if (N[u].add) {
      N[u].sum += N[u].add * (N[u].R - N[u].L);
      if (N[u].l)
          N[N[u].l].add += N[u].add;
      if (N[u].r)
          N[N[u].r].add += N[u].add;
      N[u].add = 0;
    }
    return u;
  }
  inline int pull(int u, int l, int r) {
    if (!l || !r) return l ? l : r;
    push(N[u].l = l); push(N[u].r = r);
    N[u].sum = N[l].sum + N[r].sum;
    return u;
  }
  int m(int L, int R, int u, LL v) {
    if (!u || OUT) return u; push(u);
    if (IN) return N[u].add += v, u;
    return pull(u, m(lson, v), m(rson, v));
  }
  int q(int L, int R, int u) {
    if (!u || OUT) return 0; push(u); 
    if (IN) return u;
    return pull(copy(N[push(u)]), q(lson), q(rson));
  }
  inline void modify(int L, int R, int ver, LL v) {
    rt[ver] = m(L, R, rt[ver], v);
  }
  inline Node& query(int L, int R, int ver) {
    p = n * 4 + 1;
    return N[q(L, R, rt[ver])];
  }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<LL> pow2(n + 1, 1);
    for (int i = 1 ; i < n + 1 ; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }
    map<int, int> mp;
    vector<pii> seg(n);
    for (auto &p : seg) {
        cin >> p.F >> p.S; p.S++;
        mp[p.F]; mp[p.S];
    }
    vector<int> arr(q);
    for (auto &v : arr) {
        cin >> v; mp[v];
    }
    int st = 0;
    for (auto &p : mp)
        p.S = st++;
    SegmentTree seg1; seg1.init(st);
    for (auto &p : seg) {
        p.F = mp[p.F];
        p.S = mp[p.S];
        seg1.modify(p.F, p.S, 0, 1);
    }
    for (auto &v : arr)
        v = mp[v];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    q = arr.size();
    vector<LL> oneSeg;
    for (auto &v : arr) {
        oneSeg.push_back(seg1.query(v, v + 1, 0).sum);
    }
    
    seg1.init(st);
    vector<vector<int>> N(st);
    for (auto &p : seg) {
        N[p.S].push_back(p.F);
        seg1.modify(p.F, p.F + 1, 0, 1);
        //cout << "add " << p.F << '\n';
    }
    int ptr = 0;
    vector<LL> twoSeg;
    for (int i = 1 ; i < q ; i++) {
        while (ptr <= arr[i]) {
            for (auto &v : N[ptr]) {
                seg1.modify(v, v + 1, 0, -1);
                //cout << "modify " << v << ' ' << -1 << '\n';
            }
            ptr++;
        }
        twoSeg.push_back(seg1.query(0, arr[i - 1] + 1, 0).sum);
        //cout << "query " << 0 << ' ' << arr[i - 1] + 1 << ' ' << twoSeg.back() << '\n';
    }
    /*
    for (int i = 0 ; i < q ; i++) {
        cout << oneSeg[i] << ' ';
    }
    cout << '\n';

    for (int i = 0 ; i < q - 1 ; i++) {
        cout << twoSeg[i] << ' ';
    }
    cout << '\n';
    */

    LL ans = 0;
    for (int i = 0 ; i < q ; i++) {
        ans += pow2[oneSeg[i]] - 1 + MOD;
        ans %= MOD;
    }
    for (int i = 0 ; i < q - 1 ; i++) {
        ans -= pow2[twoSeg[i]] - 1 - MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
