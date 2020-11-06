#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double EPS = 1e-10;
void check1(auto &c, double T, double F) {
    int n = c.size();
    double rest = 0;
    double x;
    for (int i = 0 ; i < n ; i++) {
        double curr = rest + T * F;
        rest = max(0.0, curr - c[i]);
        x = abs(curr - rest - c[i]);
    }
    assert(x < EPS);
}
void check2(auto &c, double T, double F) {
    int n = c.size();
    double rest = 0;
    for (int i = 0 ; i < n ; i++) {
        double curr = rest + T * F;
        rest = max(0.0, curr - c[i]);
        cout << abs(curr - rest - c[i]) << endl;
        assert(abs(curr - rest - c[i]) > EPS);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; double f;
    while (cin >> n >> f) {
        vector<double> c(n);
        for (auto &v : c)
            cin >> v;

        double L = 0, R = 1e11;
        for (int i = 0 ; i < 100 ; i++) {
            double rest = 0;
            double M = (L + R) / 2.0;
            bool ok = false;
            for (int i = 0 ; i < n ; i++) {
                double curr = rest + M * f;
                rest = max(0.0, curr - c[i]);
                if (abs(curr - rest - c[i]) <= EPS)
                    ok = true;
                else
                    ok = false;
            }
            if (!ok)
                L = M;
            else
                R = M;
            
        }
        cout << fixed << setprecision(10) << L << ' ';
        check1(c, R, f);

        L = 0, R = 1e11;
        for (int i = 0 ; i < 100 ; i++) {
            double rest = 0;
            double M = (L + R) / 2.0;
            bool ok = true;
            for (int i = 0 ; i < n ; i++) {
                double curr = rest + M * f;
                rest = max(0.0, curr - c[i]);
                if (abs(curr - rest - c[i]) >= EPS)
                    ok = false;
            }
            if (!ok)
                L = M;
            else
                R = M;
        }
        cout << fixed << setprecision(10) << L << '\n';
        check2(c, R, f);
    }
}
