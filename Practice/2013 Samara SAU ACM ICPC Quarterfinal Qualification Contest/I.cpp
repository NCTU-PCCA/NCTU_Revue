#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n + 1);
    data[0].F = 0, data[0].S = 0;
    for (int i = 1 ; i <= n ; i++)
        cin >> data[i].F >> data[i].S;
    sort(data.begin(), data.end());
    priority_queue<LL> pq;
    LL cur = 0, cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        cur += data[i].F - data[i - 1].F;
        cur -= data[i].S;
        pq.push(data[i].S);
        while (cur < 0) {
            cur += pq.top();
            cnt++;
            pq.pop();
        }
    }
    cout << cnt << '\n';
}
