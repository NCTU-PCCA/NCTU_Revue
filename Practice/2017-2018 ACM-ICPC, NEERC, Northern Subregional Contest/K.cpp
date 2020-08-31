#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("kotlin.in");
    ofstream out("kotlin.out");
    LL h, w, n; in >> h >> w >> n;
    for (LL i = 1 ; i * i <= n ; i++) {
        if (n % i)
            continue;
        LL x = i, y = n / i;
        if (x <= (h + 1) / 2 && y <= (w + 1) / 2) {
            vector<vector<int>> ok(h, vector<int>(w, 0));
            for (int i = 0 ; i < x - 1 ; i++) {
                for (int j = 0 ; j < w ; j++) {
                    ok[i * 2 + 1][j] = 1;
                }
            }
            for (int j = 0 ; j < y - 1 ; j++) {
                for (int i = 0 ; i < h ; i++) {
                    ok[i][j * 2 + 1] = 1;
                }
            }
            for (int i = 0 ; i < h ; i++) {
                for (int j = 0 ; j < w ; j++)
                    if (ok[i][j]) {
                        out << "#";
                    } else {
                        out << ".";
                    }
                out << '\n';
            }
            return 0;
        }
        if (y <= (h + 1) / 2 && x <= (w + 1) / 2) {
            vector<vector<int>> ok(h, vector<int>(w, 0));
            for (int i = 0 ; i < y - 1 ; i++) {
                for (int j = 0 ; j < w ; j++) {
                    ok[i * 2 + 1][j] = 1;
                }
            }
            for (int j = 0 ; j < x - 1 ; j++) {
                for (int i = 0 ; i < h ; i++) {
                    ok[i][j * 2 + 1] = 1;
                }
            }
            for (int i = 0 ; i < h ; i++) {
                for (int j = 0 ; j < w ; j++)
                    if (ok[i][j]) {
                        out << "#";
                    } else {
                        out << ".";
                    }
                out << '\n';
            }
            return 0;
        }
    }
    out << "Impossible\n";
}
