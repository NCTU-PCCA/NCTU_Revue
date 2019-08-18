#include <bits/stdc++.h>
using namespace std;
// LatexBegin
#define O ostream
O& operator << (O &out, __int128_t v) {
  O::sentry s(out);
  if (s) { __uint128_t uv = v < 0 ? -v : v;
    char buf[128], *d = end(buf);
    do { *(--d) = uv % 10 + '0'; uv /= 10; 
    } while (uv != 0);
    if (uv < 0) *(--d) = '-'; int len = end(buf) - d;
    if (out.rdbuf()->sputn(d, len) != len)
      out.setstate(ios_base::badbit);
  }
  return out;
}
#define I istream
I& operator >> (I &in, __int128_t &v) {
  string s; in >> s; v = 0;
  for (int i = 0 ; i < (int)s.size() ; i++)
    if ('0' <= s[i] && s[i] <= '9')
      v = 10 * v + s[i] - '0';
  return in;
}
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  __int128_t x, y; cin >> x >> y;
  cout << x + y << '\n';
}
