#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Point {
    LL x, y;
    Point(){}
    Point(LL x, LL y):x(x), y(y) {}
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (LL c) { return Point(x * c, y * c); }
    Point operator / (LL c) { return Point(x / c, y / c); }
    LL operator * (Point p) { return x * p.x + y * p.y; }
    LL operator % (Point p) { return x * p.y - y * p.x; }
    LL dist2(Point p) { return (*this - p) * (*this - p); }
};
bool between(LL a, LL b, LL x) {
    if (a > b) swap(a, b);
    return a <= x && x <= b;
}
bool between(Point a, Point b, Point x) {
    if ((x - a) % (x - b) != 0) return false;
    if (a.x != b.x) return between(a.x, b.x, x.x);
    else return a.x == x.x && between(a.y, b.y, x.y);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Point a, b, c; cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    LL d, v; cin >> d >> v;
    double alex = d + 60 * (sqrt(a.dist2(c)) + sqrt(c.dist2(b))) / v;
    char tmp; LL sh, sm, fh, fm; cin >> sh >> tmp >> sm >> fh >> tmp >> fm;
    double dmitry = (sh - 9) * 60 + sm + fh * 60 + fm;
    LL w; cin >> w;
    double petr = 60 * sqrt(a.dist2(b)) / w;
    if (between(a, b, c)) petr += d;
         if (alex < dmitry && alex < petr) cout << "Alex\n";
    else if (dmitry < alex && dmitry < petr) cout << "Dmitry\n";
    else if (petr < dmitry && petr < alex) cout << "Petr\n";
}
