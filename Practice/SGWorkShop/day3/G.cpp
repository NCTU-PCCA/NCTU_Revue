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
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<bool> ok(n - 1, false);
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        if (u == v) continue;
        if (u < v && u + 1 == v) 
            ok[u] = true;
        if (u > v) {
            cout << "No\n";
            exit(0);
        }
    }
    bool legal = true;
    for (int i = 0 ; i < n - 1 ; i++)
        legal = legal && ok[i];
    if (legal)
        cout << "Yes\n";
    else
        cout << "No\n";

}
