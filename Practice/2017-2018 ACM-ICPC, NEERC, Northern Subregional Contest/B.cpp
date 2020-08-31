#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("boolean.in");
    ofstream out("boolean.out");
    string s; in >> s;
    for (auto &c : s) {
        if (c == '|')
            c = ' ';
    }
    stringstream ss; ss << s;
    set<string> st;
    bool f = 1;
    string tmp;
    while (ss >> tmp) {
        if (tmp.size() == 2) {
            if (st.count(tmp.substr(1))) {
                f = 0;
            }
            st.insert(tmp);
        } else {
            if (st.count("~" + tmp)) {
                f = 0;
            }
            st.insert(tmp);
        }
    }
    int cnt = 0;
    set<string> res;
    for (auto &v : st) {
        if (v.size() == 2)
            res.insert(v.substr(1));
        else
            res.insert(v);
    }
    out << (1LL << res.size()) - f << '\n';
}
