#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 200;
    cout << n << '\n';
    for (int i = 0 ; i < n ; i++) {
        int m = 75;
        cout << m;
        set<int> st;
        while (st.size() != m) {
            int r = rand() % n;
            if (r == i)
                continue;
            st.insert(r);
        }
        for (auto &v : st)
            cout << ' ' << v + 1;
        cout << '\n';
    }
}
