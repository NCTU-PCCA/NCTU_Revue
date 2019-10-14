#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    if (a == b) {
        cout << "0 / 1\n";
        exit(0);
    }
    int ans = INF;
    for (int i = 1 ; i < b * 64 ; i++) {
        vector<int> data;
        for (int j = 0 ; j < a ; j++)
            data.push_back(b * 64 * j);
        for (int j = 0 ; j < b ; j++)
            data.push_back((a * 64 * j + i) % (a * b * 64));
        sort(data.begin(), data.end());
        data.push_back(a * b * 64);
        int minV = INF, maxV = 0;
        for (int i = 0 ; i < data.size() - 1 ; i++) {
            minV = min(minV, data[i + 1] - data[i]);
            maxV = max(maxV, data[i + 1] - data[i]);
        }
        ans = min(ans, maxV - minV);
    }
    int g = __gcd(ans, a * b * 64);
    cout << ans / g << " / " << a * b * 64 / g << '\n';
}
