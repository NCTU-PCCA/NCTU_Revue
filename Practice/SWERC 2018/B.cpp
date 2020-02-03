#include <bits/stdc++.h>
using namespace std;
struct ST {
    vector<vector<int> > data;
    int (*op)(int a, int b);
    ST(vector<int> &arr, int (*_op)(int a, int b)) {
        op = _op;
        int n = arr.size(), lgN = __lg(n) + 1;
        data.resize(lgN);
        for (int i = 0 ; i < n ; i++)
            data[0].push_back(arr[i]);
        for (int h = 1 ; h < lgN ; h++) {
            int len = 1 << (h - 1), i = 0;
            for (; i + len < n ; i++)
                data[h].push_back(op(data[h - 1][i], data[h - 1][i + len]));
            if (!i) break;
            for (; i < n ; i++)
                data[h].push_back(data[h - 1][i]);
        }
    }
    int query(int l, int r) {
        int h = __lg(r - l), len = 1 << h;
        return op(data[h][l], data[h][r - len]);
    }
};
int getMin(int a, int b) {
    return min(a, b);
}
int getMax(int a, int b) {
    return max(a, b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> _L, _R;
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int l, r; cin >> l >> r; r++;
        _L.push_back(l);
        _R.push_back(r);
    }
    ST *L = new ST(_L, getMax);
    ST *R = new ST(_R, getMin);
    int l = 0, r = n + 1; while (r - l > 1) {
        int m = (l + r) >> 1;
        bool ok = false;
        for (int i = 0 ; i + m <= n ; i++) {
            int left = L->query(i, i + m);
            int right = R->query(i, i + m);
            if (right - left >= m) {
                ok = true;
                break;
            }
        }
        if (ok)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
}
