#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; while (cin >> s) {
        if (s == "#")
            break;
        int p = 0;
        vector<int> pool;
        for (; p < s.size() ;) {
            if (s[p] == 'n')
                pool.push_back(-90), p += 5;
            else
                pool.push_back(90), p += 4;
        }
        int a ;
        if (pool.back() == 90)
            a = 90;
        else
            a = 0;
        pool.pop_back();
        int b = 1;
        while (pool.size()) {
            int p = pool.back(); pool.pop_back();
            a *= 2; a += p; b <<= 1;
        }
        int g = __gcd(a, b);
        a /= g, b /= g;
        if (b == 1) 
            cout << a << '\n';
        else
            cout << a << '/' << b << '\n';
    }
}
