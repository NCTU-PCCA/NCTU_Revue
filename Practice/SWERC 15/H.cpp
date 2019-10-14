#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL eval(string s) {
    LL ret = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        ret *= 2;
        ret += s[i] - '0';
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<LL> app;;
    for (int N = 1 ; N < 64 ; N++) {
        for (int M = 1 ; M < 64 ; M++) {
            string s = "";
            bool isA = true; while (1) {
                if (isA) {
                    for (int i = 0 ; i < N ; i++)
                        s += '1';
                } else {
                    for (int i = 0 ; i < M ; i++)
                        s += '0';
                }
                isA = !isA;
                if (s.size() > 63) break;
                app.insert(eval(s));
            }
        }
    }
    LL x, y; cin >> x >> y;
    vector<LL> all;
    for (auto &v : app)
        all.push_back(v);
    /*for (auto &v : all)
        cout << v << ' ';
    cout << endl;*/
    // for (int i = 0 ; i < 30 ; i++)
       // cout << all[i] << ' ';
    //cout << endl;
    //cout << upper_bound(all.begin(), all.end(), y) - all.begin() - 1 << '\n';
    //cout << lower_bound(all.begin(), all.end(), x) - all.begin() - 1 << '\n';
    cout << (upper_bound(all.begin(), all.end(), y) - all.begin()) - (lower_bound(all.begin(), all.end(), x) - all.begin()) << '\n';
}
