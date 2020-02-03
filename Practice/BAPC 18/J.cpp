#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1);
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long double a, b, c, d; cin >> a >> b >> c >> d;
    long double s = (a + b + c + d) / 2.0;
    cout << fixed << setprecision(20) << sqrt((s - a) * (s - b) * (s - c) * (s - d)) << '\n';
    
}
