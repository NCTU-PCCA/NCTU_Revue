#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    vector<pii> edges(m);
    for (auto &e : edges)
        cin >> e.F >> e.S;
    vector<int> pool1(2e6 + 5);
    for (auto &e : edges)
        pool1[e.F]++, pool1[e.S + 1]--;

    int sum = 0, pre;
    vector<pii> ckpt;
    for (int i = 0 ; i < pool1.size() ; i++) {
        pair<int, int> p = {i, pool1[i]};
        if (sum == 0 && sum + p.S > 0) {
            pre = p.F;
        } else if (sum > 0 && sum + p.S == 0) {
            ckpt.push_back({pre, p.F - 1});
        }
        sum += p.S;
    }

    int base = 0;
    vector<int> neg(2e6 + 5, 0), pos(2e6 + 5, 0);
    for (auto &v : arr) { // point
        for (auto &s : ckpt) { // seg
//            cout << v << ' ' << s.F << ' ' << s.S << '\n';
            if (s.F <= v && v <= s.S) {
//                cout << "ad " << 0 << '\n';
//                cout << "mi " << s.F - v - 1 << '\n';
//                cout << "ad " << s.S - v + 1 << '\n';
                base++;
                neg[abs(s.F - v - 1)]--;
                pos[s.S - v + 1]--;
            } else if (v < s.F) {
//                cout << "ad " << s.F - v << '\n';
//                cout << "mi " << s.S - v + 1 << '\n';
                pos[s.F - v]++;
                pos[s.S - v + 1]--;
            } else if (s.S < v) {
//                cout << "ad " << s.S - v << '\n';
//                cout << "mi " << s.F - v - 1 << '\n';
                neg[abs(s.S - v)]++;
                neg[abs(s.F - v - 1)]--;
            }
        }
    }

    int ans = base, x = 0;
    sum = base;
    for (int i = 1 ; i < neg.size() ; i++) {
        pair<int, int> p = {i, neg[i]};
        sum += p.S;
        if (ans < sum) {
            x = p.F, ans = sum;
        } else if (ans == sum) {
            x = min(x, p.F);
        }
    }
    sum = base;
    for (int i = 1 ; i < pos.size() ; i++) {
        pair<int, int> p = {i, pos[i]};
        sum += p.S;
        if (ans < sum) {
            x = p.F, ans = sum;
        } else if (ans == sum) {
            x = min(x, p.F);
        }
    }
    cout << x << ' ' << ans << '\n';
}
