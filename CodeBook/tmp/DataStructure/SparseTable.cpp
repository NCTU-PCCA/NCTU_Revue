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
    int h = __lg(r - l);
    int len = 1 << h;
    return op(data[h][l], data[h][r-len]);
  }
};
