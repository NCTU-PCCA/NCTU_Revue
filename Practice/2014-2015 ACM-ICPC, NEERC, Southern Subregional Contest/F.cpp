#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct ST {
    vector<vector<LL> > data;
    ST(vector<LL> &arr) {
        int n = arr.size();
        int lgN = __lg(n) + 1;
        data.resize(lgN);
        for (int i = 0 ; i < n ; i++)
            data[0].push_back(arr[i]);
        for (int h = 1 ; h < lgN ; h++) {
            int len = 1 << (h - 1), i = 0;
            for (; i + len < n ; i++)
                data[h].push_back(max(data[h - 1][i], data[h - 1][i + len]));
            if (!i)
                break;
            for (; i < n ; i++)
                data[h].push_back(data[h - 1][i]);
        }
    }
    LL query(int l, int r) {
        int h = __lg(r - l);
        int len = 1 << h;
        return max(data[h][l], data[h][r - len]);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> data(n);
    LL sum = 0;
    for (auto &v : data)
        cin >> v, sum += v;
    if (k * 2 >= n)
        cout << sum << '\n';
    else {
        vector<LL> pre;
        LL cur = 0;
        for (int i = 0 ; i < k - 1 ; i++)
            cur += data[i];
        for (int i = k - 1 ; i < n ; i++) {
            cur += data[i];
            pre.push_back(cur);
            cur -= data[i - k + 1];
        }
        ST *sol = new ST(pre);
        LL ans = 0;
        for (int i = 0 ; i + k < n - k + 1 ; i++)
            ans = max(ans, sol->query(0, i + 1) + sol->query(i + k, n - k + 1));
        cout << ans << '\n';
        delete sol;
    }
}
