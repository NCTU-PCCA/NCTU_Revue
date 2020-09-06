#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
map<LL, LL> mp;
vector<LL> Prime;
vector<bool> isPrime;
void build() {
    isPrime.assign(4e4 + 5, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2 ; i < 4e4 + 5 ; i++) {
        if (isPrime[i]) {
            Prime.push_back(i);
            for (int j = i + i ; j < 4e4 + 5 ; j += i)
                isPrime[j] = 0;
        }
    }
}
LL f(LL n, LL k) {
    if (mp.count(n)) return mp[n];
    for (int i = k ; i >= 0 ; i--) {
        LL p = Prime[i];
        if (p * p > n) continue;
        if (n % p) continue;
        return mp[n] = (n / p) + f(n / p, i) * p;
    }
    return mp[n] = 1;
}
int main() {
    ifstream in("arithmetic.in");
    ofstream out("arithmetic.out");
    build();
    int t; in >> t; while (t--) {
        LL x; in >> x; 
        if (x == 1) {
            out << 0 << '\n';
            continue;
        }
        int t = lower_bound(Prime.begin(), Prime.end(), sqrt(x)) - Prime.begin();
        out << f(x, t) << '\n';
    }
}
