#include <bits/stdc++.h>
using namespace std;
// LatexBegin
template <typename T>
struct Matrix { using vt = vector<T>;
  using mt = vector<vt>; using matrix = Matrix<T>;
  mt m; int r, c;
  Matrix(int r, int c) : r(r), c(c), m(r, vt(c)){}
  vt& operator [](int i) { return m[i]; }
  matrix operator + (const matrix &a) {
    matrix ret(r, c);
    for (int i = 0 ; i < r ; i++)
      for (int j = 0 ; j < c ; j++)
        ret[i][j] = m[i][j] + a.m[i][j];
    return ret;
  }
  matrix operator - (const matrix &a) {
    matrix ret(r, c);
    for (int i = 0 ; i < r ; i++)
      for (int j = 0 ; j < c ; j++)
        ret[i][j] = m[i][j] - a.m[i][j];
    return ret;
  }
  matrix operator * (const matrix &a) {
    matrix ret(r, a.c);
    for (int i = 0 ; i < r ; i++)
      for (int j = 0 ; j < a.c ; j++)
        for (int k = 0 ; k < c ; k++)
          ret.m[i][j] += m[i][k] * a.m[k][j];
    return ret;
  }
  T gas() { T det = 1;
    for (int i = 0 ; i < r ; i++) {
      for (int j = i + 1 ; j < r ; j++) {
        int a = i, b = j; while (m[b][i]) {
          T q = m[a][i] / m[b][i];
          for (int k = 0 ; k < c ; k++)
            m[a][k] -= m[b][k] * q;
          swap(a, b);
        }
        if (a != i) swap(m[i], m[j]), det *= -1;
      }
    }
    for (int i = 0 ; i < r ; i++) det *= m[i][i];
    return det;
  }
};
// LatexEnd
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

}
