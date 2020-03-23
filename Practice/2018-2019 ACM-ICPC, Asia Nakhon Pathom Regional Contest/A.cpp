#include <bits/stdc++.h>
using namespace std;
struct ST {
    vector<vector<int> > data;
    ST(vector<int> &arr) {
        int n = (int)arr.size(), lgN = __lg(n) + 1;
        data.resize(lgN);
        for (int i = 0 ; i < n ; i++)
            data[0].push_back(arr[i]);
        for (int h = 1 ; h < lgN ; h++) {
            int len = 1 << (h - 1), i = 0;
            for (; i + len < n ; i++)
                data[h].push_back(max(data[h-1][i], data[h-1][i+len]));
            if (!i) break;
            for (; i < n ; i++)
                data[h].push_back(data[h-1][i]);
        }
    }
    int query(int l, int r) {
        int h = __lg(r - l), len = 1 << h;
        return max(data[h][l], data[h][r - len]);
    }

};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data;
    vector<vector<int> > V;
    int n, m; cin >> n >> m;
    data.resize(n + 1);
    V.resize(n + 5);
    data[0] = n + 4;
    for (int i = 1 ; i <= n ; i++) {
        cin >> data[i];
        V[data[i]].push_back(i);
    }
    vector<vector<int> > G(n + 1);
    ST *sol = new ST(data);
    for (int i = 0 ; i <= n ; i++) {
        int L = 0, R = i; // L
        while (R - L > 1) {
            int M = (R + L) >> 1;
            if (sol->query(M, i) >= data[i])
                L = M;
            else
                R = M;
        }
        // construct 
        if (L != i - 1) {
            int maxV = sol->query(L + 1, i);
            for (auto it = upper_bound(V[maxV].begin(), V[maxV].end(), L) ; it != upper_bound(V[maxV].begin(), V[maxV].end(), i) ; it++) {
                G[i].push_back(*it);
            }
        }
        L = i + 1, R = n;
        while (R - L) {
            int M = (R + L) >> 1;
            if (sol->query(i + 1, M) >= data[i])
                R = M;
            else
                L = M;
        }
        //construct 
        if (L != i) {
            int maxV = sol->query(i + 1, L);
            for (auto it = upper_bound(V[maxV].begin(), V[maxV].end(), i) ; it != upper_bound(V[maxV].begin(), V[maxV].end(), L) ; it++) {
                G[i].push_back(*it);
            }
        }
    }
    for (auto &vv : G) {
        for (auto &v : vv)
            cout << v << ' ';
        cout << '\n';
    }
    delete sol;
}
