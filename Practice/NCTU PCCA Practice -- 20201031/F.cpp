#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int find(int x, auto &pa) {
    return pa[x] < 0 ? x : pa[x] = find(pa[x], pa);
}
void join(int i, int j, auto &pa) {
    int x = find(i, pa);
    int y = find(j, pa);
    if (x == y) return ;
    if (pa[x] > pa[y])
        swap(x, y);
    pa[x] += pa[y];
    pa[y] = x;
}
vector<vector<int>> gen_pa(auto &G, auto &numC, auto &numT) {
    int n = G.size(), m = G[0].size();
    vector<vector<int>> ret;
    vector<int> pre(n, -1);
    for (int i = 1 ; i < n ; i++)
        if (G[i][0] == G[i - 1][0])
            join(i - 1, i, pre);
    int cnt = 0, cntT = 0;
    for (int i = 0 ; i < n ; i++) {
        if (find(i, pre) != i)
            continue;
        cnt++;
        if (G[i][0] == 1)
            cntT++;
    }
    numC.push_back(cnt);
    numT.push_back(cntT);
    ret.push_back(pre);
    for (int j = 1 ; j < m ; j++) {
        vector<int> pa(n, -1);
        for (int i = 1 ; i < n ; i++)
            if (G[i][j] == G[i - 1][j])
                join(i - 1, i, pa);
        vector<vector<int>> grp(n);
        for (int i = 0 ; i < n ; i++) {
            if (find(i, pa) != i)
                continue;
            if (G[i][j - 1] != G[i][j])
                continue;
            grp[find(i, pre)].push_back(i);
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 1 ; j < grp[i].size() ; j++)
                join(grp[i][j - 1], grp[i][j], pa);
        }

        vector<int> newone(n, 0);
        for (int i = 0 ; i < n ; i++) {
            if (find(i, pa) == i)
                newone[find(i, pa)] = 1;
        }
        for (int i = 0 ; i < n ; i++) {
            if (G[i][j - 1] != G[i][j])
                continue;
            newone[find(i, pa)] = 0;
        }
        int cnt = 0, cntT = 0;
        for (int i = 0 ; i < n ; i++) {
            cnt += newone[i];
            if (G[i][j] == 1)
                cntT += newone[i];
        }
        numC.push_back(numC.back() + cnt);
        numT.push_back(numT.back() + cntT);
        pre = pa;
        ret.push_back(pre);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        for (int j = 0 ; j < m ; j++)
            G[i][j] = s[j] - '0';
    }
    vector<int> bnumlC, bnumlT;
    vector<vector<int>> bleft = gen_pa(G, bnumlC, bnumlT);
    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());
    vector<int> bnumrC, bnumrT;
    vector<vector<int>> bright = gen_pa(G, bnumrC, bnumrT);
    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());
    reverse(bright.begin(), bright.end());
    reverse(bnumrC.begin(), bnumrC.end());

    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ;j ++)
            G[i][j] ^= 1;

    vector<int> wnumlC, wnumlT;
    vector<vector<int>> wleft = gen_pa(G, wnumlC, wnumlT);
    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());
    vector<int> wnumrC, wnumrT;
    vector<vector<int>> wright = gen_pa(G, wnumrC, wnumrT);
    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());
    reverse(wright.begin(), wright.end());
    reverse(wnumrC.begin(), wnumrC.end());
    reverse(wnumrT.begin(), wnumrT.end());

    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ;j ++)
            G[i][j] ^= 1;

    if (m == 1) {
        cout << 0 << ' ' << 1 << '\n';
    } else {
        int ansR = 0, ansW = 0;
        for (int j = 0 ; j < m ; j++) {
            int numR = 0, numW = 0;
            if (j == 0) {
                int numB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (G[i][1] == 0)
                        continue;
                    numB += (find(i, bright[1]) == i);
                }
                numR = bnumrC[1] - numB + 1;
                numW = wnumrT[1];
            } else if (j == m - 1) {
                int numB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (G[i][m - 2] == 0)
                        continue;
                    numB += (find(i, bleft[m - 2]) == i);
                }
                numR = bnumlC[m - 2] - numB + 1;
                numW = wnumlT[m - 2];
            } else {
                int numlB = 0, numrB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (G[i][j - 1] == 0)
                        continue;
                    numlB += (find(i, bleft[j - 1]) == i);
                }

                for (int i = 0 ; i < n ; i++) {
                    if (G[i][j + 1] == 0)
                        continue;
                    numrB += (find(i, bright[j + 1]) == i);
                }
                numR = bnumlC[j - 1] + bnumrC[j + 1] - numlB - numrB + 1;
                numW = wnumlT[j - 1] + wnumrT[j + 1];
            }
            if (numR > ansR) {
                ansR = numR;
                ansW = numW;
            } else if (numR == ansR) {
                if (numW > ansW)
                    ansW = numW;
            }
        }
        cout << ansW << ' ' << ansR - ansW << '\n';
    }
}
