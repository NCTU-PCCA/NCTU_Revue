#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<LL> x(3);
    LL w, h;
    for (auto &v : x)
        cin >> v;
    cin >> w >> h;
    if (w > h) swap(w, h);
    vector<int> idx{0, 1, 2};
    do {
        LL a1 = 2 * x[idx[1]] + x[idx[0]];
        LL a2 = 2 * x[idx[1]] + 2 * x[idx[2]];
        if (a1 > a2) swap(a1, a2);
        if (a1 <= w && a2 <= h) {
            cout << "Yes\n";
            return 0;
        }
        a1 = x[idx[0]] + x[idx[2]] + 3 * x[idx[1]];
        a2 = x[idx[0]] + x[idx[2]];
        if (a1 > a2) swap(a1, a2);
        if (a1 <= w && a2 <= h) {
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    cout << "No\n";
}
