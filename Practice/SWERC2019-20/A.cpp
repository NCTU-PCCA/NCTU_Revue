#include <bits/stdc++.h>
#define F first
#define S second
#define DEBUG false
using namespace std;
typedef pair<int, int> pii;
const double EPS = 1e-8;
int dist(pii a, pii b) {
    return ceil(sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S))) + EPS;
}
struct Edge {
    int v, c, d;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    pii s, t; cin >> s.F >> s.S >> t.F >> t.S;
    int B; cin >> B;
    int C0; cin >> C0;
    int t_num; cin >> t_num;
    vector<int> T(t_num);
    for (auto &v : T)
        cin >> v;
    int n; cin >> n;
    vector<vector<Edge> > G(n + 2);
    vector<pii> P(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        int x, y; cin >> x >> y;
        P[i] = {x, y};
        int m; cin >> m;
        while (m--) {
            int v, mode; cin >> v >> mode; v++; mode--;
            G[i].push_back({v, T[mode], 0});
            G[v].push_back({i, T[mode], 0});
        }
    }
    for (int u = 1 ; u <= n ; u++) {
        int d = dist(s, P[u]);
        G[0].push_back((Edge){u, C0 * d, d});
        d = dist(P[u], t);
        G[u].push_back((Edge){n + 1, C0 * d, d});
        for (auto &e : G[u]) {
            if (e.v == n + 1)
                continue;
            d = dist(P[u], P[e.v]);
            e.d += d;
            e.c *= d;
        }
    }
    int d = dist(s, t);
    G[0].push_back({n + 1, C0 * d, d});
    if (DEBUG) {
        for (int i =0 ; i < n + 2 ; i++) {
            cout << "G[" << i << "]:";
            for (auto &e : G[i])
                cout << " (" << e.v << ' ' << e.c << ' ' << e.d << ")";
            cout << '\n';
        }
    }

    const int INF = 0x3f3f3f3f;
    int ans = INF;
    queue<pair<int, pii> > q; q.push({0, {0, 0}});
    vector<set<pii> > cur(n + 2);
    while (q.size()) {
        auto p = q.front(); q.pop();
        int u = p.F, d = p.S.F, c = p.S.S;

        bool legal = true;
        for (auto &S : cur[u]) {
            if (S.F <= d && S.S <= c)
                legal = false;
        }
        if (!legal)
            continue;
        set<pii> newSet;
        for (auto &S : cur[u]) {
            if (S.F >= d && S.S >= c)
                continue;
            newSet.insert(S);
        }
        newSet.insert({d, c});
        cur[u] = newSet;


        for(auto &e : G[u]) {
            if (e.d + d > B)
                continue;
            if (e.v == n + 1)
                ans = min(ans, c + e.c);
            q.push({e.v, {e.d + d, e.c + c}});
        }
    }
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
