#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
map<char, int> trans;
bitset<5000> dp[MAXN][MAXN];
string s;
void solve(int i, int j) {
    if (dp[i][j].size()) return ;
    if (i == j) return ;
    for (int k = i + 1 ; k < j ; k++) {
        // [i, k) [k, j)
        solve(i, k);
        solve(k, j);
        
        
        
        for (auto &v1 : dp[i][k]) {

        }

        /*
        for v2...
            for v1...
                if (v1 < v2)
                    dp[i][j].insert(v2 - v1);
                else
                    dp[i][j].insert(v2 + v1);
*/

    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    trans['I'] = 1;
    trans['V'] = 5;
    trans['X'] = 10;
    trans['L'] = 50;
    trans['C'] = 100;
    int kase = 0; while (cin >> s) {
        if (s[0] == '0')
            break;
        cout << "Case " << ++kase << ":";
        for (int i = 0 ; i < MAXN ; i++)
            for (int j = 0 ; j < MAXN ; j++) 
                dp[i][j] = bitset<5000>(0);
        solve(0, s.size());
    }
}
