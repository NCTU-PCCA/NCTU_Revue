#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p; cin >> n >> p;
    vector<vector<int> > cnt(p, vector<int>(2));
    for (int i = 0 ; i < n ; i++) {
        int d; cin >> d;
        int a, b; cin >> a >> b;
        cnt[d - 1][0] += a;
        cnt[d - 1][1] += b;
    }
    int sumA = 0, sumB = 0, V = 0;
    for (int i = 0 ; i < p ; i++) {
        if (cnt[i][0] > cnt[i][1]) {
            cout << "A ";
            int sum = cnt[i][0] + cnt[i][1];
            cout << cnt[i][0] - (sum / 2 + 1) << ' ';
            cout << cnt[i][1] << '\n';
            sumA += cnt[i][0] - (sum / 2 + 1);
            sumB += cnt[i][1];
        } else {
            cout << "B ";
            int sum = cnt[i][0] + cnt[i][1];
            cout << cnt[i][0] << ' ';
            cout << cnt[i][1] - (sum / 2 + 1) << '\n';
            sumA += cnt[i][0];
            sumB += cnt[i][1] - (sum / 2 + 1);
        }
        V += cnt[i][0] + cnt[i][1];
    }
    cout << fixed << setprecision(10) << (double)abs(sumA - sumB) / V << '\n';



}
