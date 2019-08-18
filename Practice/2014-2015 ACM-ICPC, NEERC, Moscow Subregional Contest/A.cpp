#include <bits/stdc++.h>
using namespace std;
void trans(vector<vector<int> > &G) {
    vector<vector<int> > ret(G.size(), vector<int>(G.size()));
    for (int i = 0 ; i < (int)G.size() ; i++)
        for (int j = 0 ; j < (int)G.size() ; j++)
            ret[G.size() - 1 - j][i] = G[i][j];
    G = ret;
}
vector<int> trim(vector<int> &x, int &score) {
    queue<int> q; for (auto &v : x) q.push(v);
    bool canMerge = true;
    vector<int> ret;
    while (q.size()) {
        int p = q.front(); q.pop();
        if (!p) continue;
        if (ret.size() && ret.back() == p && canMerge) {
            canMerge = false;
            ret.back() += p;
            score += ret.back();
        } else {
            ret.push_back(p);
            canMerge = true;
        }
    }
    ret.resize(x.size(), 0);
    return ret;
}
int OP(vector<vector<int> > &G, string &op) {
    int ret = 0;
    if (op == "U") {
        trans(G);
        for (int i = 0 ; i < G.size() ; i++)
            G[i] = trim(G[i], ret);
        trans(G);
        trans(G);
        trans(G);
    } else if (op == "D") {
        trans(G);
        trans(G);
        trans(G);
        for (int i = 0 ; i < G.size() ; i++)
            G[i] = trim(G[i], ret);
        trans(G);
    } else if (op == "L") {
        for (int i = 0 ; i < G.size() ; i++)
            G[i] = trim(G[i], ret);
    } else {
        trans(G);
        trans(G);
        for (int i = 0 ; i < G.size() ; i++)
            G[i] = trim(G[i], ret);
        trans(G);
        trans(G);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int> > G(n, vector<int>(n, 0));
    while (k--) {
        int v, x, y; cin >> v >> x >> y; x--, y--;
        G[x][y] = v;
    }
    int ans = 0;
    int q; cin >> q; while (q--) {
        string op; int v, x, y; cin >> op >> v >> x >> y; x--, y--;
        ans += OP(G, op);
        G[x][y] = v;
    }
    cout << ans << '\n';
}
