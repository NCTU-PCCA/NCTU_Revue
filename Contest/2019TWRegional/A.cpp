#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > B;
map<B, int> P;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int> > _B(8, vector<int>(8));
    for (int i = 0 ; i < 6; i++)
        for (int j = 0 ; j < 6 ; j++)
            cin >> _B[i][j];

    queue<B> q; q.push(_B); P[_B] = 0;
    while (q.size()) {
        B p = q.front(); q.pop();
        if (p[2][4] == 1 && p[2][5] == 1) {
            cout << P[p] + 2 << '\n';
            exit(0);
        }
        if (P[p] == 8)
            continue;

        for (int i = 0 ; i < 6 ; i++) {
            for (int j = 0 ; j + 2 < 6 ; j++) {
                if (p[i][j] == p[i][j + 1] && p[i][j + 1] == p[i][j + 2] && p[i][j] != 0) {
                    if (j - 1 >= 0 && p[i][j - 1] == 0) {
                        B tmp = p;
                        p[i][j - 1] = p[i][j];
                        p[i][j + 2] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                    if (j + 3 < 6 && p[i][j + 3] == 0) {
                        B tmp = p;
                        p[i][j + 3] = p[i][j];
                        p[i][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                }
            }
        }
        for (int j = 0 ; j < 6 ; j++) {
            for (int i = 0 ; i + 2 < 6 ; i++) {
                if (p[i][j] == p[i + 1][j] && p[i + 1][j] == p[i + 2][j] && p[i][j] != 0) {
                    if (i - 1 >= 0 && p[i - 1][j] == 0) {
                        B tmp = p;
                        p[i - 1][j] = p[i][j];
                        p[i + 2][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                    if (i + 3 < 6 && p[i + 3][j] == 0) {
                        B tmp = p;
                        p[i + 3][j] = p[i][j];
                        p[i][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                }
            }
        }
        for (int i = 0 ; i < 6 ; i++) {
            for (int j = 0 ; j + 1 < 6 ; j++) {
                if (p[i][j] == p[i][j + 1] && p[i][j] != 0) {
                    if (j - 1 >= 0 && p[i][j - 1] == p[i][j])
                        continue;
                    if (j + 2 < 6 && p[i][j + 2] == p[i][j])
                        continue;
                    if (j - 1 >= 0 && p[i][j - 1] == 0) {
                        B tmp = p;
                        p[i][j - 1] = p[i][j];
                        p[i][j + 1] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                    if (j + 2 < 6 && p[i][j + 2] == 0) {
                        B tmp = p;
                        p[i][j + 2] = p[i][j];
                        p[i][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                }
            }
        }
        for (int j = 0 ; j < 6 ; j++) {
            for (int i = 0 ; i + 1 < 6 ; i++) {
                if (p[i][j] == p[i + 1][j] && p[i][j] != 0) {
                    if (i - 1 >= 0 && p[i - 1][j] == p[i][j])
                        continue;
                    if (i + 2 < 6 && p[i + 2][j] == p[i][j])
                        continue;
                    if (i - 1 >= 0 && p[i - 1][j] == 0) {
                        B tmp = p;
                        p[i - 1][j] = p[i][j];
                        p[i + 1][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                    if (i + 2 < 6 && p[i + 2][j] == 0) {
                        B tmp = p;
                        p[i + 2][j] = p[i][j];
                        p[i][j] = 0;
                        if (!P.count(p)) {
                            P[p] = P[tmp] + 1;
                            q.push(p);
                        }
                        p = tmp;
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}
