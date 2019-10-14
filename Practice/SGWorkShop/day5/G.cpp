#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
vector<int> solve(string s) {
    vector<int> ret;
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] == s[(i + 1) % s.size()] && s[i] == '1')
            ret.push_back(i), s[i] = s[(i + 1) % s.size()] = '0';
    }
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] == '0') continue;
        int pos = i;
        while (pos - 2 >= 0 && s[pos - 1] == s[pos - 2] && s[pos - 1] == '0') {
            ret.push_back(pos - 2);
            ret.push_back(pos - 1);
            swap(s[pos], s[pos - 2]);
            pos -= 2;
        }
        if (pos - 1 >= 0 && s[pos] == s[pos - 1])
            s[pos] = s[pos - 1] = '0', ret.push_back(pos - 1);
    }
    if (s.size() % 2) {
        int cnt = 0;
        for (int i = 0 ; i < s.size() ; i++)
            cnt += (s[i] == '1');
        for (int i = 0 ; i < s.size() && cnt > 1 ; i++) {
            if (s[i] == '1') {
                int pos = (i - 1 + s.size()) % s.size();
                while (s[pos] != '1') {
                    ret.push_back((pos - 1 + s.size()) % s.size());
                    ret.push_back((pos     + s.size()) % s.size());
                    swap(s[(pos + 1) % s.size()], s[(pos - 1 + s.size()) % s.size()]);
                    pos = (pos - 2 + s.size()) % s.size();
                }
                ret.push_back(pos);
                s[pos] = s[(pos + 1) % s.size()] = '0';
                cnt -= 2;
            }
        }
        if (cnt == 1) {
            int pos;
            for (int i = 0 ; i < s.size() ; i++)
                if (s[i] == '1')
                    pos = i;
            while (pos != 0) {
                ret.push_back((pos - 2 + s.size()) % s.size());
                ret.push_back((pos - 1 + s.size()) % s.size());
                swap(s[(pos - 2 + s.size()) % s.size()], s[pos]);
                pos = (pos - 2 + s.size()) % s.size();
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    vector<int> a = solve(s);
    vector<int> b = solve(t);
    reverse(b.begin(), b.end());
    cout << a.size() + b.size() << '\n';
    for (auto &v : a) {
        cout << v << '\n';
        assert(s[v] == s[(v + 1) % s.size()]);
        s[v] = s[(v + 1) % s.size()] = ((s[v] - '0') ^ 1) + '0';
    }
    for (auto &v : b) {
        cout << v << '\n';
        assert(s[v] == s[(v + 1) % s.size()]);
        s[v] = s[(v + 1) % s.size()] = ((s[v] - '0') ^ 1) + '0';
    }
    assert(a.size() + b.size() <= 100000);
    assert(s == t);
}
