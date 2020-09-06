#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL trans(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}
char transInv(int x) {
    if (0 <= x && x <= 9)
        return x + '0';
    return (x - 10) + 'A';
}
LL w2t(string s) {
    LL ret = 0, b = s.size() + 1;
    for (auto &c : s) {
        ret *= b;
        ret += trans(c);
        b--;
    }
    return ret;
}
string t2w(LL x) {
    string ret;
    LL b = 2;
    while (x) {
        ret += transInv(x % b);
        x /= b;
        b++;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main() {
    ifstream in("factoradic.in");
    ofstream out("factoradic.out");
    string _s; getline(in, _s);
    string s = "";
    for (auto &c : _s)
        if (c == '+' || c == '-')
            s += " ", s += c, s += " ";
        else
            s += c;
    s = "+ " + s;
    stringstream ss; ss << s;
    string op;
    LL res = 0;
    while (ss >> op) {
        string num; ss >> num;
        LL x = w2t(num);
        if (op == "+")
            res += x;
        else
            res -= x;
    }
    out << t2w(res) << '\n';
}
