#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
pii decode(int x, int n, int m) {
    return {x / m, x % m};
}
int encode(pii p, int n, int m) {
    return p.F * m + p.S;
}
const int INF = 0x3f3f3f3f;
vector<vector<int> > bfs(pii s, vector<vector<int> > &G, int n, int m) {
    vector<vector<int> > d(n, vector<int>(m, INF));
    queue<pii> q; q.push(s); d[s.F][s.S] = 0; while (q.size()) {
        auto p = q.front(); q.pop();
        for (auto &v : G[encode(p, n, m)]) {
            pii nt = decode(v, n, m);
            if (d[nt.F][nt.S] == INF) {
                d[nt.F][nt.S] = d[p.F][p.S] + 1;
                q.push(nt);
            }
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, kase = 0; while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        cout << "Case " << ++kase << ": ";
        vector<vector<int> > G(n * m), TG(n * m);
        for (int i = 0 ; i < n * m - 1 ; i++) {
            int pos; char dir;
            cin >> pos >> dir;
            pii p = decode(i, n, m);
            if (dir == 'N') {
                pii nt = {p.F - pos, p.S};
                if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                    continue;
                G[encode(nt, n, m)].push_back(encode(p, n, m));
                TG[encode(p, n, m)].push_back(encode(nt, n, m));
            } else if (dir == 'S') {
                pii nt = {p.F + pos, p.S};
                if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                    continue;
                G[encode(nt, n, m)].push_back(encode(p, n, m));
                TG[encode(p, n, m)].push_back(encode(nt, n, m));
            } else if (dir == 'W') {
                pii nt = {p.F, p.S - pos};
                if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                    continue;
                G[encode(nt, n, m)].push_back(encode(p, n, m));
                TG[encode(p, n, m)].push_back(encode(nt, n, m));
            } else if (dir == 'E') {
                pii nt = {p.F, p.S + pos};
                if (nt.F < 0 || nt.F >= n || nt.S < 0 || nt.S >= m)
                    continue;
                G[encode(nt, n, m)].push_back(encode(p, n, m));
                TG[encode(p, n, m)].push_back(encode(nt, n, m));
            }
        }
        vector<vector<int> > d = bfs({n - 1, m - 1}, G, n, m);
        vector<bool> vis(n * m, false), r(n, false), c(m, false);
        int pos = 0, ans = d[0][0], ansPos = -1, cnt = 0;
        string ansStr; int ansDelta;
        while (pos != n * m - 1) {
            if (vis[pos])
                break;
            vis[pos] = true;
            pii decodep = decode(pos, n, m);
            if (!r[decodep.F]) {
                r[decodep.F] = true;
                int minV = INF, minIdx = -1;
                vector<int> idx;
                for (int i = 0 ; i < m ; i++) {
                    if (d[decodep.F][i] < minV) {
                        minIdx = i;
                        idx.clear();
                        minV = d[decodep.F][i];
                        idx.push_back(i);
                    } else if (d[decodep.F][i] == minV)
                        idx.push_back(i);
                }
                
                
                if (cnt + minV + 1 < ans) {
                    ans = cnt + minV + 1;
                    ansDelta = abs(minIdx - decodep.S);
                    ansPos = pos;
                    if (minIdx < decodep.S)
                        ansStr = "W";
                    else
                        ansStr = "E";
                } else if (cnt + minV + 1 == ans) {
                    if (pos < ansPos) {
                        ansPos = pos;
                        ansDelta = abs(minIdx - decodep.S);
                        if (minIdx < decodep.S)
                            ansStr = "W";
                        else
                            ansStr = "E";
                    }
                }
            }
            if (!c[decodep.S]) {
                c[decodep.S] = true;
                int minV = INF, minIdx = -1;
                for (int i = 0 ; i < n ; i++) {
                    if (d[i][decodep.S] < minV) {
                        minIdx = i;
                        minV = d[i][decodep.S];
                    }
                }
                if (cnt + minV + 1 < ans) {
                    ans = cnt + minV + 1;
                    ansDelta = abs(minIdx - decodep.F);
                    ansPos = pos;
                    if (minIdx < decodep.F)
                        ansStr = "N";
                    else
                        ansStr = "S";
                } else if (cnt + minV + 1 == ans) {
                    if (pos < ansPos) {
                        ansPos = pos;
                        ansDelta = abs(minIdx - decodep.F);
                        if (minIdx < decodep.F)
                            ansStr = "N";
                        else
                            ansStr = "S";
                    }
                }
            }
            if (!TG[pos].size())
                break;
            pos = TG[pos][0];
            cnt++;
        }
        if (ans == INF) {
            cout << "impossible\n";
        } else {
            if (!ansStr.size()) {
                cout << "none " << d[0][0] << '\n';
            } else {
                cout << decode(ansPos, n, m).F << ' ' << decode(ansPos, n, m).S << ' ' << ansDelta << ansStr <<  ' ' << ans << '\n';
            }
        }
    }
    
}
