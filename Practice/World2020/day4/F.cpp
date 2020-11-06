#include <bits/stdc++.h>
using namespace std;
void go(int n) {
    vector<int> p(n);
    for (auto &v : p)
        cin >> v, v--;
    if (n <= 2) {
        cout << "No\n";
        return ;
    }
    int t = max(1000 / n, 10);
    while (t--) {
        vector<int> q(n);
        for (int i = 0 ; i < n ; i++)
            q[i] = i;
        random_shuffle(q.begin(), q.end());
        vector<int> left(n);
        for (int i = 0 ; i < n ; i++)
            left[i] = p[q[i]];
        vector<int> righ(n);
        for (int i = 0 ; i < n ; i++)
            righ[i] = q[p[i]];
        if (left != righ) {
            cout << "Yes\n";
            for (int i = 0 ; i < n ; i++)
                cout << q[i] + 1 << " \n"[i + 1 == n];
            return ;
        }
    }
    cout << "No\n";
}
int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        go(n);
    }
}
