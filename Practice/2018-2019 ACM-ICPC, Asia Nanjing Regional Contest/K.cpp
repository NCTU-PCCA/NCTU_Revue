#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 50000;
    string s = "UDLR";
    while (n--)
        cout << s[rand() % 4];
    cout << '\n';
}
