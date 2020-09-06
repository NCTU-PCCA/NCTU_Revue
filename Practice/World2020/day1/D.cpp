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
vector<int>g[maxn];
void solve(int x) {
    if (x == 1&&g[x].size() >= 3) {
        cout << "Epic fail\n";
        exit(0);
    }
    int mi = (x+1)/2 + 1;
    for (int i = 1 ; i < (x + 1) / 2; i++) {
        if (g[i].size()) {
            cout << "Epic fail\n";
            exit(0);
        }
    }
    //if (x % 2) {
        vector<int>tar, tar2;
        for (int i = x ; i > x / 2; i--) {
            if (g[i].size() < 2) {
                cout << "Epic fail\n";
                exit(0);
            }
            tar.pb(g[i].back());
            g[i].pop_back();
            tar2.pb(g[i].back());
            g[i].pop_back();
        }
        if (x % 2 == 0 && g[x/2].size() != 1) {
            cout << "Epic fail\n";
            exit(0);
        }
        else if (x % 2 == 0){
            tar.pb(g[x/2][0]);
            g[x/2].clear();
        }
        else if (x % 2 == 1 && g[(x+1)/2].size()) {
            cout << "Epic fail\n";
            exit(0);  
        } 
        reverse(all(tar2));
        cout << "I got it\n";
        int last = tar[0];
        for (int i = 1 ; i < tar.size() ; i++) {
            cout << last <<' '<<tar[i] << '\n';
            last = tar[i];
        }
        for (auto &i : tar2) {
            cout << last  <<' ' << i << '\n';
            last = i;
        }
        for (int i = 0 ; i <= x ; i++) {
            if (g[i].size()) {
                for (auto &j : g[i]) {
                    int zz = x - i + 1;
                    cout << j <<' '<<tar[zz] <<'\n';
                }
            }
        }
    //}
}
void go() {
    int n;
    cin >> n;
    f1(n) {
        int x;
        cin >> x;
        g[x].pb(i);
    }
    for (int i = n ; i >= 1 ; i--) {
        if (g[i].size()) {
            solve(i);
            break;
        }
    }
}
int main() {
    freopen("decode.in","r",stdin);
    freopen("decode.out","w",stdout);
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
