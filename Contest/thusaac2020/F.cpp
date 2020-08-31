#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
void FWT(vector<LL> &A, int T) {
    int n = A.size();
    for (int len = 1 ; len < n ; len <<= 1) {
        vector<int> a1(len), a2(len);
        for (int i = 0 ; i < n ; i += 2 * len) {
            for (int j = 0 ; j < len ; j++) {
                a1[j] = A[i + j] + A[i + j + len];
                a2[j] = A[i + j] - A[i + j + len];
            }
            for (int j = 0 ;  j< len ; j++) {
                A[i + j] = a1[j];
                A[i + j + len] = a2[j];
                if (T == -1) {
                    A[i + j] /= 2;
                    A[i + j + len] /= 2;
                }
            }
        }
    }
}
const int MAXN = 1e5 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int len = 1;
    while (len < 2 * MAXN) len <<= 1;
    vector<LL> arr(len);
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        arr[v]++;
    }
    FWT(arr, 1);
    vector<LL> res(len);
    for (int i = 0 ; i < len ; i++)
        res[i] = arr[i] * arr[i];
    FWT(res, -1);
    for (int i = 1 ; i < len ; i++) {
        if (res[i] > 2) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
