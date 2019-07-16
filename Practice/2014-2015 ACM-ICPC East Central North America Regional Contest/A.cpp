#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
pii trim(pii p) {
    LL g = __gcd(abs(p.F), abs(p.S));
    if (p.S < 0)
        p.F *= -1, p.S *= -1;
    else if (p.F == 0)
        p.S = abs(p.S);
    return {p.F / g, p.S / g};
}
pii add(pii a, pii b) {
    pii res = {a.F * b.S + a.S * b.F, a.S * b.S};
    return trim(res);
}
pii sub(pii a, pii b) {
    pii res = {a.F * b.S - a.S * b.F, a.S * b.S};
    return trim(res);
}
pii mul(pii a, pii b) {
    return trim({a.F * b.F, a.S * b.S});
}
pii div(pii a, pii b) {
    return trim({a.F * b.S, a.S * b.F});
}
vector<LL> trans(pii p) {
    if (p.S == 1) 
        return {p.F};
    else if (p.F < 0) {
        vector<LL> res;
        res.push_back(p.F / p.S - 1);
        p.S = abs(p.S);
        p.F = abs(p.F);
        p.F %= p.S;
        p = sub({1, 1}, p);
        if (p.F == 1) {
            res.push_back(p.S);
            return res;
        }
        swap(p.F, p.S); p = trim(p);
        while (1) {
            res.push_back(p.F / p.S);
            p.F %= p.S;
            if (p.F == 1) {
                res.push_back(p.S);
                return res;
            }
            swap(p.F, p.S); p = trim(p);
        }
        return res;
    } else {
        vector<LL> res;
        while (1) {
            res.push_back(p.F / p.S);
            p.F %= p.S;
            if (p.F == 1) {
                res.push_back(p.S);
                return res;
            }
            swap(p.F, p.S); p = trim(p);
        }
        return res;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, kase = 0; while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        cout << "Case " << ++kase << ":\n";
        vector<LL> r1_data(n); pii r1 = {1, 0};
        vector<LL> r2_data(m); pii r2 = {1, 0};
        for (auto &v : r1_data) cin >> v;
        for (auto &v : r2_data) cin >> v;
        reverse(r1_data.begin(), r1_data.end());
        reverse(r2_data.begin(), r2_data.end());
        for (auto &v : r1_data) {
            swap(r1.F, r1.S);
            r1 = add(r1, {v, 1});
        }
        for (auto &v : r2_data) {
            swap(r2.F, r2.S);
            r2 = add(r2, {v, 1});
        }
        vector<LL> res;
        res = trans(add(r1, r2));
        for (int i = 0 ; i < (int)res.size() ; i++)
            cout << res[i] << " \n"[i + 1 == (int)res.size()];
        res = trans(sub(r1, r2));
        for (int i = 0 ; i < (int)res.size() ; i++)
            cout << res[i] << " \n"[i + 1 == (int)res.size()];
        res = trans(mul(r1, r2));
        for (int i = 0 ; i < (int)res.size() ; i++)
            cout << res[i] << " \n"[i + 1 == (int)res.size()];
        res = trans(div(r1, r2));
        for (int i = 0 ; i < (int)res.size() ; i++)
            cout << res[i] << " \n"[i + 1 == (int)res.size()];
    }
}
