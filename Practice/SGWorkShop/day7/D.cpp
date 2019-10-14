#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
double a, b, c, d, e, f; 
double F(double x) {
    return -x*x*x + (a+b+c) * x*x - (a*b + a*c + b*c - d*d/4 - e*e/4 - f*f/4) * x 
          + (a*b*c - a*d*d/4 - f*f*c/4 + d*e*f/4 - b*e*e/4);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> a >> b >> c >> d >> e >> f) {
        double A = -3;
        double B = 2 * (a + b + c);
        double C = -(a*b + b*c + c*a - d*d/4 - e*e/4 - f*f/4);
        double x1 = (-B + sqrt(B*B - 4*A*C)) / (2*A);
        double x2 = (-B - sqrt(B*B - 4*A*C)) / (2*A);
        double L = x2, R = 1e60;
        for (int i = 0 ; i < 100000 ; i++) {
            double M = (R + L) / 2.0;
            if (F(M) < 0)
                R = M;
            else
                L = M;
        }
        cout << fixed << setprecision(10) << sqrt(1.0 / L) << '\n';
    }
}
