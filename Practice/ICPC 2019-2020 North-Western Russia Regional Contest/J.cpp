#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
#define pb push_back
    using namespace std;
vector<int>g[200005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s[n+5];
    f(n){
        cin >> s[i];
    }
    int b[n][n];
    f(n){
        fr(j,0,n){
            b[i][j] = s[i][j]-'0';
        }
    }
    int ans[n][n] = {};
    int dp[n][n] = {};
    for (int i = n - 1 ; i >= 0 ; i--) {
        for (int j = i + 1 ; j < n ; j++) {
            if (dp[i][j] != b[i][j]) {
                for (int k = j + 1 ; k < n ; k++)
                    dp[i][k] += dp[j][k], dp[i][k] %= 10;
                ans[i][j] = 1;
                dp[i][j]++; dp[i][j] %= 10;
            }
        }
    }
    f(n){
        fr(j,0,n){
            cout << ans[i][j];
        }
        cout << endl;
    }
}
