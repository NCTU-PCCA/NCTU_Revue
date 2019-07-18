#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void trim(vector<LL> &x) {
    while (x.size() && x.back() == 0)
        x.pop_back();
    if (!x.size())
        x.push_back(0);
}
vector<LL> mul(vector<LL> a, vector<LL> b) {
    vector<LL> res(a.size() + b.size() - 1, 0);
    for (int i = 0 ; i < (int)a.size(); i++)
        for (int j = 0 ; j < (int)b.size() ; j++)
            res[i + j] += a[i] * b[j], res[i + j] %= 2;
    trim(res);
    return res;
}
vector<LL> add(vector<LL> a, vector<LL> b) {
    vector<LL> res(min(a.size(), b.size()), 0);
    for (int i = 0 ; i < (int)res.size() ; i++)
        res[i] = a[i] ^ b[i];
    while (res.size() < a.size())
        res.push_back(a[res.size()]);
    while (res.size() < b.size())
        res.push_back(b[res.size()]);
    trim(res);
    return res;
}
void input(vector<LL> &a, ifstream &in) {
    int v; in >> v; v++;
    if (v == 0)
        a.push_back(0);
    else while (v--) {
        LL x; in >> x;
        a.push_back(x);
    }
    reverse(a.begin(), a.end());
    trim(a);
}
pair<vector<LL>, vector<LL> > div(vector<LL> a, vector<LL> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<LL> q;
    for (int i = 0 ; i + b.size() <= a.size() ; i++) {
        LL c = a[i];
        q.push_back(c);
        for (int j = 0 ; j < (int)b.size() ; j++) {
            a[i + j] ^= b[j] * c;
        }
    }
    reverse(a.begin(), a.end());
    reverse(q.begin(), q.end());
    trim(a);
    trim(q);
    return {q, a};
}
bool isZero(vector<LL> &v) {
    return (v.size() == 1 && v[0] == 0);
}
int main() {
    ifstream in("eq.in");
    ofstream out("eq.out");
    srand(time(NULL));
    vector<LL> a1, a2, b1, b2, c1, c2;
    input(a1, in); input(b1, in); input(c1, in);
    input(a2, in); input(b2, in); input(c2, in);
    vector<LL> f = add(mul(a2, b1), mul(a1, b2));
    vector<LL> b = add(mul(a2, c1), mul(a1, c2));
    if (isZero(f) && !isZero(b)) {
        out << "No solution\n";
    } else if (isZero(f) && isZero(b)) {
        bool ok = false;
        while (1) {
            int len = rand() % 600 + 10;
            vector<LL> y;
            while (len--) y.push_back(rand() % 2);
            trim(y);
            auto res = div(add(c1, mul(b1, y)), a1);
            if (!isZero(res.second)) {
                continue;
            } else {
                reverse(res.first.begin(), res.first.end());
                reverse(y.begin(), y.end());
                if (isZero(res.first)) {
                    out << -1 << '\n';
                } else {
                    out << res.first.size() - 1;
                    for (auto &v : res.first)
                        out << ' ' << v;
                    out << '\n';
                }
                if (isZero(y)) {
                    out << -1 << '\n';
                } else {
                    out << y.size() - 1;
                    for (auto &v : y)
                        out << ' ' << v;
                    out << '\n';
                }
                ok = true;
                break;
            }
        }
        if (!ok)
            out << "No solution\n";
    } else {
        auto res = div(b, f);
        if (!isZero(res.second)) {
            out << "No solution\n";
        } else {
            vector<LL> y = res.first;
            res = div(add(c1, mul(b1, y)), a1);
            if (!isZero(res.second)) {
                out << "No solution\n";
            } else {
                vector<LL> x = res.first;
                reverse(x.begin(), x.end());
                reverse(y.begin(), y.end());
                if (isZero(x)) {
                    out << -1 << '\n'; 
                } else {
                    out << x.size() - 1;
                    for (auto &v : x)
                        out << ' ' << v;
                    out << '\n';
                }
                if (isZero(y)) {
                    out << -1 << '\n';
                } else {
                    out << y.size() - 1;
                    for (auto &v : y)
                        out << ' ' << v;
                    out << '\n';
                }
            }
        }
    }
}
