#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int> > solve(int k) {
    string s; cin >> s;
    vector<pair<char, int> > ret;
    for (auto &c : s) {
        if (ret.size() == 0)
            ret.push_back({c, 1});
        else {
            if (c != ret.back().first)
                ret.push_back({c, 1});
            else {
                ret.back().second++;
                if (ret.back().second == k)
                    ret.pop_back();
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<char, int> > a = solve(k);
    vector<pair<char, int> > b = solve(k);
    if (k == 1) {
        cout << "Yes\n";
        return 0;
    }
    if (a == b)
        cout << "Yes\n";
    else
        cout << "No\n";
}

