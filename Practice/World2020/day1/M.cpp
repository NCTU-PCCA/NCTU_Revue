#include <bits/stdc++.h>
#define sq(x) (x) * (x)
using namespace std;
#define double long double
double dis(double x1, double y1, double x2, double y2) {
    return sqrt(sq(x1 - x2) + sq(y1 - y2));
}
const double eps = 1e-8;
void solve(int x1, int y1, int x2, int y2, int x3, int y3, double A, double P) {
    // center (x1, y1)

    double a1 = P / 2;
    double a2 = dis(x1, y1, x2, y2) * dis(x1, y1, x3, y3) / 2;
    if (sq(a1) - 4 * a2 < 0) return ;
    double t1 = a1 / 2;
    double t2 = sqrt(sq(a1) - 4 * a2) / 2;
    double minLe = t1 - t2;
    double maxLe = t1 + t2;
    double minLi = min(dis(x1, y1, x2, y2), dis(x1, y1, x3, y3));
    double maxLi = max(dis(x1, y1, x2, y2), dis(x1, y1, x3, y3));
    if (minLe > minLi + eps || maxLe > maxLi + eps) return ;

    // x2, y2 -> minLe
    if (dis(x1, y1, x2, y2) > dis(x1, y1, x3, y3))
        swap(x2, x3), swap(y2, y3);
    // x3, y3 -> maxLe
    
    double X, Y;
    X = x1 + (x2 - x1) / dis(x1, y1, x2, y2) * minLe;
    Y = y1 + (y2 - y1) / dis(x1, y1, x2, y2) * minLe;
    cout << fixed << setprecision(10) << X << ' ';
    cout << fixed << setprecision(10) << Y << '\n';

    X = x1 + (x3 - x1) / dis(x1, y1, x3, y3) * maxLe;
    Y = y1 + (y3 - y1) / dis(x1, y1, x3, y3) * maxLe;
    cout << fixed << setprecision(10) << X << ' ';
    cout << fixed << setprecision(10) << Y << '\n';
    exit(0);
}
/*
x + y = a1
x * y = a2

t^2 - a1 t + a2 = 0
     a1 +- sqrt(a1 * a1 - 4 a2)
t =  -------------------------
                 2

x + y = P / 2;
x * y * sin(t) = A / 2

0 <= x <= dis(a, b, 0, 0)
0 <= y <= c
*/

int main() {
    // freopen("mashadasha.in","r",stdin);
    // freopen("mashadasha.out","w",stdout);
    double a, b, c; cin >> a >> b >> c;
    double A = c * b / 2.0;
    double P = c + dis(0, 0, a, b) + dis(c, 0, a, b);
    solve(0, 0, a, b, c, 0, A, P);
    solve(a, b, 0, 0, c, 0, A, P);
    solve(c, 0, a, b, 0, 0, A, P);
    cout << "Impossible\n";
}

