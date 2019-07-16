#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void mR(vector<LL> &x) {
    int n = (int)x.size();
    vector<LL> tar;
    for (auto &v : x)
        tar.push_back(v);
    for (auto &v : x)
        tar.push_back(v);
    int i = 0, j = 1;
    while (i < n && j < n) {
        int k = 0;
        while (k < n && tar[i + k] == tar[j + k])
            k++;
        if (tar[i + k] <= tar[j + k])
            j += k + 1;
        else
            i += k + 1;
        if (i == j)
            j++;
    }
    int ans = i < n ? i : j;
    x.clear();
    for (int i = 0 ; i < n ; i++)
        x.push_back(tar[i + ans]);
}
const LL MOD = 1e9 + 7;
const LL BAS1 = 0xdefaced;
const LL BAS2 = 616069;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n; LL sum = 0; cin >> n;
        vector<vector<LL> > data(4, vector<LL>(n));
        for (auto &vv : data)
            for (auto &v : vv)
                cin >> v, sum += v;
        if (sum % n) {
            cout << "No\n";
            continue;
        }
        LL res = sum / n;
        unordered_set<int> s1;
        bool ok = false;
        for (int i = 0 ; i < n ; i++) {
            vector<LL> cur;
            for (int j = 0 ; j < n ; j++)
                cur.push_back(data[0][j] + data[1][(i + j) % n]);
            mR(cur);
            LL sum1 = 0;
            for (auto &v : cur)
                sum1 *= BAS1, sum1 %= MOD, sum1 += v, sum1 %= MOD;
            s1.insert(sum1);
        }
        for (int i = 0 ; i < n ; i++) {
            vector<LL> cur;
            for (int j = 0 ; j < n ; j++)
                cur.push_back(res - data[2][j] - data[3][(i + j) % n]);
            mR(cur);
            LL sum1 = 0;
            for (auto &v : cur)
                sum1 *= BAS1, sum1 %= MOD, sum1 += v, sum1 %= MOD;
            if (s1.count(sum1))
                ok = true;
            if (ok)
                break;
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
