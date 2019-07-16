#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const LL MOD = 1e9 + 7;
map<pair<LL, LL>, bool> S;
int ID(char c) {
    if (c == 'x') return 0;
    if (c == 'R') return 1;
    if (c == 'G') return 2;
    if (c == 'B') return 3;
    if (c == 'Y') return 4;
    return -1;
}
pair<long long, long long> trans(vector<vector<char> > &G) {
    long long res1 = 0, res2 = 0;
    for (int i = 0 ; i < 5 ; i++)
        for (int j = 0 ; j < 6 ; j++)
            res1 *= 616069, res1 += ID(G[i][j]),
            res2 *= 0xdefaced, res2 %= MOD, res2 += ID(G[i][j]), res2 %= MOD;
    return {res1, res2};
}
void trim(vector<vector<char> > &G) {
    for (int i = 0 ; i < 6 ; i++) {
        int stamp = 4;
        for (int j = 4 ; j >= 0 ; j--)
            if (G[j][i] != 'x')
                G[stamp--][i] = G[j][i];
        for (int j = stamp ; j >= 0 ; j--)
            G[stamp--][i] = 'x';
    }
    vector<vector<char> > tmp(5);
    for (int j = 0 ; j < 6 ; j++) {
        bool ok = false;
        for (int i = 0 ; i < 5 ; i++) {
            if (G[i][j] != 'x')
                ok = true;
        }
        if (ok) {
            for (int i = 0 ; i < 5 ; i++)
                tmp[i].push_back(G[i][j]);
        }
    }
    while (tmp[0].size() != 6) {
        for (int i = 0 ; i < 5 ; i++)
            tmp[i].push_back('x');
    }
    G = tmp;
}
bool solve(vector<vector<char> > &G) {
    pair<LL, LL> Ss = trans(G);
    if (S.count(Ss))
        return S[Ss];
    bool ok = true;
    for (auto &vv : G)
        for (auto &v : vv)
            if (v != 'x')
                ok = false;
    if (ok) return S[Ss] = true;
    vector<vector<bool> > vis(5, vector<bool>(6, false));
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 6 ; j++) {
            if (vis[i][j] || G[i][j] == 'x')
                continue;
            vector<vector<char> > B = G;
            char tar = B[i][j];
            queue<pii> q; q.push({i, j}); vis[i][j] = true; B[i][j] = 'x';
            int cnt = 0;
            while (q.size()) {
                pii p = q.front(); q.pop(); cnt++;
                for (int d = 0 ; d < 4 ; d++) {
                    pii nt = {p.F + dx[d], p.S + dy[d]};
                    if (nt.F < 0 || nt.F >= 5 || nt.S < 0 || nt.S >= 6)
                        continue;
                    if (vis[nt.F][nt.S])
                        continue;
                    if (B[nt.F][nt.S] != tar)
                        continue;
                    q.push(nt);
                    vis[nt.F][nt.S] = true;
                    B[nt.F][nt.S] = 'x';
                }
            }

            if (cnt > 1) {
                trim(B);
                if (solve(B))
                    return S[Ss] = true;
            }
        }
    }
    return S[Ss] = false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        S.clear();
        cout << "Case " << ++kase << ": ";
        vector<vector<char> > G(5, vector<char>(6));
        for (auto &vv : G)
            for (auto &v : vv)
                cin >> v;
        if (solve(G))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
