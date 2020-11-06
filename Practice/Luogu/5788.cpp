#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    reverse(arr.begin(), arr.end());
    vector<int> stk;
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        while (stk.size() && arr[stk.back()] <= arr[i])
            stk.pop_back();
        if (stk.size() == 0)
            ans.push_back(0);
        else
            ans.push_back(n - stk.back());
        stk.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0 ; i < n ; i++)
        cout << ans[i] << " \n"[i + 1 == n];
}
