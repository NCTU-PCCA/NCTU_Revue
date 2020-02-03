#include <bits/stdc++.h>
using namespace std;
double maxV[1 << 9][6][6], minV[1 << 9][6][6];
vector<int> maxOp[1 << 9][6][6], minOp[1 << 9][6][6];
const double INF = 1e20;
vector<vector<int> > par[13];
void solveMax(int S, int a, int b) {
    if (maxV[S][a][b] != -1) return ;
    maxV[S][a][b] = -INF;
    int sum = a + 1 + b + 1, ok = 0;
    for (auto &vec : par[sum]) {
        int can = 1;
        for (auto &v : vec) {
            if (!(S & (1 << v)))
                can = 0;
        }
        if (!can) continue;
        ok = 1;
        int nt = S;
        for (auto &v : vec)
            nt ^= (1 << v);
        double sum = 0;
        for (int i = 0 ; i < 6 ; i++)
            for (int j = 0 ; j < 6 ; j++)
                solveMax(nt, i, j), sum += maxV[nt][i][j];
        sum /= 36;
        if (sum > maxV[S][a][b]) {
            maxV[S][a][b] = sum;
            maxOp[S][a][b] = vec;
        }
    }
    if (ok) return ;
    maxOp[S][a][b] = {-2};
    maxV[S][a][b] = 0;
    for (int i = 0 ; i < 9 ; i++) {
        if (S & (1 << i))
            maxV[S][a][b] *= 10, maxV[S][a][b] += (i + 1);
    }
}
void solveMin(int S, int a, int b) {
    if (minV[S][a][b] != -1) return ;
    minV[S][a][b] = INF;
    int sum = a + 1 + b + 1, ok = 0;
    for (auto &vec : par[sum]) {
        int can = 1;
        for (auto &v : vec) {
            if (!(S & (1 << v)))
                can = 0;
        }
        if (!can) continue;
        ok = 1;
        int nt = S;
        for (auto &v : vec)
            nt ^= (1 << v);
        double sum = 0;
        for (int i = 0 ; i < 6 ; i++)
            for (int j = 0 ; j < 6 ; j++)
                solveMin(nt, i, j), sum += minV[nt][i][j];
        sum /= 36;
        if (sum < minV[S][a][b]) {
            minV[S][a][b] = sum;
            minOp[S][a][b] = vec;
        }
    }
    if (ok) return ;
    minOp[S][a][b] = {-2};
    minV[S][a][b] = 0;
    for (int i = 0 ; i < 9 ; i++) {
        if (S & (1 << i))
            minV[S][a][b] *= 10, minV[S][a][b] += (i + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0 ; i < (1 << 9) ; i++)
        for (int j = 0 ; j < 6 ; j++)
            for (int k = 0 ; k < 6 ; k++)
                maxV[i][j][k] = minV[i][j][k] = -1;
    string s; int a, b; cin >> s >> a >> b;
    a--, b--;
    int S = 0;
    for (auto &c : s)
        S ^= (1 << (c - '1'));
    for (int _S = 1 ; _S < (1 << 9) ; _S++) {
        int sum = 0; vector<int> vec;
        for (int j = 0 ; j < 9 ; j++) {
            if (_S & (1 << j)) {
                vec.push_back(j);
                sum += j + 1;
            }
        }
        if (sum >= 13) continue;
        par[sum].push_back(vec);
    }
    solveMin(S, a, b);
    for (auto &v : minOp[S][a][b])
        cout << v + 1;
    cout << ' ';
    cout << fixed << setprecision(5) << minV[S][a][b] << '\n';
    solveMax(S, a, b);
    for (auto &v : maxOp[S][a][b])
        cout << v + 1;
    cout << ' ';
    cout << fixed << setprecision(5) << maxV[S][a][b] << '\n';
}
