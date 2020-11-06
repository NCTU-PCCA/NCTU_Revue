#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    sort(arr.begin(), arr.end());
    int minV = 0x3f3f3f3f;
    for (int i = 0 ; i < n / 2 ; i++)
        minV = min(minV, arr[i] + arr[n - i - 1]);
    cout << minV << '\n';
}
