#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node *l, *r; int v;
};
void solve(string &op, vector<Node*> &l) {
    for (auto &c : op) {
        if (c == 'C') {
            
        } else if (c == 'D') {

        } else if (c == 'L') {

        } else if (c == 'P') {

        } else if (c == 'R') {

        } else if (c == 'S') {
            
        } else if (c == 'U') {

        }
    }
}
bool same(vector<Node*> &l1, vector<Node*> &l2) {
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<Node*> l1, l2;
    for (int i = 1 ; i <= 1e4 + 5 ; i++)
        l1.push_back({NULL, NULL, i}),
        l2.push_back({NULL, NULL, i});
    string op1, op2; cin >> op1 >> op2;
    solve(op1, l1);
    solve(op2, l2);
    if (same(l1, l2))
        cout << "True\n";
    else
        cout << "False\n";
}
