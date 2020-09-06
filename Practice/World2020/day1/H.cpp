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
const int maxn = 1000005;
int cnt[maxn];
ll ans[maxn];
void go() {
    int n, m;
    cin >> n >> m;
    f1(n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    f1(1000000) {
        for (int j = 1 ; j * i <= 1000000 ; j++) {
            ans[i] += (ll)j * cnt[j*i];
        }
    }
    ll sum = 0;
    f(m) {
        int x;
        cin >> x;
        sum += ans[x];
    }
    cout << sum << '\n';
}
int main() {
    freopen("halloween.in","r",stdin);
    freopen("halloween.out","w",stdout);
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
