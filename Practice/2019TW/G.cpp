#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        vector<vector<LL> > G(n, vector<LL>(n, INF));
        string s; getline(cin, s);
        for (int i = 0 ; i < n ; i++) {
            getline(cin, s);
            stringstream ss; ss << s;
            int tar; while (ss >> tar)
                G[i][tar - 1] = 1;
        }
        vector<vector<LL> > D = G;
        LL minV = INF;
        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < k ; i++)
                for (int j = 0 ; j < i ; j++)
                    minV = min(minV, G[k][i] + D[i][j] + G[j][k]);
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
        }
        if (minV == INF)
            cout << 0 << '\n';
        else
            cout << minV << '\n';
    }
}
