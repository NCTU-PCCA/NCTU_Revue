#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
void solve(vector<vector<char> > &G, int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) return ;
    vector<int> X;
    for (int i = x1 ; i < x2 ; i++) {
        for (int j = y1 ; j < y2 ; j++) {
            if (G[i][j] != '.') {
                X.push_back(i);
                break;
            }
        }
    }
    X[0] = x1;
    X.push_back(x2);
    for (int i = 0 ; i < X.size() - 1 ; i++) {
        vector<int> Y;
        for (int j = y1 ; j < y2 ; j++) {
            for (int k = X[i] ; k < X[i + 1] ; k++) {
                if (G[k][j] != '.') {
                    Y.push_back(j);
                }
            }
        }
        Y.push_back(y2);
        Y[0] = y1;
        for (int _y = 0 ; _y < Y.size() - 1 ; _y++) {
            char tar; int f = 0;
            for (int x = X[i] ; x < X[i + 1] ; x++) {
                for (int y = Y[_y] ; y < Y[_y + 1] ; y++) {
                    if (G[x][y] != '.') {
                        tar = G[x][y];
                        f = 1;
                        break;
                    }
                    if (f)
                        break;
                }
            }
            for (int x = X[i] ; x < X[i + 1] ; x++) {
                for (int y = Y[_y] ; y < Y[_y + 1] ; y++) {
                    if (G[x][y] == '.') {
                        G[x][y] = tolower(tar);
                    }
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n, vector<char>(m));
    pii A;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'A')
                A.F = i, A.S = j;
        }
    }
    G[A.F][A.S] = '.';
    vector<vector<int> > r(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        if (G[i][m - 1] != '.')
            r[i][m - 1] = 0;
        else
            r[i][m - 1] = 1;
        for (int j = m - 2 ; j >= 0 ; j--) {
            if (G[i][j] != '.')
                r[i][j] = 0;
            else
                r[i][j] = r[i][j + 1] + 1;
        }
    }
    int mx = 0, X = -1, Y = -1, W, H;
    for (int i = 0 ; i <= A.F ; i++) {
        for (int j = 0 ; j <= A.S ; j++) {
            int mn = r[i][j];
            for (int k = i ; k <= A.F ; k++)
                mn = min(mn, r[k][j]);
            if (mn + j <= A.S)
                continue;
            for (int k = A.F ; k < n ; k++) {
                mn = min(mn, r[k][j]);
                if (mn + j <= A.S)
                    break;
                if (mn * (k - i + 1) > mx) {
                    X = i, Y = j;
                    W = k - i + 1;
                    H = mn;
                }
                mx = max(mx, mn * (k - i + 1));
            }
        }
    }
    for (int i = 0 ; i < W ; i++)
        for (int j = 0 ; j < H ; j++)
            G[X + i][Y + j] = 'a';
    G[A.F][A.S] = 'A';


    solve(G, 0,     0,      X,          m);
    solve(G, X,     0,      X + W,      Y);
    solve(G, X,     Y + H,  X + W,      m);
    solve(G, X + W, 0,      n,          m);
    for (auto &vv : G) {
        for (auto &v : vv) 
            cout << v;
        cout << '\n';
    }
}
/*
.Y.....Z..
SaaaaaA...
.aaaaaa...
.aaaaaaFS.
.aaaaaa...
..D.......

............
............
............
............
............
.........IHG
.........FCD
.........EBA
*/
