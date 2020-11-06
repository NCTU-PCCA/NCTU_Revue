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
const int mod = 998244353;
const int maxn = 300005;

void go() {
    int n, m, k;
    cin >> n >> m >> k;
    if (!n) {
        exit(0);
    }
    vector<pair<string,string>>v;
    f(k) {
        string s1, s2;
        cin >> s1 >> s2;
        v.pb({s1,s2});
    }
    for (int i = 0 ; i < m ; i++) {
        int c[n] = {};
        char last = '0';
        for (int j = 0 ; j < k ; j++) {
            if (v[j].S[i] != last) {
                for (int z = 0 ; z < n ; z++) {
                    if (v[j].F[z] == '0') {
                        c[z] = 1;
                    }
                }
            }
            else {
                for (int z = 0 ; z < n ; z++) {
                    if (v[j].F[z] == '1') {
                        c[z] = 1;
                    }
                }
            }
            last = v[j].S[i];
        }
        int cnt = 0;
        int ans;
        fr(j,0,n) {
            if (!c[j]) {
                cnt++;
                ans = j;
            }
        }
        //cout << cnt <<' '<< ans << endl;
        if (cnt == 1) {
            if (ans < 10) {
                cout << char('0' + ans);
            }
            else {
                cout << char('A' + ans - 10);
            }
        }
        else {
            cout << '?';
        }
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = mod;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}
