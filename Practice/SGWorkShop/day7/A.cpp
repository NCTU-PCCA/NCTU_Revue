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
    int n, q; cin >> n >> q;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    vector<int> C(n);
    bool haveOne = false;
    for (auto &v : C) {
        cin >> v;
        if (v == 1)
            haveOne = true;
    }
    for (int i = 0 ; i < q ; i++) {
        int v; cin >> v;
        if (v < 0) {
            cout << "NO\n";
            continue;
        }
        if (haveOne) {
            if (v == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        } else {
            if (v == 0 || v % 2)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}
