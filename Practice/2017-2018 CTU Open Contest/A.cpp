#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        vector<int> arr(n);
        for (auto &v : arr)
            cin >> v;
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        int ptr = n - 1, d = arr[n - 1] - arr[n - 2];
        while (ptr >= 1 && arr[ptr] - arr[ptr - 1] == d)
            ptr--;
        cout << ptr + 1 << '\n';
    }
}
