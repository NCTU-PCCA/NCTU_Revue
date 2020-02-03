#include <bits/stdc++.h>
using namespace std;
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y; cin >> x >> y;
    int x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    if (x <= x1 && y >= y2) {
        cout << fixed << setprecision(3) << int(1000 * dist(x, y, x1, y2) + .5) / 1000. << '\n';
    } else if (x1 <= x && x <= x2 && y >= y2) {
        cout << fixed << setprecision(3) << int(1000 * (y - y2) + .5) / 1000. << '\n';
    } else if (x >= x2 && y >= y2) {
        cout << fixed << setprecision(3) << int(1000 * dist(x, y, x2, y2) + .5) / 1000. << '\n';
    } else if (x >= x2 && y1 <= y && y <= y2) {
        cout << fixed << setprecision(3) << int(1000 * (x - x2) + .5) / 1000. << '\n';
    } else if (x >= x2 && y <= y1) {
        cout << fixed << setprecision(3) << int(1000 * dist(x, y, x2, y1) + .5) / 1000. << '\n';
    } else if (x1 <= x && x <= x2 && y <= y1) {
        cout << fixed << setprecision(3) << int(1000 * (y1 - y) + .5) / 1000. << '\n';
    } else if (x <= x1 && y <= y1) {
        cout << fixed << setprecision(3) << int(1000 * dist(x, y, x1, y1) + .5) / 1000. << '\n';
    } else if (x <= x1 && y1 <= y && y <= y2) {
        cout << fixed << setprecision(3) << int(1000 * (x1 - x) + .5) / 1000. << '\n';
    }
}
