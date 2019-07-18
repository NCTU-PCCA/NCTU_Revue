#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> data;
LL solve(LL n) {
    for (auto &v : data) {
        if (n % v)
            continue;
        return n - n / v;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ifstream in("choco.in");
    ofstream out("choco.out");
    data.push_back(1);
    data.push_back(1);
    while (data[data.size() - 1] + data[data.size() - 2] < 1e10) {
        data.push_back(data[data.size() - 1] + data[data.size() - 2]);
    }
    reverse(data.begin(), data.end());
    data.pop_back();
    data.pop_back();
    LL n, m; in >> n >> m;
    out << max(n * solve(m), m * solve(n)) << '\n';
}
