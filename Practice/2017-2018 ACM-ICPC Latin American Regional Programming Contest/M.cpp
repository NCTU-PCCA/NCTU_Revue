#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
using VI = vector<int>;
#define NX(x) ((x + k) % n)
#define C(a,b) (V[a] == V[b] ? V[NX(a)] < V[NX(b)] : V[a] < V[b])
#define go(XD) V2[sa[0]] = N = 0; \
    for (int i = 1 ; i < n ; i++) N += XD, V2[sa[i]] = N; V = V2;
#define RSP sa, n, N + 1
void RS(auto &sa, int n, int N, auto &V) {
    VI B(N), t(n); for (auto &v : sa) B[V[v]]++;
    partial_sum(ALL(B), B.begin()); int i = n;
    while (i--) t[--B[V[sa[i]]]] = sa[i]; sa = t;
}
VI SA(vector<int> &s) { int n = s.size(), k = 0, N = 305;
    VI sa(n), V(n), V2(n); iota(ALL(sa), 0);
    RS(RSP, s); go(s[sa[i - 1]] != s[sa[i]]);
    for (int k = 1 ; N + 1 < n ; k <<= 1, k %= n) {
        for (auto &v : sa) (v += n - k) %= n; RS(RSP, V);
        go(C(sa[i - 1], sa[i]) || C(sa[i], sa[i - 1]));
    } return sa;
}
const LL MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    vector<int> top(n, -1);
    for (int i = 0 ; i < n ; i++) {
        top[i] = v.size();
        int m; cin >> m;
        while (m--) {
            int x; cin >> x;
            v.push_back(x);
        }
        v.push_back(302);
    }
    VI sa = SA(v);
    VI ra(v.size());
    for (int i = 0 ; i < v.size() ; i++)
        ra[sa[i]] = i;
    /*
    for (int i = 0 ; i < sa.size() ; i++) {
        for (int j = sa[i] ; j < v.size() ; j++) {
            if (v[j] == 302)
                break;
            cout << v[j] << ' ';
        }
        cout << '\n';
    }
    */
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    /*
    for (auto &c : v)
        cout << c << ' ';
    cout << '\n';
    */
    for (int i = 0 ; i < n ; i++) {
        // cout << "SA " << top[i] << '\n';
        pq.push({ra[top[i]], i});
    }
    LL ans = 0;
    while (pq.size()) {
        pii p = pq.top(); pq.pop();
        // cout << "get " << v[top[p.S]] << '\n';
        int i = p.S;
        ans += v[top[i]]; ans %= MOD;
        ans *= 365; ans %= MOD;
        top[i]++;
        if (v[top[i]] != 302)
            pq.push({ra[top[i]], i});
    }
    cout << ans << '\n';
}
