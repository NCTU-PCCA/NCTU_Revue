#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
struct T {
    int s; LL q, p;
    map<char, int> mp;
};
struct F {
    char c, l, r;
};
vector<T> trim(auto &ans) {
    vector<T> ret;
    for (auto &t : ans) {
        if (t.q == 0)
            continue;
        ret.push_back(t);
    }
    if (ret.size() == 0) {
        ret.push_back({1, 0, 1, {}});
    }
    return ret;
}
vector<T> trans(auto &ans, char f, char c) {
    if (c == '0')
        return {T{1, 0, 1, {}}};
    if (c == '1') {
        vector<T> ret = ans;
        for (auto &t : ret)
            t.mp.erase(f);
        return ret;
    }
    vector<T> ret = ans;
    for (auto &t : ret) {
        t.mp[c] += t.mp[f];
        t.mp.erase(f);
    }
    return trim(ret);
}
pair<LL, LL> add(pair<LL, LL> a, pair<LL, LL> b) {
    LL l = a.S * b.S;
    pair<LL, LL> ret = {a.F * b.S + a.S * b.F, a.S * b.S};
    LL g = __gcd(abs(ret.F), abs(ret.S));
    ret.F /= g, ret.S /= g;
    return ret;
}
int main() {
    ifstream in("fygon20.in");
    ofstream out("fygon20.out");
    int n; in >> n;
    vector<F> fors;
    for (int i = 0 ; i < n - 1 ; i++) {
        string tmp; in >> tmp >> tmp;
        char c = tmp[0];
        in >> tmp >> tmp;
        char l = tmp[6];
        if (l == '1')
            l = '0';
        in >> tmp;
        char r = tmp[0];
        if (r == 'n')
            r = '1';
        fors.push_back(F{c, l, r});
    }
    string s; in >> s;
    vector<T> ans{T{1, 1, 1, {}}};
    while (fors.size()) {
        F f = fors.back(); fors.pop_back();
        for (auto &t : ans) {
            t.mp[f.c]++;
            t.p *= t.mp[f.c];
        }
        vector<T> L = trans(ans, f.c, f.l);
        vector<T> R = trans(ans, f.c, f.r);
        for (auto &t : R) {
            t.s *= -1;
            L.push_back(t);
        }
        ans = trim(L);
    }
    pair<LL, LL> sum = {0, 1};
    for (auto &t : ans) {
        pair<LL, LL> cur = {t.s * t.q, t.p};
        sum = add(sum, cur);
    }
    out << n - 1 << ' ' << abs(sum.F) << '/' << abs(sum.S) << '\n';
}
