#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
struct BIT {
    vector<LL> bit; int n;
    void init(int _n) { n = _n;
        bit.assign(n + 1, 0);
    }
    void m(int x, LL d) {
        while (x <= n)
            bit[x] += d, x += x & -x;
    }
    LL q(int x) {
        LL ret = 0;
        while (x > 0)
            ret += bit[x], x -= x & -x;
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; LL L, R; cin >> n >> m >> L >> R;
    L *= L, R *= R; 
    BIT cnt; cnt.init(1e5 + 5);
    BIT sum; sum.init(1e5 + 5);
    for (int i = 1 ; i <= 1e5 ; i++)
        cnt.m(i, 1), sum.m(i, i);
    for (
}
