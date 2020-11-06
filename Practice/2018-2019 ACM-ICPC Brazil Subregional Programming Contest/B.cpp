#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int solve(int i, int j, auto &sg) {
    if (i <= 0 || j <= 0 || i == j) return INF;
    if (~sg[i][j]) return sg[i][j];
    set<int> st;
    for (int u = 1 ; u <= 100 ; u++) {
        st.insert(solve(i - u, j, sg));
        st.insert(solve(i, j - u, sg));
        st.insert(solve(i - u, j - u, sg));
    }
    for (int x = 0 ;; x++) {
        if (st.count(x))
            continue;
        sg[i][j] = x;
        return sg[i][j];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int>> sg(101, vector<int>(101, -1));
    sg[0][0] = 0;
    for (int i = 0 ; i <= 100 ; i++) {
        for (int j = 0 ; j <= 100 ; j++)  {
            solve(i, j, sg);
        }
    }
    int ans = 0;
    int n; cin >> n; while (n--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << "Y\n";
            return 0;
        }
        ans ^= sg[x][y];
    }
    if (ans == 0) {
        cout << "N\n";
    } else {
        cout << "Y\n";
    }
}

