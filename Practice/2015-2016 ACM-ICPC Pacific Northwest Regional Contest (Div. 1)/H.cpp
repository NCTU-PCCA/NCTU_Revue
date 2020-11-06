#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
void solve(auto &arr, LL S) {
    if (arr.size() <= 1) return ;
    vector<vector<pair<pii, int>>> pool(4);
    for (auto &p : arr) {
        if (p.F.F * 2 < S && p.F.S * 2 < S)
            pool[0].push_back({{p.F.S * 2, p.F.F * 2}, p.S});
        else if (p.F.F * 2 < S && p.F.S * 2 >= S)
            pool[1].push_back({{p.F.F * 2, p.F.S * 2 - S}, p.S});
        else if (p.F.F * 2 >= S && p.F.S * 2 < S)
            pool[3].push_back({{S - p.F.S * 2, 2 * S - p.F.F * 2}, p.S});
        else
            pool[2].push_back({{p.F.F * 2 - S, p.F.S * 2 - S}, p.S});
    }
    solve(pool[0], S);
    solve(pool[1], S);
    solve(pool[2], S);
    solve(pool[3], S);
    arr.clear();
    for (int i = 0 ; i < 4 ; i++)
        for (auto &p : pool[i])
            arr.push_back(p);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL S; cin >> n >> S;
    vector<pair<pii, int>> arr(n);
    vector<string> idx;
    int st = 0;
    for (auto &p : arr) {
        cin >> p.F.F >> p.F.S; p.S = st++;
        string s; cin >> s; idx.push_back(s);
    }
    solve(arr, S);
    for (auto &p : arr)
        cout << idx[p.S] << '\n';
}
