#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> data(m);
    for (auto &v : data)
        cin >> v, v--;
    vector<int> rank(n);
    vector<int> list(n);
    for (int i = 0 ; i < n ; i++)
        list[i] = i, rank[i] = i;
    vector<pii> ans(n);
    for (int i = 0 ; i < n ; i++) {
        ans[i].F = ans[i].S = i;
    }
    for (auto &v : data) {
        int x = rank[v];
        if (x == 0) continue;
        swap(list[x], list[x - 1]);
        int x1 = list[x - 1];
        int x2 = list[x];
        swap(rank[x1], rank[x2]);
        ans[x1].F = min(ans[x1].F, x - 1);
        ans[x2].S = max(ans[x2].S, x);
    }   
    for (auto &p : ans)
        cout << p.F + 1 << ' ' << p.S + 1 << '\n';

}
