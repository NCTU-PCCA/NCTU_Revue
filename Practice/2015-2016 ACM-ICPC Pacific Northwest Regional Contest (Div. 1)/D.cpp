#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> A, B;
    for (int i = 0 ; i < 3 ; i++) {
        int v; cin >> v; A.push_back(v);
    }
    for (int i = 0 ; i < 3 ; i++) {
        int v; cin >> v; B.push_back(v);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (A != B) {
        cout << "NO\n";
    } else {
        if (A[0] * A[0] + A[1] * A[1] == A[2] * A[2]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
