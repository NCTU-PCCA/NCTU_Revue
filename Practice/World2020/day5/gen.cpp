#include <bits/stdc++.h>
using namespace std;
string randBitString(int n) {
    string ret = "";
    for (int i = 0 ; i < n ;i ++)
        ret += rand() % 2 + '0';
    return ret;
}
int main() {
    srand(time(NULL));
    ofstream cout("input.in");
    int n = 8, m = 10, q = 100;
    cout << n << ' ' << m << ' ' << q << '\n';
    string ans = "";
    for (int i = 0 ; i < m ; i++)
        ans += '0' + (rand() % n);
    string S;
    for (int i = 0 ;i < m ; i++) {
        S += '0';
    }
    while (q--) {
        string op = randBitString(n);
        for (int i = 0 ; i < n ; i++) {
            if (op[i] == '0')
                continue;
            for (int j = 0 ; j < m ; j++) {
                if (ans[j] == i + '0')
                    S[j] ^= 1;
            }
        }
        cout << op << ' ' << S << '\n';
    }
    cout << "0 0 0\n";
    ofstream Ans("ans.out");
    Ans << ans;
}
