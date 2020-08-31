#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, s, m, d, n; cin >> r >> s >> m >> d >> n;
    vector<LL> B(r);
    vector<vector<int>> S(s), M(m), D(d);
    for (auto &v : B) cin >> v;
    for (int i = 0 ; i < s ; i++) {
        int x; cin >> x;
        while (x--) {
            int v; cin >> v; v--;
            S[i].push_back(v);
        }
    }
    for (int i = 0 ; i < m ; i++) {
        int x; cin >> x;
        while (x--) {
            int v; cin >> v; v--;
            M[i].push_back(v);
        }
    }
    for (int i = 0 ; i < d ; i++) {
        int x; cin >> x;
        while (x--) {
            int v; cin >> v; v--;
            D[i].push_back(v);
        }
    }
    vector<vector<int>> ok(s + m + d, vector<int>(s + m + d, 1));
    while (n--) {
        int a, b; cin >> a >> b; a--, b--;
        ok[a][b] = ok[b][a] = 0;
    }
    LL ans = 0; double dans = 0;
    for (int _s = 0 ; _s < s ; _s++) {
        for (int _m = 0 ; _m < m ; _m++) {
            for (int _d = 0 ; _d < d ; _d++) {
                if (!ok[_s][s + _m] || !ok[s + _m][s + m + _d] || !ok[_s][s + m + _d])
                    continue;
                double dsum = 1; LL sum = 1;
                set<int> st;
                for (auto &v : S[_s])
                    st.insert(v);
                for (auto &v : M[_m])
                    st.insert(v);
                for (auto &v : D[_d])
                    st.insert(v);
                for (auto &v : st)
                    dsum *= B[v], sum *= B[v];
                ans += sum, dans += dsum;
                if (dans > 1e18) {
                    cout << "too many\n";
                    exit(0);
                }
            }
        }
    }
    cout << ans << '\n';
}
