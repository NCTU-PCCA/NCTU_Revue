#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct SW {
    static const int MAXN = 205;
    int n, vst[MAXN];
    LL del[MAXN], edge[MAXN][MAXN], wei[MAXN];
    void init(int _n) { n = _n;
        memset(edge, 0, sizeof(edge));
        memset(del, 0, sizeof(del));
    }
    void addEdge(int u, int v, LL w) {
        edge[u][v] += w; edge[v][u] += w;
    }
    void search(int &s, int &t) {
        memset(vst, 0, sizeof(vst));
        memset(wei, 0, sizeof(wei));
        s = t = -1;
        while (1) { int mx = -1, cur = 0;
            for (int i = 0 ; i < n ; i++)
                if (!del[i] && !vst[i] && mx < wei[i])
                    cur = i, mx = wei[i];
            if (mx == -1) break;
            vst[cur] = 1; s = t; t = cur;
            for (int i = 0 ; i < n ; i++)
                if (!vst[i] && !del[i])
                    wei[i] += edge[cur][i];
        }
    }
    LL solve() { LL res = INF;
        for (int i = 0, x, y; i < n - 1 ; i++) {
            search(x, y); res = min(res, wei[y]);
            del[y] = 1;
            for (int j = 0 ; j < n ; j++)
                edge[x][j] = (edge[j][x] += edge[y][j]);
        }
        return res;
    }
} graph;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    graph.init(n * 2);
    for (int i = 0 ; i < n ; i++)
        graph.addEdge(i, i + n, 1);
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        v += n;
        graph.addEdge(u, v, INF);
    }
    cout << graph.solve() << '\n';


}
