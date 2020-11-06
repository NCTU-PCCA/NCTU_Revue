#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
vector<pair<pii, pii>> solve(int cx, int cy, int x, int y, int n) {
    vector<pair<pii, pii>> ans;
    while (1) {
        cout << cx << ' ' << cy << endl;
        if (x == 0 && y == 0)
            break;
        if (x < n && y < n) {
            if (x == 0) {
                if (cx == 0 && cy == 0) 
                    cy--;
                ans.push_back({{cx, cy + n}, {cx - n + 1, cy + 1}});
            } else if (y == 0) {
                if (cx == 0 && cy == 0) 
                    cx--;
                ans.push_back({{cx + n, cy + n - 1}, {cx + 1, cy}});
            } else {
                if (cx == 0 && cy == 0) 
                    cy--;
                ans.push_back({{cx + x, cy + n}, {cx + x - n + 1, cy + 1}});
            }
            break;
        } else if (x >= n && y >= n) {
            if (x > y) {
                if (cx == 0 && cy == 0) 
                    cx--;
                ans.push_back({{cx + n, cy + n - 1}, {cx + 1, cy}});
                x -= n;
                y -= n - 1;
                cx += n;
                cy += n - 1;
            } else {
                if (cx == 0 && cy == 0) 
                    cy--;
                ans.push_back({{cx + n - 1, cy + n}, {cx, cy + 1}});
                x -= n - 1;
                y -= n;
                cx += n - 1;
                cy += n;
            }
        } else if (x < n && y >= n) {
            if (cx == 0 && cy == 0) 
                cy--;
            ans.push_back({{cx, cy + n}, {cx - n + 1, cy + 1}});
            cy += n;
            y -= n;
        } else if (x >= n && y < n) {
            if (cx == 0 && cy == 0) 
                cx--;
            ans.push_back({{cx + n, cy}, {cx + 1, cy - n + 1}});
            cx += n;
            x -= n;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int _a, _b, n; cin >> _a >> _b >> n;
        int x = abs(_a);
        int y = abs(_b);
        int cx = 0, cy = 0;
        vector<pair<pii, pii>> ans;
        ans = solve(0, 0, x, y, n);
        cout << ans.size() << '\n';
        for (auto &pp : ans) {
            pp.F.F *= (_a < 0 ? -1 : 1);
            pp.F.S *= (_b < 0 ? -1 : 1);
            pp.S.F *= (_a < 0 ? -1 : 1);
            pp.S.S *= (_b < 0 ? -1 : 1);
            cout << pp.F.F << ' ' << pp.F.S << ' ' << pp.S.F << ' ' << pp.S.S << '\n';
        }
    }

}
