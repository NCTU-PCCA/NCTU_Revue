// LatexBegin
struct Key {
  int F, S;
  Key() {}
  Key(int _x, int _y) : F(_x), S(_y) {}
  bool operator == (const Key &b) const {
    return tie(F, S) == tie(b.F, b.S);
  }
};
struct KeyHasher {
  size_t operator() (const Key &b) const {
    return k.F + k.S * 100000;
  }
};
typedef unordered_map<Key, int, KeyHasher> map_t;
// LatexEnd
