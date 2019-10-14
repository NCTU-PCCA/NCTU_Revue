// NCTU_Revue
#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const LL p1 = 20190523;
// const LL p2 = 0xdefaced;
typedef pair<LL, LL> pLL;
vector<LL> _data, pre1, pre2, pre1rev, pre2rev;
int n;
LL fpow(LL a, LL n, LL MOD) {
    if (n == 0) return 1;
    LL k = fpow(a, n >> 1, MOD);
    if (n % 2)
        return k * k % MOD * a % MOD;
    else 
        return k * k % MOD;
}
LL query(int l, int r) {   // [l, r)
    LL res1 = ((pre1[r] - pre1[l] + MOD) % MOD) * fpow(fpow(p1, MOD - 2, MOD), l, MOD) % MOD;
    // LL res2 = ((pre2[r] - pre2[l] + MOD) % MOD) * fpow(fpow(p2, MOD - 2, MOD), l, MOD) % MOD;
    int L = n - r;
    int R = n - l;
    l = L; r = R;
    LL res1rev = ((pre1rev[r] - pre1rev[l] + MOD) % MOD) * fpow(fpow(p1, MOD - 2, MOD), l, MOD) % MOD;
    // LL res2rev = ((pre2rev[r] - pre2rev[l] + MOD) % MOD) * fpow(fpow(p2, MOD - 2, MOD), l, MOD) % MOD;
    // return {min(res1, res1rev), min(res2, res2rev)};
    return min(res1, res1rev);
}
unordered_set<LL> st[200005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; _data.clear(); _data.resize(n);
    LL b1 = 1, b2 = 1;
    pre1.push_back(0); pre2.push_back(0);
    for (auto &v : _data) {
        cin >> v;
        pre1.push_back((pre1.back() + b1 * v) % MOD);
//        pre2.push_back((pre2.back() + b2 * v) % MOD);
        b1 *= p1, b1 %= MOD;
//        b2 *= p2, b2 %= MOD;
    }
    reverse(_data.begin(), _data.end());
    pre1rev.push_back(0);
    pre2rev.push_back(0);
    b1 = 1, b2 = 1;
    for (auto &v : _data) {
        pre1rev.push_back((pre1rev.back() + b1 * v) % MOD);
//        pre2rev.push_back((pre2rev.back() + b2 * v) % MOD);
        b1 *= p1, b1 %= MOD;
//        b2 *= p2, b2 %= MOD;
    }
    reverse(_data.begin(), _data.end());
    int maxV = 0, cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = i ; j <= n ; j += i) {
            LL ret = query(j - i, j);
            st[i].insert(ret);
        }
        maxV = max(maxV, (int)st[i].size());
        if (n / i < maxV)
            break;
    }
    cout << maxV << ' ';
    vector<int> ans;
    for (int i = 0 ; i < 200005 ; i++)
        if (st[i].size() == maxV)
            cnt++, ans.push_back(i);
    cout << cnt << '\n';
    for (int i = 0 ; i < cnt ; i++)
        cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
}
