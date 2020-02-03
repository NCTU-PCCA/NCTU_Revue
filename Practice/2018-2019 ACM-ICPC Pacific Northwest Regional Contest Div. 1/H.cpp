#include <bits/stdc++.h>
using namespace std;
vector<int> P;
vector<bool> isP;
void Prime() {
    isP.clear();
    isP.resize(1e6 + 5, true);
    isP[0] = isP[1] = 0;
    for (int i = 2 ; i <= 1e6 ; i++) {
        if (isP[i]) {
            P.push_back(i);
            for (int j = i + i ; j <= 1e6 ; j += i)
                isP[j] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    Prime();
    int x; cin >> x;
    int cnt = 0;
    while (1) {
        if (x < 4)
            break;
        cnt++;
        int p, q;
        for (auto &_p : P) {
            if (isP[x - _p]) {
                p = _p, q = x - _p;
                break;
            }
        }
        x = q - p;
    }
    cout << cnt << '\n';
}
