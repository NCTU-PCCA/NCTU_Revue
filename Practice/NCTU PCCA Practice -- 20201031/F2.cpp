#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int find(int x, auto &pa) {
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

void cal(auto &G, auto &pa_arr, auto &numW, auto &numB) {
    int n = G.size(), m = G[0].size();
    vector<int> pre(n, -1);
    for (int i = 1 ; i < n ; i++)
        if (G[i][0] == G[i - 1][0])
            join(i - 1, i, pre);
    int cnt[2] = {};
    for (int i = 0 ; i < n ; i++) {
        if (find(i, pre) != i)
            continue;
        cnt[G[i][0]]++;
    }
    numW.push_back(cnt[0]);
    numB.push_back(cnt[1]);
    pa_arr.push_back(pre);
    for (int j = 1 ; j < m ; j++) {
        vector<int> pa(n, -1);
        for (int i = 1 ; i < n ; i++)
            if (G[i][j] == G[i - 1][j])
                join(i - 1, i, pa);
        vector<vector<int>> grp(n);
        for (int i = 0 ; i < n ; i++) {
            if (G[i][j - 1] != G[i][j])
                continue;
            grp[find(i, pre)].push_back(find(i, pa));
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 1 ; j < grp[i].size() ; j++)
                join(grp[i][j - 1], grp[i][j], pa);
        }

        vector<set<int>> grp2(n);
        for (int i = 0 ; i < n ; i++) {
            if (G[i][j - 1] != G[i][j])
                continue;
            grp2[find(i, pa)].insert(find(i, pre));
        }
        int desW = 0, desB = 0;
        for (int i = 0 ; i < n ; i++) {
            if (i != find(i, pa))
                continue;
            if (grp2[i].size() == 0) {
                if (G[i][j] == 0)
                    desW++;
                else
                    desB++;
                continue;
            }
            if (G[i][j] == 0) {
                desW -= grp2[i].size() - 1;
            } else {
                desB -= grp2[i].size() - 1;
            }
        }
        
        numW.push_back(numW.back() + desW);
        numB.push_back(numB.back() + desB);
        pa_arr.push_back(pa);
        pre = pa;
    }
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

//void cal(auto &G, auto &pa_arr, auto &numW, auto &numB) {
    vector<vector<int>> left;
    vector<int> lnumW, lnumB;
    cal(G, left, lnumW, lnumB);
    
    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());

    vector<vector<int>> righ;
    vector<int> rnumW, rnumB;
    cal(G, righ, rnumW, rnumB);

    for (int i = 0 ; i < n ; i++)
        reverse(G[i].begin(), G[i].end());

    reverse(righ.begin(), righ.end());
    reverse(rnumW.begin(), rnumW.end());
    reverse(rnumB.begin(), rnumB.end());

    /*
    cout << "left\n";
    for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++)
            cout << find(i, left[j]) << ' ';
        cout << '\n';
    }
    cout << "lnumW\n";
    for (int j = 0 ; j < m ; j++)
        cout << lnumW[j] << ' ';
    cout << '\n';
    cout << "lnumB\n";
    for (int j = 0 ; j < m ; j++)
        cout << lnumB[j] << ' ';
    cout << '\n';

    cout << "righ\n";
    for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++)
            cout << find(i, righ[j]) << ' ';
        cout << '\n';
    }
    cout << "rnumW\n";
    for (int j = 0 ; j < m ; j++)
        cout << rnumW[j] << ' ';
    cout << '\n';
    cout << "rnumB\n";
    for (int j = 0 ; j < m ; j++)
        cout << rnumB[j] << ' ';
    cout << '\n';
    */

    if (m == 1) {
        cout << 0 << ' ' << 1 << '\n';
    } else {
        int ansR = 0, ansW = 0;
        for (int j = 0 ; j < m ; j++) {
            int numR = 0, numW = 0;
            if (j == 0) {
                int numB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (find(i, righ[j + 1]) != i)
                        continue;
                    if (G[i][j + 1] == 1)
                        numB++;
                }
                numR = rnumW[j + 1] + rnumB[j + 1] - numB + 1;
                numW = rnumW[j + 1];
            } else if (j == m - 1) {
                int numB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (find(i, left[j - 1]) != i)
                        continue;
                    if (G[i][j - 1] == 1)
                        numB++;
                }
                numR = lnumW[j - 1] + lnumB[j - 1] - numB + 1;
                numW = lnumW[j - 1];
            } else {

                int numlB = 0, numrB = 0;
                for (int i = 0 ; i < n ; i++) {
                    if (find(i, left[j - 1]) != i)
                        continue;
                    if (G[i][j - 1] == 1)
                        numlB++;
                }
                for (int i = 0 ; i < n ; i++) {
                    if (find(i, righ[j + 1]) != i)
                        continue;
                    if (G[i][j + 1] == 1)
                        numrB++;
                }

                numW = lnumW[j - 1] + rnumW[j + 1];
                numR = numW + lnumB[j - 1] + rnumB[j + 1] - numlB - numrB + 1;
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
