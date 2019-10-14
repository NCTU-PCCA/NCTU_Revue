#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 500 + 5;
typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct KM { LL W[MAXN][MAXN]; int V;
    LL mx[MAXN], my[MAXN]; LL lx[MAXN], ly[MAXN];
    bool x[MAXN], y[MAXN];
    KM(int V) : V(V) { memset(W, 0, sizeof(W)); }
    bool augment(int u) { x[u] = 1;
        for (int i = 0 ; i < V ; i++)
            if (!y[i] && W[u][i] == lx[u] + ly[i] && (y[i] = 1))
                if (!~my[i] || augment(my[i]))
                    return my[i] = u, true;
        return false;
    }
    LL run() {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for (int i = 0 ; i < V ; i++)
            lx[i] = -INF, ly[i] = 0;
        for (int i = 0 ; i < V ; i++)
            for (int j = 0 ; j < V ; j++)
                lx[i] = max(lx[i], W[i][j]);
        for (int i = 0 ; i < V ; i++) {
            while (1) {
                memset(x, false, sizeof(x));
                memset(y, false, sizeof(y));
                if (augment(i)) break;
                LL d = INF;
                for (int j = 0 ; j < V ; j++) {
                    if (!x[j]) continue;
                    for (int k = 0 ; k < V ; k++) {
                        if (y[k]) continue;
                        d = min(d, lx[j] + ly[k] - W[j][k]);
                    }
                }
                if (d == INF) break;
                for (int j = 0 ; j < V ; j++) {
                    if (x[j]) lx[j] -= d;
                    if (y[j]) ly[j] += d;
                }
            }
        }
        LL ret = 0; for (int i = 0 ; i < V ; i++)
            if (~my[i]) ret += W[my[i]][i];
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data) {
        cin >> p.F >> p.S;
        p.F--, p.S--;
    }
    KM *sol = new KM(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            sol->W[i][j] = -abs(data[i].F - j) - abs(data[i].S - (j));
        }
    }
    cout << -sol->run() << '\n';
  
}
