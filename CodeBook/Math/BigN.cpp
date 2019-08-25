#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// LatexBegin
#define O operator
#define CBC (const bigN &b) const
#define CB (const bigN &b)
const int B = 1e9;
const int W = log10(B) + .5;
template <typename T> string to_string(const T &x) {
  stringstream ss; return ss << x, ss.str();
}
struct bigN : vector<LL> { bool neg;
  bigN(string s) {
    if (s.empty()) return; neg = false; LL t;
    if (s[0] == '-') neg = true, s = s.substr(1);
    for (int i = s.size() - 1; i >= (t = 0); i -= W) {
      for (int j = max(0, i - W + 1) ; j <= i ; j++)
        t = t * 10 + s[j] - '0';
      push_back(t);
    } trim();
  }
  template <typename T>
  bigN(const T &x) : bigN(to_string(x)) {}
  bigN() : neg(false) {}
  friend istream& O >> (istream &in, bigN &b) {
    string s; return in >> s, b = s, in;
  }
  friend ostream& O << (ostream &out, const bigN &b) {
    if (b.neg) out << '-'; 
    out << (b.empty() ? 0 : b.back());
    for (int i = b.size() - 2 ; i >= 0 ; i--)
      out << setw(W) << setfill('0') << b[i];
    return out;
  }
  inline void trim() { 
    while (size() && !back()) pop_back();
    if (empty()) neg = false;
  }
  bigN O-() const { bigN ret = *this;
    return ret.neg = !neg, ret.trim(), ret;
  }
  bigN O+CBC { bigN ret = *this;
    if (neg) return -(-ret + (-b));
    if (b.neg) return ret - (-b);
    if (b.size() > size()) ret.resize(b.size());
    for (int i = 0; i < b.size(); i++) ret[i] += b[i];
    return ret.carry(), ret.trim(), ret;
  }
  bigN O-CBC { bigN ret = *this;
    if (neg) return -(-ret - (-b));
    if (b.neg) return ret + (-b);
    if (abscmp(b) < 0) return -(b - ret);
    if (b.size() > size()) ret.resize(b.size());
    for (int i = 0; i < b.size(); i++) ret[i] -= b[i];
    return ret.carry(), ret.trim(), ret;
  }
  inline void carry() {
    for (int i = 0 ; i < size() ; i++) {
      if (at(i) >= 0 && at(i) < B) continue;
      if (i + 1 == size()) push_back(0);
      int r = at(i) % B; if (r < 0) r += B;
      at(i + 1) += (at(i) - r) / B; at(i) = r;
    }
  }
  int abscmp CBC {
    if (size() > b.size()) return 1;
    if (size() < b.size()) return -1;
    for (int i = size() - 1 ; i >= 0 ; i--) {
      if (at(i) > b[i]) return 1;
      if (at(i) < b[i]) return -1;
    }
    return 0;
  }
  bigN O*CBC { bigN ret; ret.neg = neg != b.neg;
    ret.resize(size() + b.size());
    for (int i = 0 ; i < size() ; i++)
      for (int j = 0 ; j < b.size() ; j++)
        if ((ret[i + j] += at(i) * b[j]) >= B)
          ret[i + j + 1] += ret[i + j] / B,
          ret[i + j] %= B;
    return ret.trim(), ret;
  }
  bigN O/CBC { int n = B / (b.back() + 1);
    bigN x = abs() * n, y = b.abs() * n; 
    bigN q, r; q.resize(x.size());
    for (int i = x.size() - 1 ; i >= 0 ; i--) {
      r = r * B + x[i];
      LL s1 = r.size() <= y.size() ? 0 : r[y.size()];
      LL s2 = r.size() < y.size() ? 0 : r[y.size()-1];
      LL d = (LL(B) * s1 + s2) / y.back();
      r = r - y * d; while (r.neg) r = r + y, d--;
      q[i] = d;
    }
    return q.neg = neg != b.neg, q.trim(), q;
  }
  bigN abs() const { bigN ret = *this;
    return ret.neg = false, ret;
  }
  bigN O%CBC { return *this - (*this / b) * b; }
  int cmp CBC { if (neg != b.neg) return neg ? -1 : 1;
    return neg ? -abscmp(b) : abscmp(b);
  }
  bigN& O+=CB { return *this = *this + b, *this; }
  bigN& O-=CB { return *this = *this - b, *this; }
  bigN& O*=CB { return *this = *this * b, *this; }
  bigN& O/=CB { return *this = *this / b, *this; }
  bool O<CBC { return cmp(b) < 0; }
  bool O>CBC { return cmp(b) > 0; }
  bool O<=CBC { return cmp(b) <= 0; }
  bool O>=CBC { return cmp(b) >= 0; }
  bool O==CBC { return cmp(b) == 0; }
  bool O!=CBC { return cmp(b) != 0; }
  template <typename T> O T() {
    stringstream ss; ss << *this;
    T ret; return ss >> ret, ret;
  }
};
// LatexEnd
int main() {
  bigN a, b; 
  while (cin >> a >> b) {
    cout <<  a << ' ' <<  b << '\n';
    cout << -a << ' ' << -b << '\n';
    cout << a.abs() << ' ' << b.abs() << '\n';
    cout << a + b << '\n';
    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a / b << '\n';
    cout << a.abs() % b.abs() << '\n';
    a += b; cout << a << '\n';
    a -= b; cout << a << '\n';
    a *= b; cout << a << '\n';
    a /= b; cout << a << '\n';
    cout << (a <  b) << '\n';
    cout << (a >  b) << '\n';
    cout << (a <= b) << '\n';
    cout << (a >= b) << '\n';
    cout << (a == b) << '\n';
    cout << (a != b) << '\n';
  }
}
