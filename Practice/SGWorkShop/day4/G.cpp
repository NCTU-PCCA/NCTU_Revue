#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> pii;
using T = LL;
const LL MOD = 1000000000;
struct M : vector<vector<LL> > {
    int r, c;
    M(int r, int c) : r(r), c(c) {
        clear(); resize(r, vector<LL>(c, 0));
    }
    M operator * (const M &m) const {
        M ret(r, m.c);
        for (int i = 0 ; i < ret.r ; i++)
            for (int j = 0 ; j < ret.c ; j++)
                for (int k = 0 ; k < c ; k++)
                    ret[i][j] += at(i)[k] * m[k][j], ret[i][j] %= MOD;
        return ret;
    }
};
int getId(int a, int b) {
    return (29 - a) * a / 2 + b;
}
pii getPos(int x) {
    int a = 0, b = 0;
    while (getId(a + 1, b) <= x)
        a++;
    b = x - getId(a, b);
    return {a, b};
}
LL c[15][15];
LL C(int n, int m) {
    if (~c[n][m]) return c[n][m];
    if (n == m || m == 0) return c[n][m] = 1;
    return c[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % MOD;
}
M fpow(M &A, M &I, LL n) {
    if (n == 0) return I;
    M k = fpow(A, I, n >> 1);
    if (n % 2) return k * k * A;
    else return k * k;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(c, -1, sizeof(c));
    LL n; int k; cin >> n >> k;
    M A(106, 106);
    for (int i = 0 ; i < 105 ; i++) {
        int k = getPos(i).F, x = getPos(i).S;
        for (int a = 0 ; a <= k ; a++)
            for (int b = 0 ; b <= k - a ; b++)
                A[i][getId(a + x, b)] = C(k, a) * C(k - a, b) % MOD;
    }
    A[105][105] = A[105][getId(k, 0)] = 1;
    M B(106, 1), I(106, 106);
    for (int i = 0 ; i < 106 ; i++)
        B[i][0] = I[i][i] = 1;
    cout << setw(9) << setfill('0') << (fpow(A, I, n) * B)[105][0] << '\n';
}
