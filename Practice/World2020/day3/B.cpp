#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, int> cnt;
    vector<string> res;
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        for (auto &c : s)
            if (c == '.')
                c = ' ';
        string a, b;
        stringstream ss; ss << s; 
        ss >> a >> b;
        if (!cnt.count(b))
            res.push_back(b);
        cnt[b]++;
    }
    for (auto &s : res)
        cout << s << ": " << cnt[s] << '\n';
}
