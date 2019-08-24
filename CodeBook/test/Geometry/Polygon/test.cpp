#include <bits/stdc++.h>
#include "../../../Geometry/Polygon.cpp"
using namespace std;

vector<P> points;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int type; cin >> type;
    if (type == 1) { // point on or inside polygon
        int T; cin >> T; while (T --) {
            points.clear();
            int n; cin >> n;
            for (int i = 0; i < n; i ++) {
                double x, y; cin >> x >> y;
                points.push_back({x, y});
            }
            int m; cin >> m;
            while (m --) {
                P p; cin >> p.x >> p.y;
                if (PointOnPolygon(points, p)) {
                    cout << "on\n";
                    continue;
                }
                if (PointInPolygon(points, p)) {
                    cout << "in\n";
                } else {
                    cout << "out\n";
                }
            }
        }
    }
}

