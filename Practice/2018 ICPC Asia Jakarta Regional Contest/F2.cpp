#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; LL m; cin >> n >> m;
    vector<LL> A(n), B(n), preA{0}, preB{0};
    for (auto &v : A) cin >> v, preA.push_back(preA.back() + v);
    for (auto &v : B) cin >> v, preB.push_back(preB.back() + v);
    LL cur = 0; int idx = -1;
    for (int i = 0 ; i < n ; i++) {
        if (cur + A[i] > m)
            break;
        idx = i;
        cur += A[i];
    }
    vector<pLL> stk;
    for (int i = idx ; i >= 0 ; i--) {
        if (stk.size() == 0)
            stk.push_back({B[i], i});
        else if (stk.back().first < B[i])
            stk.push_back({B[i], i});
    }
    vector<LL> cnt(n, 0);
    LL curA = 0, cntB = 0;
    for (int i = 0 ; i <= idx ; i++) {
        curA += A[i];
        while (stk.size() && preB[stk.back().second + 1] + cntB < curA)
            stk.pop_back();
        if (stk.size() == 0)
            break;
        cnt[stk.back().second]++;
        cntB += B[stk.back().second];
    }
    LL curB = 0;
    vector<LL> ans;
    for (int i = 0 ; i < n ; i++) {
        curB += B[i];
        int c = cnt[i];
        while (c > 0) {
            if (curB <= m)
                ans.push_back(curB);
            curB += B[i];
            c--;
        }
    }
    int Bs = 0; curB = 0;
    for (int i = 0 ; i < n ; i++) {
        curB += B[i] * (cnt[i] + 1);
        if (curB > m)
            break;
        Bs++;
    }
    if (Bs >= idx + 1) {
        cout << -1 << '\n';
    } else {
        cout << ans.size() << '\n';
        for (int i = 0 ; i < (int)ans.size() ; i++)
            cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    }

}
