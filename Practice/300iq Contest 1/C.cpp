#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 3e5 + 5;
LL a[MAXN], b[MAXN], ansa[MAXN], ansb[MAXN];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, k; cin >> n >> k;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for (int i = 1 ; i <= n ; i++)
        cin >> b[i];
    for (int i = 1 ; i <= n ; i++)
        ansb[b[i]] = i - n - 1;
    for (int _i = 1 ; _i <= n ; _i++) {
        int i = a[_i];
        if (k == 0) {
            ansa[i] = n;
        } else if (n - i <= k) {
            k -= n - i;
            continue;
        } else {
            vector<LL> arr;
            for (int j = i + 1 ; j <= n ; j++)
                arr.push_back(ansb[j]);
            sort(arr.begin(), arr.end());
            ansa[i] = -arr[k];
            k = 0;
        }
    }
    cout << "Yes\n";
    for (int i = 1 ; i <= n ; i++)
        cout << ansa[i] << " \n"[i == n];
    for (int i = 1 ; i <= n ; i++)
        cout << ansb[i] << " \n"[i == n];
}
