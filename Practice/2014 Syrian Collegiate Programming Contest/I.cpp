#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        map<char, int> cnt;
        string s; while (cin >> s) {
            if (s == "*")
                break;
            for (auto &c : s)
                if (isalpha(c))
                    cnt[tolower(c)]++;
        }
        vector<pii> data;
        for (auto &p : cnt) {
            data.push_back({p.second, p.first});
        }
        sort(data.begin(), data.end());
        int sum = 0, tar = 5;
        while (data.size() && tar--) {
            sum += (data.back().second - 'a');
            data.pop_back();
        }
        if (sum > 62)
            cout << "Effective\n";
        else
            cout << "Ineffective\n";
    }
}
