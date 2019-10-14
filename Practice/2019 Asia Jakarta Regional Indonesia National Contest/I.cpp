#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> cnt(26, 0);
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == t[i])
            cnt[s[i] - 'a']++;
        else {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
    }
    int maxV = 0;
    for (int i = 0 ; i < 26 ; i++)
        maxV = max(maxV, cnt[i]);
    cout << maxV << '\n';
}
