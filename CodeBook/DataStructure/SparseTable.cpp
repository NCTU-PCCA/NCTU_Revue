#include <bits/stdc++.h>
using namespace std;
// LatexBegin
struct SparseTable{
  vector<vector<int> > data;
  int (*op)(int a, int b);
  SparseTable(vector<int> &arr, int (*_op)(int a, int b)) {
    op = _op;
    int n = (int)arr.size(), lgN = __lg(n) + 1;
    data.resize(lgN);
    for (int i = 0 ; i < n ; i++)
      data[0].push_back(arr[i]);
    for (int h = 1 ; h < lgN ; h++){
      int len = 1 << (h - 1), i = 0;
      for (; i + len < n ; i++)
        data[h].push_back(op(data[h-1][i], data[h-1][i+len]));
      if (!i) break;
      for (; i < n ; i++)
        data[h].push_back(data[h-1][i]);
    }
  }
  int query(int l, int r){
    int h = __lg(r - l), len = 1 << h;
    return op(data[h][l], data[h][r-len]);
  }
};
// LatexEnd
int getMin(int a, int b) {
  return min(a, b);
}
int getMax(int a, int b) {
  return max(a, b);
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int> arr(n);
  for (auto &v : arr)
    cin >> v;
  SparseTable *minV = new SparseTable(arr, getMin);
  SparseTable *maxV = new SparseTable(arr, getMax);
  while (q--) {
    int l, r; cin >> l >> r; l--;
    cout << maxV->query(l, r) - minV->query(l, r) << endl;
  }
  delete minV;
  delete maxV;
}
