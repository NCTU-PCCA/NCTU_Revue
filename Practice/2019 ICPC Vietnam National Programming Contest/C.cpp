#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool in(vector<LL> &p, vector<LL> &c) {
    if (c[0] > p[0] || c[3] < p[0]) return false;
    if (c[1] > p[1] || c[4] < p[1]) return false;
    if (c[2] > p[2] || c[5] < p[2]) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL a, b, c; int n; while (cin >> a) {
        if (a == -1)
            break;
        cin >> b >> c >> n;
        vector<vector<LL> > P(n);
        for (auto &p : P) {
            p.resize(3);
            for (auto &v : p)
                cin >> v;
        }
        vector<vector<LL> > C(n);
        for (auto &_c : C) {
            _c.resize(6);
            for (auto &v : _c)
                cin >> v;
        }
        bool ok = true;
        for (int i = 0 ; i < n ; i++) {
            if (0 > C[i][0] || a < C[i][0])
                ok = false;
            if (0 > C[i][1] || b < C[i][1])
                ok = false;
            if (0 > C[i][2] || c < C[i][2])
                ok = false;
            if (0 > C[i][3] || a < C[i][3])
                ok = false;
            if (0 > C[i][4] || b < C[i][4])
                ok = false;
            if (0 > C[i][5] || c < C[i][5])
                ok = false;
            if (C[i][0] > C[i][3])
                ok = false;
            if (C[i][1] > C[i][4])
                ok = false;
            if (C[i][2] > C[i][5])
                ok = false;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0 ; i < n ; i++) {
            if (!in(P[i], C[i]))
                ok = false;
            if (!ok) break;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                vector<LL> input(3);
                input[0] = C[i][0];
                input[1] = C[i][1];
                input[2] = C[i][2];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0];
                input[1] = C[i][1];
                input[2] = C[i][2 + 3];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0];
                input[1] = C[i][1 + 3];
                input[2] = C[i][2];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0];
                input[1] = C[i][1 + 3];
                input[2] = C[i][2 + 3];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0 + 3];
                input[1] = C[i][1];
                input[2] = C[i][2];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0 + 3];
                input[1] = C[i][1];
                input[2] = C[i][2 + 3];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0 + 3];
                input[1] = C[i][1 + 3];
                input[2] = C[i][2];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
                input[0] = C[i][0 + 3];
                input[1] = C[i][1 + 3];
                input[2] = C[i][2 + 3];
                if (in(input, C[j]))
                    ok = false;
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        LL sum = 0;
        for (int i = 0 ; i < n ; i++)
            sum += (C[i][3] - C[i][0] + 1) * (C[i][4] - C[i][1] + 1) * (C[i][5] - C[i][2] + 1);
        if (sum != a * b * c)
            ok = false;
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
