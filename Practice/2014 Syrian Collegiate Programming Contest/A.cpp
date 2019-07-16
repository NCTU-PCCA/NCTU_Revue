#include <bits/stdc++.h>
using namespace std;
typedef pair<char, char> pii;
int dp[26][1 << 9][1 << 9];
vector<vector<pii> > data;
int n[2];
int solve(int i, int j, char c, int state) {
    if (dp[c - 'a'][i][j] != -1)
        return dp[c - 'a'][i][j];
    dp[c - 'a'][i][j] = 0;
    int minV = 1;
    for (int x = 0 ; x < n[state] ; x++) {
        if (data[state][x].first != c || ((1 << x) & (state == 0 ? i : j)) != 0)
            continue;
        int next_i = i, next_j = j;
        if (state == 0)
            next_i |= (1 << x);
        else
            next_j |= (1 << x);
        minV = min(minV, solve(next_i, next_j, data[state][x].second, !state));
    }
    if (minV == 0)
        return dp[c - 'a'][i][j] = 1;
    else
        return dp[c - 'a'][i][j] = 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Game " << ++kase << ": ";
        cin >> n[0];
        string input; 
        getline(cin, input);
        data.clear(); data.resize(2);
        for (int i = 0 ; i < n[0] ; i++) {
            getline(cin, input);
            data[0].push_back({input.front(), input.back()});
        }
        cin >> n[1];
        getline(cin, input);
        for (int i = 0 ; i < n[1] ; i++) {
            getline(cin, input);
            data[1].push_back({input.front(), input.back()});
        }
        memset(dp, -1, sizeof(dp));
        int minV = 1;
        for (int i = 0 ; i < n[0] ; i++) {
            minV = min(minV, solve(1 << i, 0, data[0][i].second, 1));
        }
        cout << "player" << minV + 1 << '\n';
    }
}
