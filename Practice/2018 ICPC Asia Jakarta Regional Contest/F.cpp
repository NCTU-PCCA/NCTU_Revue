#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL m; cin >> n >> m;
    vector<LL> A(n), B(n);
    vector<LL> preA{0}, preB{0};
    for (auto &v : A) cin >> v, preA.push_back(preA.back() + v);
    for (auto &v : B) cin >> v, preB.push_back(preB.back() + v);
    priority_queue<pii> pq;
    vector<LL> cnt(n, 0);
    LL sum = 0; int idx = -1;
    for (int i = 0 ; i < n ; i++) {
        if (sum + A[i] > m)
            break;
        idx = i;
        sum += A[i];
    }
    int ptr = idx;
    for (int i = idx ; i >= 0 ; i--) {
        while (ptr >= 0 && preB[ptr + 1] >= preA[i + 1])
            pq.push({B[ptr], ptr}), ptr--;
        if (pq.size() != 0)
            cnt[pq.top().second]++;
    }
    vector<LL> ans;
    LL cur = 0;
    for (int i = 0 ; i < n ; i++) {
        cur += B[i];
        LL c = cnt[i];
        while (c >= 1) {
            if (cur <= m)
                ans.push_back(cur);
            cur += B[i];
            c--;
        }
    }
    int Bs = 0; cur = 0;
    for (int i = 0 ; i < n ; i++) {
        cur += B[i] * (cnt[i] + 1);
        if (cur > m) break;
        Bs++;
    }
    if (Bs >= idx + 1)
        cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for (int i = 0 ; i < (int)ans.size() ;i++)
            cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    }
}
