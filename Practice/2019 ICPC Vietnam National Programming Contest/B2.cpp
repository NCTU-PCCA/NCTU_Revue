#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c, n; while (cin >> a) {
        if (a == -1)
            break;
        cout << "YES\n";
        cin >> b >> c >> n;
        vector<vector<int> > Xp(n);
        int idx = 0;
        for (auto &p : Xp) {
            p.resize(3);
            for (auto &v : p)
                cin >> v;
            p.push_back(idx);
            idx++;
        }
        sort(Xp.begin(), Xp.end());
        vector<int> X;
        for (int i = 0 ; i < Xp.size() ; i++)
            X.push_back(Xp[i][0]);
        X.erase(unique(X.begin(), X.end()), X.end());
        X[0] = 1;
        X.push_back(a + 1);
        Xp.push_back({INF, INF, INF});
        vector<vector<int> > Yp;
        int ptrX = 0;
        vector<vector<int> > ans(n);
        for (int i = 0 ; i < Xp.size() ; i++) {
            if (X[ptrX] <= Xp[i][0] && Xp[i][0] < X[ptrX + 1])
                Yp.push_back(Xp[i]);
            else {
                vector<int> Y;
                for (int j = 0 ; j < Yp.size() ; j++)
                    Y.push_back(Yp[j][1]);
                Y.erase(unique(Y.begin(), Y.end()), Y.end());
                Y[0] = 1;
                Y.push_back(b + 1);
                int ptrY = 0;
                vector<vector<int> > Zp;
                Yp.push_back({INF, INF, INF});
                for (int j = 0 ; j < Yp.size() ; j++) {
                    if (Y[ptrY] <= Yp[j][1] && Yp[j][1] < Y[ptrY + 1])
                        Zp.push_back(Yp[j]);
                    else {
                        vector<int> Z;
                        for (int k = 0 ; k < Zp.size() ; k++)
                            Z.push_back(Zp[k][2]);
                        Z[0] = 1;
                        Z.push_back(c + 1);
                        for (int k = 0 ; k < Z.size() - 1 ; k++) {
                            ans[Zp[k][3]] = {X[ptrX], Y[ptrY], Z[k], X[ptrX + 1] - 1, Y[ptrY + 1] - 1, Z[k + 1] - 1};
                        }
                        ptrY++;
                        Zp.clear();
                        Zp.push_back(Yp[j]);
                    }
                }
                ptrX++;
                Yp.clear();
                Yp.push_back(Xp[i]);
            }
        }
        for (auto &v : ans) {
            for (int i = 0 ; i < 6 ; i++)
                cout << v[i] << " \n"[i + 1 == 6];
        }
    }
}
