#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; LL k;
    cin >> s >> k;
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t)
        cout << "YES\n";
    else
        cout << "NO\n";
}
