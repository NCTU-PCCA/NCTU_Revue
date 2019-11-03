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
        vector<vector<int> > data(n);
        for (auto &v : data) {
            v.resize(3);
            for (auto &_c : v)
                cin >> _c;
        }
        sort(data.begin(), data.end());
        vector<int> X;
        for (int i = 0 ; i < n ; i++)
            X.push_back(data[i][0]);
        X.erase(unique(X.begin(), X.end()), X.end());
        X[0] = 1;
        X.push_back(a + 1);
        int ptrX = 0; // X
        vector<vector<int> > target;
        data.push_back({INF, INF, INF});
        for (int i = 0 ; i < data.size() ; i++) {
            if (X[ptrX] <= data[i][0] && data[i][0] < X[ptrX + 1])
                target.push_back(data[i]);
            else {
                vector<int> Y;
                for (int j = 0 ; j < target.size() ; j++)
                    Y.push_back(target[j][1]);
                Y.erase(unique(Y.begin(), Y.end()), Y.end());
                Y[0] = 1;
                Y.push_back(b + 1);
                int ptrY = 0;
                vector<vector<int> > target2;
                target.push_back({INF, INF, INF});
                for (int j = 0 ; j < target.size() ; j++) { 
                    if (Y[ptrY] <= target[j][1] && target[j][1] < Y[ptrY + 1]) {
                        target2.push_back(target[j]);
                    } else {
                        vector<int> Z;
                        for (int k = 0 ; k < target2.size() ; k++)
                            Z.push_back(target2[k][2]);
                        Z.erase(unique(Z.begin(), Z.end()), Z.end());
                        Z[0] = 1;
                        Z.push_back(c + 1);
                        for (int k = 0 ; k < Z.size() - 1 ; k++) {
                            cout << X[ptrX] << ' ' << Y[ptrY] << ' ' << Z[k] << ' ';
                            cout << X[ptrX + 1] - 1 << ' ' << Y[ptrY + 1] - 1 << ' ' << Z[k + 1] - 1 << '\n';
                        }
                        ptrY++;
                        target2.clear();
                        target2.push_back(target[j]);
                    }
                }
                ptrX++;
                target.clear();
                target.push_back(data[i]);
            }
        }
    }
       
}
