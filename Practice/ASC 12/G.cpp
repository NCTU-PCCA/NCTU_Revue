#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("pipe.in");
    ofstream out("pipe.out");
    int n, k; in >> n >> k;
    pair<pii, pii> line[2];
    for (int i = 0 ; i < 2 ; i++) {
        in >> line[i].F.F >> line[i].F.S >> line[i].S.F >> line[i].S.S;
    }
    vector<double> w[2];
    for (int i = 0 ; i < n ; i++) {
        int x, y; double z;
        in >> x >> y >> z;
        for (int j = 0 ; j < 2 ; j++) {
            int a = line[j].S.S - line[j].F.S;
            int b = - line[j].S.F + line[j].F.F;
            int c = - a * line[j].F.F - b * line[j].F.S;
            w[j].push_back(abs(a * x + b * y + c) / sqrt(a * a + b * b) * z);
        }
    }
    vector<int> group; vector<pair<double, int> > diff;
    int g0 = 0, g1 = 0;
    for (int i = 0 ; i < n ; i++) {
        if (w[0][i] < w[1][i]) {
            group.push_back(0);
            diff.push_back({w[1][i] - w[0][i], i});
            g0++;
        } else {
            group.push_back(1);
            diff.push_back({w[0][i] - w[1][i], i});
            g1++;
        }
    }
    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());
    int tar = (g0 < g1 ? 1 : 0);
    while (abs(g0 - g1) > k) {
        if (group[diff.back().S] != tar) {
            diff.pop_back();
            continue;
        } else {
            if (tar == 0) {
                group[diff.back().S] = 1;
                g0--, g1++;
            } else if (tar == 1) {
                group[diff.back().S] = 0;
                g0++, g1--;
            }
            diff.pop_back();
        }
    }
    for (int i = 0 ; i < n ; i++)
        out << group[i] + 1 << " \n"[i + 1 == n];
}
