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
    int n; cin >> n;
    vector<LL> data(n);
    for (int i = 0 ; i < n ; i++) {
        LL u, v; cin >> u >> v;
        data[i] = min(u, v);
        data[i] *= 2;
    }
    data.push_back(0);
    sort(data.begin(), data.end());
    LL L; cin >> L; L *= 2; LL sum = 0;
    if (data[1] >= L) {
        cout << 1 << '\n';
        exit(0);
    }
    for (int i = 1 ; i <= n ; i++) {
        sum += data[i];
        if (sum - (data[i] + data[i - 1]) / 2 >= L) {
            cout << i - 1 << '\n';
            exit(0);
        }
    }
    cout << n << '\n';
}
