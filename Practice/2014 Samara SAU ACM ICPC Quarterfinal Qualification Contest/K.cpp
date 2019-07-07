#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    LL sum = 0;
    vector<LL> data(n);
    for (auto &v : data)
        cin >> v, sum += v;
    LL suma = 0;
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    for (int i = 1 ; i < n ; i += 2) {
        pq.push(data[i - 1]);
        pq.push(data[i]);
        suma += pq.top();
        pq.pop();
    }
    cout << sum - suma << ' ' << suma << '\n';
}
