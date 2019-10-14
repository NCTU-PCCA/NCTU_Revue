#include <bits/stdc++.h>
using namespace std;
struct Q {
    int l, r, sum;
    bool operator < (const Q &rhs) const {
        if (r == rhs.r)
            return l < rhs.l;
        else
            return r < rhs.r;
    }
};
struct BIT {
    vector<int> d; int n;
    BIT(int n) : n(n) { d.resize(n + 1, 0); }
    void _(int &x, int v) { x += v * (x & -x); }
    int Q(int x) {
        int ret = 0;
        while (x > 0) ret += d[x], _(x, -1);
        return ret;
    }
    void M(int x, int v) {
        while (x <= n) d[x] += v, _(x, 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> data(n + 1, 0);
    set<int> pool;
    BIT *sol = new BIT(n);
    for (int i = 1 ; i <= n ; i++) {
        cin >> data[i];
        if (data[i] == 0) {
            data[i] = -1;
            pool.insert(i);
        }
        sol->M(i, data[i]);
    }
    vector<Q> qs(m);
    for (auto &_q : qs)
        cin >> _q.l >> _q.r >> _q.sum;
    sort(qs.begin(), qs.end());
    for (auto &q : qs) {
        int ret = sol->Q(q.r) - sol->Q(q.l - 1);
        if (ret >= q.sum)
            continue;
        while (ret < q.sum) {
            auto it = pool.upper_bound(q.r);
            if (it == pool.begin()) {
                cout << "Impossible\n";
                return 0;
            }
            it--;
            sol->M(*it, 2);
            data[*it] = 1;
            pool.erase(it);
            ret += 2;
        }
    }
    for (int i = 1 ; i <= n ; i++)
        cout << data[i] << " \n"[i == n];
    delete sol;
}
