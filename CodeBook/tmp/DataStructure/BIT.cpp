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
