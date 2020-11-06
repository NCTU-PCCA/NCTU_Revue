#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> e(n), c(n);
    for (auto &v : e)
        cin >> v;
    for (auto &v : c)
        cin >> v;
    LL maxV = max(0LL, e[n - 1] - c[n - 1]);
    if (k == 0) {
        LL sum = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            sum += e[i];
            maxV = max(maxV, sum - c[i]);
        }
    } else if (k >= 2) {
        LL sum = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            sum += e[i];
            maxV = max(maxV, sum - c[i]);
        }
        LL minV = INF;
        for (int i = n - 2 ; i >= 0 ; i--)
            minV = min(minV, c[i]);
        maxV = max(maxV, sum - minV);
    } else {

        {   // cycle and suffix
            LL tot = 0;
            for (int i = 0 ; i < n ; i++)
                tot += e[i];
            vector<LL> premin(n, INF);
            premin[0] = c[0];
            for (int i = 1 ; i < n ; i++)
                premin[i] = min(premin[i - 1], c[i]);
            LL sum = 0;
            for (int i = n - 1 ; i >= 2 ; i--) {
                sum += e[i];
                maxV = max(maxV, max(0LL, tot - sum - premin[i - 1]) + max(0LL, sum - c[i]));
            }
        }
        {   // cycle and single
            LL sum = 0; LL minV = INF;
            for (int i = 0 ; i < n - 1 ; i++) {
                sum += e[i];
                minV = min(minV, c[i]);
            }
            LL ans = max(sum - minV, 0LL);
            if (c[n - 1] < e[n - 1])
                ans += e[n - 1] - c[n - 1];
            maxV = max(maxV, ans);
        }
        {   // suffix [1, n)
            LL sum = 0;
            for (int i = n - 1 ; i >= 1 ; i--) {
                sum += e[i];
                maxV = max(maxV, sum - c[i]);
            }
        }
        {   // start from zero and skip one node
            LL sum = 0;
            for (int i = 0 ; i < n ; i++)
                sum += e[i];
            for (int i = 1 ; i < n - 1 ; i++)
                maxV = max(maxV, sum - e[i] - c[0] + max(0LL, e[i] - c[i]));
        }

        /*
        LL sum = 0, minE = INF, minC = INF;
        for (int i = n - 1 ; i >= 0 ; i--) {
            sum += e[i];
            if (i < 1) {
                maxV = max(maxV, sum - min(minC, minE) - c[i]);
            } else {
                maxV = max(maxV, sum - c[i]);
            }
            minE = min(minE, e[i]);
            minC = min(minC, c[i]);
        }
        */
    }
    cout << maxV << '\n';
}

