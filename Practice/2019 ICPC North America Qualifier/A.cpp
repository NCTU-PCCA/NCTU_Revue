#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    for (int i = 0 ; i < n ; i++) {
        string s; cin >> s;
        if (s[0] == 'T')
            data[i] = 1;
        else
            data[i] = false;
    }
    stack<int> stk;
    string input; 
    getline(cin, input);
    getline(cin, input);
    stringstream ss; ss << input;
    string tmp;
    while (ss >> tmp) {
        if (tmp == "*") {
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            stk.push(x & y);
        }
        else if (tmp == "+") {
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            stk.push(x | y);
        }
        else if (tmp == "-") {
            int x = stk.top(); stk.pop();
            stk.push(!x);
        }
        else {
            stk.push(data[tmp[0] - 'A']);
        }
    }
    cout << (stk.top() ? 'T' : 'F') << '\n';

}
