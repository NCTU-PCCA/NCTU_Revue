#include <bits/stdc++.h>
using namespace std;
void build(string &s, vector<int> &f) {
    f.push_back(-1);
    for (int i = 1, pos = -1; i < (int)s.size() ; i++) {
        while (~pos && s[i] != s[pos + 1])
            pos = f[pos];
        if (s[i] == s[pos + 1])
            pos++;
        f.push_back(pos);
    }
}
void modify(string &s, vector<int> &f) {
    int pos = f.back();
    while (~pos && s.back() != s[pos + 1])
        pos = f[pos];
    if (s.back() == s[pos + 1])
        pos++;
    f.push_back(pos);
}
bool match(string &pattern, string &content, vector<int> &f) {
    for (int i = 0, pos = -1; i < content.size() ; i++) {
        while (~pos && content[i] != pattern[pos + 1])
            pos = f[pos];
        if (content[i] == pattern[pos + 1])
            pos++;
        if (pos + 1 == pattern.size())
            return true;
    }
    return false;
}
bool solve(string &s, vector<string> &data, vector<vector<int> > &f) {
    for (int i = 0 ; i < (int)data.size() ; i++) {
        if (match(data[i], s, f[i]))
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<string> data(n);
    vector<vector<int> > f(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> data[i];
        build(data[i], f[i]);
    }
    int la = 0;
    for (int i = 0 ; i < q ; i++) {
        int t; cin >> t;
        if (t == 1) {
            string s; cin >> s;
            for (auto &c : s) {
                int cur = c - 'a';
                cur += la;
                cur %= 26;
                c = cur + 'a';
            }
            if (solve(s, data, f)) {
                cout << "YES\n";
                la = i;
            } else cout << "NO\n";
        } else {
            int x, al; cin >> x >> al;
            char c = (al + la) % 26 + 'a';
            data[(x + la) % n].push_back(c);
            modify(data[(x + la) % n], f[(x + la) % n]);
        }
    }
}
