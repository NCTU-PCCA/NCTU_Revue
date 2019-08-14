#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> data;
    for (int i = 0 ; i < 3 ; i++) {
        string s; cin >> s;
        data.push_back(s);
    }
    for (int i = 0 ; i < n ; i++) {
        map<char, int> cnt;
        for (int j = 0 ; j < 3 ; j++) {
            cnt[data[j][i]]++;
        }
        char c; int maxV = 0;
        for (auto &p : cnt) {
            if (maxV < p.second)
                maxV = p.second, c = p.first;
        }
        cout << c;
    }
    cout << '\n';
}
