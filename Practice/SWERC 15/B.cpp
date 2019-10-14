#include <bits/stdc++.h>
using namespace std;
struct Q {
    string s; int player, cnt;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<Q> data(n);
    for (auto &v : data)
        cin >> v.s >> v.player >> v.cnt;
    int cnt = 0;
    for (char i = 'A' ; i <= 'Z' ; i++) {
        for (char j = i + 1 ; j <= 'Z' ; j++) {
            for (char k = j + 1 ; k <= 'Z' ; k++) {
                bool ok = true;
                vector<int> vis(26, -1);
                vector<vector<int> > G(26);
                set<char> app;
                app.insert(i);
                app.insert(j);
                app.insert(k);
                for (auto &q : data) {
                    if (app.count(q.s[0]) && app.count(q.s[1])) {       // 都是非法
                        if (q.cnt != 0) {
                            ok = false;
                            break;
                        }
                    } else if (app.count(q.s[0])) { // s[0]是非法
                        if (q.cnt == 0) {
                            if (vis[q.s[1] - 'A'] == q.player)
                                ok = false;
                            else
                                vis[q.s[1] - 'A'] = 3 - q.player;
                        } else if (q.cnt == 1) {
                            if (vis[q.s[1] - 'A'] == 3 - q.player)
                                ok = false;
                            else
                                vis[q.s[1] - 'A'] = q.player;
                        } else if (q.cnt == 2)
                            ok = false;
                    } else if (app.count(q.s[1])) {
                        if (q.cnt == 0) {
                            if (vis[q.s[0] - 'A'] == q.player)
                                ok = false;
                            else
                                vis[q.s[0] - 'A'] = 3 - q.player;
                        } else if (q.cnt == 1) {
                            if (vis[q.s[0] - 'A'] == 3 - q.player)
                                ok = false;
                            else
                                vis[q.s[0] - 'A'] = q.player;
                        } else if (q.cnt == 2)
                            ok = false;
                    } else {
                        if (q.cnt == 0) {
                            if (vis[q.s[0] - 'A'] == q.player)
                                ok = false;
                            else
                                vis[q.s[0] - 'A'] = 3 - q.player;
                            if (vis[q.s[1] - 'A'] == q.player)
                                ok = false;
                            else
                                vis[q.s[1] - 'A'] = 3 - q.player;
                        } else if (q.cnt == 1) {
                            G[q.s[0] - 'A'].push_back(q.s[1] - 'A');
                            G[q.s[1] - 'A'].push_back(q.s[0] - 'A');
                        } else {
                            if (vis[q.s[0] - 'A'] == 3 - q.player)
                                ok = false;
                            else
                                vis[q.s[0] - 'A'] = q.player;
                            if (vis[q.s[1] - 'A'] == 3 - q.player)
                                ok = false;
                            else
                                vis[q.s[1] - 'A'] = q.player;
                        }
                    }
                }
                if (!ok) continue;
                vector<bool> check(26, false);
                check[i - 'A'] = check[j - 'A'] = check[k - 'A'] = true;
                for (int i = 0 ; i < 26 ; i++) {
                    if (check[i]) continue;
                    if (vis[i] == -1) continue;
                    check[i] = true;
                    queue<int> q; q.push(i);
                    while (q.size()) {
                        int p = q.front(); q.pop();
                        for (auto &v : G[p]) {
                            if (vis[v] == -1) {
                                 check[v] = true;
                                 vis[v] = 3 - vis[p];
                                 q.push(v);
                            } else if (vis[v] == vis[p]) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                            break;
                    }
                    if (!ok)
                        break;
                }
                if (!ok) continue;
                for (int i = 0 ; i < 26 ; i++) {
                    if (check[i]) continue;
                    vis[i] = 1; check[i] = true;
                    queue<int> q; q.push(i); while (q.size()) {
                        int p = q.front(); q.pop();
                        for (auto &v : G[p]) {
                            if (vis[v] == -1) {
                                check[v] = true;
                                vis[v] = 3 - vis[p];
                                q.push(v);
                            } else if (vis[v] == vis[p]) {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                            break;
                    }
                    if (!ok)
                        break;
                }
                if (ok) { 
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}
