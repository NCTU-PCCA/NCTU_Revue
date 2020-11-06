#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
vector<int> Z(vector<int> &s) { int L = 0, R = 0;
    vector<int> z(s.size()); z[0] = s.size();
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (i <= R && z[i - L] <= R - i) z[i] = z[i - L];
        else { L = i; if (i > R) R = i;
            while (R < z[0] && s[R - L] == s[R]) R++;
            z[i] = (R--) - L;
        }
    }
    return z;
}
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    reverse(arr.begin(), arr.end());
    vector<int> z = Z(arr);
    int ans1 = INF, ans2 = INF;
    for (int i = 1 ; i <= n ; i++) {
        bool ok = true;
        int j;
        for (j = 0 ; j + i <= n ; j += i) {
            if (z[j] < i) {
                int succ = j + z[j];
                int fail = n - succ;
                ok = false;
                if (fail + i < ans1 + ans2) {
                    ans1 = fail;
                    ans2 = i;
                } else if (fail + i == ans1 + ans2) {
                    if (i < ans2)
                        ans2 = i;
                }
                break;
            }
        }
        if (ok) {

            int fail;
            if (j != n) {
                int succ = j + z[j];
                fail = n - succ;
            } else 
                fail = 0;

            if (fail + i < ans1 + ans2) {
                ans1 = fail;
                ans2 = i;
            } else if (fail + i == ans1 + ans2) {
                if (i < ans2)
                    ans2 = i;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}
