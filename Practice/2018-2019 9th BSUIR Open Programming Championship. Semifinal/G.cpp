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
const int mod = 1e9+7;
const int maxn = 200005;
 
void go() {
    int n;
    long double a, b;
    cin >> n >> a >> b;
    vector<pair<long double,long double>>v(n+1);
    n++; 
    v[0] = {0,0};
    for (int i = 1 ; i < n ; i++) {
        cin >> v[i].F >> v[i].S;
    }
    
    for (int i = n - 2 ; i >= 0 ; i--) {
        long double x = (v[i + 1].F - v[i].F); 
        long double t = (-2 * v[i + 1].S + sqrt(4 * v[i + 1].S * v[i + 1].S + 8 * b * x)) / (2 * b);
        v[i].S = min(v[i].S, v[i + 1].S + t * b);
    }
    long double ts = 0;;
    long double ans = 0;
    for (int i = 1 ; i < n ; i++) {
        long double x = v[i].F - v[i - 1].F;
        long double t = (-2 * ts + sqrt(4 * ts * ts + 8 * a * x)) / (2 * a);
        long double newspeed = ts + a * t;
        
        if (newspeed <= v[i].S) {
            ans += t;
            ts = newspeed;
        }
        else {
            long double r = x, l = 0;
            int times = 200;
            long double add = -1;
            while (times--) {
                long double mid = (l + r) / 2.0;
                long double t = (-2 * ts + sqrt (4 * ts * ts + 8 * a * mid) ) / (2 * a);
                long double maxspeed = ts + a * t;
                long double t2 = (maxspeed - v[i].S) / b;
                long double x2 = (maxspeed + v[i].S) * t2 / 2.0;
                if (t2 < 0 || x2 + mid >= x) {
                    r = mid;
                }
                else {
                    l = mid;
                    add = t2 + t;
                }
            }
            ts = v[i].S;
            if (add == -1) {
                long double maxspeed = ts;
                long double t2 = (maxspeed - v[i].S) / b;
                add = t2;
            }
            ans += add;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
int main() {
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
