#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60 + 5;
const int BASE  = 1e9 + 0.5;
const int WIDTH = log10(BASE) + 0.5;
template <typename T>
inline string to_string(const T &x) {
    stringstream ss;
    return ss << x, ss.str();
}
typedef long long LL;
struct bigN : vector<LL> {
    bool neg;
    bigN(string s) {
        if (s.empty()) return ;
        if (s[0] == '-') neg = true, s = s.substr(1);
        else neg = false;
        for (int i = s.size() - 1 ; i >= 0 ; i -= WIDTH) {
            LL t = 0;
            for (int j = max(0, i - WIDTH + 1) ; j <= i ; j++)
                t = t * 10 + s[j] - '0';
            push_back(t);
        }
        trim();
    }
    template <typename T>
    bigN(const T &x) : bigN(to_string(x)) {}
    bigN() : neg(false) {}
    friend istream& operator >> (istream &in, bigN &b) {
        string s;
        return in >> s, b = s, in;
    }
    friend ostream& operator << (ostream &out, const bigN &b) {
        if (b.neg) out << '-';
        out << (b.empty() ? 0 : b.back());
        for (int i = b.size() - 2 ; i >= 0 ; i--)
            out << setw(WIDTH) << setfill('0') << b[i];
        return out;
    }
    inline void trim() {
        while (size() && !back()) pop_back();
        if (empty()) neg = false;
    }
    bigN operator - () const {
        bigN res = *this;
        return res.neg = !neg, res.trim(), res;
    }
    bigN operator + (const bigN &b) const {
        if (neg) return -(-(*this) + (-b));
        if (b.neg) return *this - (-b);
        bigN res = *this;
        if (b.size() > size()) res.resize(b.size());
        for (int i = 0 ; i < b.size() ; i++) res[i] += b[i];
        return res.carry(), res.trim(), res;
    }
    bigN operator - (const bigN &b) const {
        if (neg) return -(-(*this) - (-b));
        if (b.neg) return *this + (-b);
        if (abscmp(b) < 0) return -(b-(*this));
        bigN res = *this;
        if (b.size() > size()) res.resize(b.size());
        for (int i = 0 ; i < b.size() ; i++) res[i] -= b[i];
        return res.carry(), res.trim(), res;
    }
    inline void carry() {
        for (int i = 0 ; i < size() ; i++) {
            if (at(i) >= 0 && at(i) < BASE) continue;
            if (i + 1 == size()) push_back(0);
            int r = at(i) % BASE;
            if (r < 0) r += BASE;
            at(i + 1) += (at(i) - r) / BASE;
            at(i) = r;
        }
    }
    int abscmp(const bigN &b) const {
        if (size() > b.size()) return 1;
        if (size() < b.size()) return -1;
        for (int i = size() - 1 ; i >= 0 ; i--) {
            if (at(i) > b[i]) return 1;
            if (at(i) < b[i]) return -1;
        }
        return 0;
    }
    bigN operator * (const bigN &b) const {
        bigN res;
        res.neg = neg != b.neg;
        res.resize(size() + b.size());
        for (int i = 0 ; i < size() ; i++)
            for (int j = 0 ; j < b.size() ; j++)
                if ((res[i + j] += at(i) * b[j]) >= BASE) {
                    res[i + j + 1] += res[i + j] / BASE;
                    res[i + j] %= BASE;
                }
        return res.trim(), res;
    }
    bigN operator / (const bigN &b) const {
        int norm = BASE / (b.back() + 1);
        bigN x = abs() * norm;
        bigN y = b.abs() * norm;
        bigN q, r;
        q.resize(x.size());
        for (int i = x.size() - 1 ; i >= 0 ; i--) {
            r = r * BASE + x[i];
            int s1 = r.size() <= y.size() ? 0 : r[y.size()];
            int s2 = r.size() <  y.size() ? 0 : r[y.size() - 1];
            int d = (LL(BASE) * s1 + s2) / y.back();
            r = r - y * d;
            while (r.neg) r = r + y, d--;
            q[i] = d;
        }
        q.neg = neg != b.neg;
        return q.trim(), q;
    }
    bigN abs() const {
        bigN res = *this;
        return res.neg = false, res;
    }
    bigN operator % (const bigN &b) const {
        return *this - (*this / b) * b;
    }
    int cmp(const bigN &b) const {
        if (neg != b.neg) return neg ? -1 : 1;
        return neg ? -abscmp(b) : abscmp(b);
    }
    bool operator < (const bigN &b) const { return cmp(b) < 0; }
    bool operator > (const bigN &b) const { return cmp(b) > 0; }
    bool operator <= (const bigN &b) const { return cmp(b) <= 0; }
    bool operator >= (const bigN &b) const { return cmp(b) >= 0; }
    bool operator == (const bigN &b) const { return cmp(b) == 0; }
    bool operator != (const bigN &b) const { return cmp(b) != 0; }
    template <typename T>
    operator T() {
        stringstream ss;
        ss << *this;
        T res;
        return ss >> res, res;
    }
};
const int MAXL = 60 + 5;
bigN dp[26][MAXL][2];
bigN c[MAXL][MAXL];
bigN C(int n, int m) {
    if (c[n][m] != -1)
        return c[n][m];
    if (n == m || m == 0)
        return c[n][m] = 1;
    return c[n][m] = C(n - 1, m - 1) + C(n - 1, m);
}
bigN gcd(bigN a, bigN b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
const bigN INF = "99999999999999999999999999999999999999999999999999999999999999999999999999";
int cnt[26];
int main() {
    ifstream in("lottery.in");
    ofstream out("lottery.out");
    int n; in >> n;
    string s; in >> s;
    for (int i = 0 ; i < MAXL ; i++)
        for (int j = 0 ; j < MAXL ; j++)
            c[i][j] = -1;
    memset(cnt, 0, sizeof(cnt));
    for (auto &v : s)
        cnt[v - 'A']++;
    for (int i = 0 ; i < 26 ; i++)
        for (int j = 0 ; j < MAXL ; j++)
            dp[i][j][1] = INF;
    for (int j = cnt[0] ; j <= n ; j++)
        dp[0][j][0] = dp[0][j][1] = C(j, cnt[0]);
    for (int i = 1 ; i < 26 ; i++) {
        for (int j = cnt[i] ; j <= n ; j++) {
            bigN maxV = 0;
            for (int k = cnt[i] ; k <= j ; k++) {
                if (maxV < dp[i - 1][j - k][0] * C(k, cnt[i]))
                    maxV = dp[i - 1][j - k][0] * C(k, cnt[i]);
            }
            dp[i][j][0] = maxV;
        }
    }
    bigN g = gcd(dp[25][n][0], C(n, s.size()));
    out << dp[25][n][0] / g << '/' << C(n, s.size()) / g << '\n';
    int minV = 100, minIdx = -1;
    for (int i = 0 ; i < 26 ; i++) {
        if (!cnt[i])
            continue;
        if (minV > cnt[i])
            minV = cnt[i], minIdx = i;
    }
    int need = n - s.size();
    bigN sum = 1;
    for (int i = 0 ; i < 26 ; i++) {
        if (i == minIdx)
            sum = sum * C(cnt[i] + need, cnt[i]);
    }
    g = gcd(sum, C(n, s.size()));
    out << sum / g << '/' << C(n, s.size()) / g << '\n';

}
