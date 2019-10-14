#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> one;
    map<LL, int> data;
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        data[v] = i + 1;
        if (v == 1)
            one.push_back(i + 1);
    }
    if (one.size() >= 2) {
        cout << one[0] << ' ' << one[1] << '\n';
        return 0;
    }
    LL a = 1, b = 2;
    while (b < 1e6 + 5) {
        if (data.count(a) && data.count(b)) {
            cout << data[a] << ' ' << data[b] << '\n';
            exit(0);
        }
        LL tmp = b;
        b += a;
        a = tmp;
    }
    cout << "impossible\n";
}
