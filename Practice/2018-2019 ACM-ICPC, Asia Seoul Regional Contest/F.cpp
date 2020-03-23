#include <bits/stdc++.h>
using namespace std;
void error() {
    cout << "error\n";
    exit(0);
}
void improper() {
    cout << "improper\n";
    exit(0);
}
void proper() {
    cout << "proper\n";
    exit(0);
}
bool isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
int main() {
    string _s; getline(cin, _s);
    string s;
    for (auto &c : _s) {
        if (c == ' ')
            continue;
        s += c;
    }

    if (s.size() == 1) {
        if (isalpha(s[0]))
            proper();
        else
            error();
    }

    string a = s, o = s;
    for (auto &c : a)
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')
            c = ' ';
    for (auto &c : o)
        if (isalpha(c) || c == '(' || c == ')')
            c = ' ';

    int cnt = 0;
    for (auto &c : s) {
        if (c == '(')
            cnt++;
        if (c == ')')
            cnt--;
        if (cnt < 0)
            error();
    }
    if (cnt != 0)
        error();

    stringstream A, O;
    A << a;
    O << o;
    string tmp;
    while (A >> tmp)
        if (tmp.size() != 1)
            error();
    while (O >> tmp)
        if (tmp.size() != 1)
            error();
    s = "(" + s + ")";
    vector<char> stk;
    for (auto &c : s) {
        if (c != ')') {
            stk.push_back(c);
        } else {
            vector<char> list;
            while (stk.back() != '(')
                list.push_back(stk.back()), stk.pop_back();
            stk.pop_back();
            stk.push_back('a');
            for (int i = 0 ; i < list.size() ; i++) {
                char c = list[i];
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
                    if (i - 1 < 0 || !isalpha(list[i - 1]))
                        error();
                    if (i + 1 >= list.size() || !isalpha(list[i + 1]))
                        error();
                }
            }
            if (list.size() == 0)
                error();
        }
    }
    stk.clear();
    for (auto &c : s) {
        if (c != ')') {
            stk.push_back(c);
        } else {
            vector<char> list;
            while (stk.back() != '(')
                list.push_back(stk.back()), stk.pop_back();
            stk.pop_back();
            stk.push_back('a');
            if (list.size() != 3)
                improper();
        }
    }
    proper();
}
