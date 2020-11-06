#include <bits/stdc++.h>
using namespace std;
string trans(char c) {
    if (c == '0') return "0000";
    if (c == '1') return "0001";
    if (c == '2') return "0010";
    if (c == '3') return "0011";
    if (c == '4') return "0100";
    if (c == '5') return "0101";
    if (c == '6') return "0110";
    if (c == '7') return "0111";
    if (c == '8') return "1000";
    if (c == '9') return "1001";
    if (c == 'A') return "1010";
    if (c == 'B') return "1011";
    if (c == 'C') return "1100";
    if (c == 'D') return "1101";
    if (c == 'E') return "1110";
    if (c == 'F') return "1111";
}
const int N = 4000;
vector<bitset<N>> read(int n) {
    vector<bitset<N>> a(n);
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        string t;
        for (int j = 0 ; j < s.size() ; j++)
            t += trans(s[j]);
        t.resize(n);
        a[i] = bitset<N>(t);
    }
    return a;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<bitset<N>> a = read(n);
  vector<bitset<N>> b = read(n);
  vector<bitset<N>> c = read(n);
  int t = 100; while (t--) {
      bitset<N> x;
      for (int i = 0 ; i < n ; i++)
          x[i] = rand() % 2;
      bitset<N> y;
      for (int i = 0 ; i < n ; i++)
          y[n - i - 1] = ((b[i] & x).count()) % 2;
      bitset<N> z1;
      for (int i = 0 ; i < n ; i++)
          z1[n - 1 - i] = ((a[i] & y).count()) % 2;

      bitset<N> z2;
      for (int i = 0 ; i < n; i++)
          z2[n - i - 1] = ((c[i] & x).count()) % 2;
    
      if (z1 != z2) {
          cout << "NO\n";
          return 0;
      }
  }
  cout << "YES\n";
}
