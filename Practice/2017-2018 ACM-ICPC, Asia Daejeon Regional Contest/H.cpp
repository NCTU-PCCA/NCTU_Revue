#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int fpow(int a, int n, int P) {
    int r = 1; while (n) {
        if (n & 1)
            r = 1ll * r * a % P;
        a = 1ll * a * a % P; n >>= 1;
    }
    return r;
}
const int P = 998244353, R = 3, MAXN = (1 << 23);
struct Poly : vector<int> { int n;
    Poly (int n) : n(n) { this->resize(n); }
    int extend(int x) {
        int N = 1; while (N < x) N <<= 1; return N;
    }
    Poly operator * (const Poly &rhs) {
        Poly a = *this, b = rhs;
        int N = extend(n + rhs.n - 1);
        a.resize(a.n = N); a.ntt(1);
        b.resize(b.n = N); b.ntt(1);
        for (int i = 0 ; i < N ; i++)
            a[i] = 1ll * a[i] * b[i] % P;
        return a.ntt(-1), a.n = n + rhs.n - 1, a;
    }
    void ntt(int op) { static Poly r(MAXN);
        for (int i = 0 ; i < n ; i++) {
            r[i] = (i & 1) * (n >> 1) + (r[i >> 1] >> 1);
            if (r[i] < i) std::swap(at(i), at(r[i]));
        }
        for (int m = 2 ; m <= n ; m <<= 1) {
            int k = m >> 1, gn = fpow(R, (P - 1) / m, P);
            for (int i = 0 ; i < n ; i += m) { int g = 1;
                for (int j = 0 ; j < k ; j++, g = 1ll * g * gn % P) {
                    int tmp = 1ll * at(i + j + k) * g % P;
                    at(i + j + k) = (at(i + j) - tmp + P) % P;
                    at(i + j) = (at(i + j) + tmp) % P;
                }
            }
        }
        if (op == -1) {
            reverse(begin() + 1, end());
            int inv = fpow(n, P - 2, P);
            for (int i = 0 ; i < n ; i++)
                at(i) = 1ll * at(i) * inv % P;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    
    string S = "PSR";
    string T = "SRP";
    vector<Poly> arr;
    for (int x = 0 ; x < 3 ; x++) {
        Poly _s(s.size()), _t(t.size());
        for (int i = 0 ; i < s.size() ; i++)
            _s[i] = (s[i] == S[x]);
        for (int i = 0 ; i < t.size() ; i++)
            _t[i] = (t[i] == T[x]);
        Poly ans = _s * _t;
        arr.push_back(ans);
    }
    int ans = 0;
    for (int i = m - 1 ; i < arr[0].n ; i++) {
        ans = max(ans, arr[0][i] + arr[1][i] + arr[2][i]);
    }
    cout << ans << '\n';
}
