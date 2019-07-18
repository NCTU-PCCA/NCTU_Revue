#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("brackets.in");
    ofstream out("brackets.out");
    string s; in >> s;
    stack<char> stk;
    int cur = 0, maxV = 0, maxIdx = 0;
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (s[i] == '(') {
            stk.push('(');
        } else if (s[i] == ')') {
            if (stk.size() && stk.top() == '(') {
                cur += 2;
                stk.pop();
            } else {
                if (maxV < cur) {
                    maxV = cur;
                    maxIdx = i;
                }
                cur = 0;
                while (stk.size())
                    stk.pop();
            }
        } else if (s[i] == '[') {
            stk.push('[');
        } else if (s[i] == ']') {
            if (stk.size() && stk.top() == '[') {
                cur += 2;
                cout << "cur " << cur << '\n';
                stk.pop();
            } else {
                if (maxV < cur) {
                    maxV = cur;
                    maxIdx = i;
                }
                cur = 0;
                while (stk.size())
                    stk.pop();
            }
        }
    }
    if (maxV < cur) {
        maxV = cur;
        maxIdx = s.size();
    }
    cout << maxV << ' ' << maxIdx << '\n';
    string ans = s.substr(maxIdx - maxV, maxV);
    out << ans << '\n';
}
