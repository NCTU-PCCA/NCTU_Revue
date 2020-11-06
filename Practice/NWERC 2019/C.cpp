#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int check(auto &st, int l, int r) {
    auto l_it = st.lower_bound(l);
    auto r_it = st.upper_bound(r);
    int cnt = 0;
    for (auto &it = l_it ; it != r_it ; it++)
        cnt++;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> arr(n);
    for (auto &p : arr)
        cin >> p.F >> p.S;
    int m; cin >> m;
    set<int> st;
    while (m--) {
        int v; cin >> v;
        st.insert(v);
    }
    if (n == 1) {
        int cnt = check(st, arr[0].F, arr[0].S);
        if (cnt == 0) {
            cout << 2 << '\n';
            cout << arr[0].F << ' ' << arr[0].S << '\n';
        } else if (cnt == 1) {
            if (st.count(arr[0].S)) {
                cout << 1 << '\n';
                cout << arr[0].S - 1 << '\n';
            } else {
                cout << 1 << '\n';
                cout << arr[0].S << '\n';
            }
        } else if (cnt == 2) {
            cout << 0 << '\n';
        } else {
            cout << "impossible\n";
        }
        exit(0);
    }
    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
        auto p = arr[i];
        int cnt = check(st, p.F, p.S);
        if (cnt > 2) {
            cout << "impossible\n";
            exit(0);
        }
        if (cnt == 0) {
            if (i == n - 1) {
                ans.push_back(p.S - 1);
                ans.push_back(p.S);
                st.insert(p.S);
                st.insert(p.S - 1);
            } else {
                int x = check(st, arr[i + 1].F, arr[i + 1].S);
                if (arr[i].S == arr[i + 1].F && x == 2) {
                    ans.push_back(p.S - 1);
                    ans.push_back(p.S - 2);
                    st.insert(p.S - 1);
                    st.insert(p.S - 2);
                } else {
                    ans.push_back(p.S - 1);
                    ans.push_back(p.S);
                    st.insert(p.S);
                    st.insert(p.S - 1);
                }
            }
        } else if (cnt == 1) {
            if (i == n - 1) {
                if (st.count(p.S)) {
                    ans.push_back(p.S - 1);
                    st.insert(p.S - 1);
                } else {
                    ans.push_back(p.S);
                    st.insert(p.S);
                }
            } else {
                int x = check(st, arr[i + 1].F, arr[i + 1].S);
                if ((arr[i].S == arr[i + 1].F && x == 2) || st.count(p.S)) {
                    if (st.count(p.S - 1)) {
                        ans.push_back(p.S - 2);
                        st.insert(p.S - 2);
                    } else {
                        ans.push_back(p.S - 1);
                        st.insert(p.S - 1);
                    }
                } else {
                    ans.push_back(p.S);
                    st.insert(p.S);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &v : ans)
        cout << v << ' ';
    cout << '\n';
}
