#include <bits/stdc++.h>
#define F first  
#define S second
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<string, int> > data;
    int sum = 0, zero = 0, hand = 0;
    for (int i = 0 ; i < n ; i++) {
        string a; int b; cin >> a >> b;
        if (b == 0)
            zero++;
        if (b == 100)
            hand++;
        b *= 100;
        data.push_back({a, b});
        sum += b;
    }
    if (sum + 49 * (n - hand) < 10000 || sum - 50 * (n - zero) > 10000) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    for (int i = 0 ; i < n ; i++) {
        cout << data[i].F << ' ';
        int minV = 10000 - (sum - data[i].S + (n - 1 - hand + (data[i].S == 10000)) * 49);
        int maxV = 10000 - (sum - data[i].S - (n - 1 - zero + (data[i].S == 0)    ) * 50);
        minV = max({data[i].S - 50, minV, 0});
        maxV = min({data[i].S + 49, maxV, 10000});
        cout << minV / 100 << '.' << setw(2) << setfill('0') << minV % 100 << ' ' << maxV / 100 << '.' << setw(2) << setfill('0') << maxV % 100 << '\n';
    }
}
