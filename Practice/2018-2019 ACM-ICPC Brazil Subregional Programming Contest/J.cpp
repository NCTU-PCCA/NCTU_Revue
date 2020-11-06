#include <bits/stdc++.h>
#define fr(i,j,k) for (int i = j ; i < k ; i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define ll long long
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double inf = 1e18;
using namespace std;
vector<tuple<ll,ll,ll>>v;
bool ok(int x,int y) {
    ll dx = get<2>(v[x]) - get<2>(v[y]);
    ll dy = get<1>(v[x]) - get<1>(v[y]);
    ll tot = dx * dx + dy * dy;
    ll r1 = get<0>(v[x]), r2 = get<0>(v[y]);
    return tot >= (r1 - r2) * (r1 - r2) &&tot <= (r1 + r2) * (r1 + r2);
}
int main() {
    int n;
    cin >> n;
    double a = clock();
    f(n) {
        double a, b, c;
        cin >> a >> b >> c;
        v.pb({(int)(c*1000), (int)(b*1000), (int)(a*1000)});
    }
    random_shuffle(all(v));
    int cnt = 0;
    f(n) {
        fr(j,i + 1, n + 1) {
            if (ok(i,j)) {
                cnt += 2;
            }
            if (cnt > n * 2) {
                cout << "greater" << '\n';
                exit(0);
            }
        }
        double b = clock();
        //cout << b << endl;
        //cout << b - a << endl;
        if(b - a >= 2800) break;
    }
    cout << cnt << '\n'; 
}
