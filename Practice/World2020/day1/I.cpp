#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 500005;

void go() {
    int n, m;
    cin >> n >> m;
    vector<ll>v[m];
    f1(n) {
        fr(j,0,m) {
            int x;
            cin >> x;
            v[j].pb(x);
        }
    }
    f(m) {
        sort(all(v[i]));
    }
    ll sum = 0;
    ll pro = 0;
    f(m) {
        sum += v[i][0];
        if(v[i].size() == 1) {
            pro = max(pro,v[i][0]);
        }
        else {
            pro = max(pro, min(v[i][0] * 2,v[i][1]) - v[i][0]);
        }
    }
    cout << sum + pro << '\n';
}
int main() {
    freopen("intelligent.in","r",stdin);
    freopen("intelligent.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
