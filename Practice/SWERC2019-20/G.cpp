#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int s, l, n; cin >> s >> l >> n;
    vector<string> idx2str;
    map<string, int> str2idx;
    for (int i = 0 ; i < s ; i++) {
        string s; cin >> s;
        idx2str.push_back(s);
    }
    sort(idx2str.begin(), idx2str.end());
    for (int i = 0 ; i < s ; i++)
        str2idx[idx2str[i]] = i;
    vector<set<int> > limit(s);
    while (l--) {
        string stru, strv; cin >> stru >> strv;
        int u = str2idx[stru];
        int v = str2idx[strv];
        limit[u].insert(v);
        limit[v].insert(u);
    }
    vector<int> cur(s, 0);
    vector<vector<int> > G(n + 1);
    vector<int> deg(n + 1, 0);
    vector<int> data(n + 1, -1);
    for (int i = 1 ; i <= n ; i++) {
        string strx; cin >> strx;
        int x = str2idx[strx];
        data[i] = x;
        for (int j = 0 ; j < s ; j++) {
            if (j == x || limit[x].count(j))
                continue;
            G[cur[j]].push_back(i);
            deg[i]++;
        }
        cur[x] = i;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0 ; i <= n ; i++) {
        if (deg[i] == 0)
            pq.push({data[i], i});
    }
    while (pq.size()) {
        pii p = pq.top(); pq.pop();
        if (p.F != -1)
            cout << idx2str[p.F] << ' ';
        for (auto &v : G[p.S]) {
            deg[v]--;
            if (deg[v] == 0)
                pq.push({data[v], v});
        }
    }
    cout << '\n';
}
