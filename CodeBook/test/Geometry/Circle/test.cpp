#include <bits/stdc++.h>
#include "../../../Geometry/Circle.cpp"
using namespace std;

// uva 10005
vector<P> points;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int type; cin >> type;
    if (type == 1) {
        int n;
        while (cin >> n && n) {
            for (int i = 0; i < n; i ++) {
              double x, y; cin >> x >> y;
              points.push_back({x, y});
            }
            double r; cin >> r;
            pair<P, double> ans = SmallestEnclosingCircle(points);
            if (ans.second > r) {
                cout << "There is no way of packing that polygon.\n";
            } else {
                cout << "The polygon can be packed in the circle.\n";
            }
        }
    } else if (type == 2) {
        int T; cin >> T; while (T --) {
            P c; double r;
            cin >> c.x >> c.y >> r;
            int q; cin >> q;
            while (q --) {
                P a, b;
                cin >> a.x >> a.y >> b.x >> b.y;
                vector<P> ans = CircleLineIntersection(c, r, L(a, b));
                sort(ans.begin(), ans.end());
                for (int i = 0; i < ans.size(); i ++) {
                    cout << fixed << setprecision(6) << ans[i].x + EPS << ' ' << ans[i].y + EPS << ' ';
                }
                cout << '\n';
            }
        }
    } else if (type == 3) {
        int T; cin >> T; while (T --) {
            P c1, c2; double r1, r2;
            cin >> c1.x >> c1.y >> r1;
            int q; cin >> q;
            while (q --) {
                cin >> c2.x >> c2.y >> r2;
                vector<P> ans = CircleCircleIntersection(c1, c2, r1, r2);
                sort(ans.begin(), ans.end());
                for (int i = 0; i < ans.size(); i ++) {
                    cout << fixed << setprecision(6) << ans[i].x + EPS << ' ' << ans[i].y + EPS << ' ';
                }
                cout << '\n';
            }
        }
    }
}

