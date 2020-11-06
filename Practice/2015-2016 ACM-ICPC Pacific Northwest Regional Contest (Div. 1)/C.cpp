#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; getline(cin, s);
    vector<pair<string, string>> arr(n);
    for (auto &p : arr) {
        getline(cin, s);
        stringstream ss; ss << s;
        ss >> p.S; p.S.pop_back();
        string tmp;
        string level = "";
        while (ss >> tmp) {
            if (tmp == "lower")
                level += "2";
            else if (tmp == "middle")
                level += "1";
            else
                level += "0";
        }
        reverse(level.begin(), level.end());
        p.F = level;
    }
    int maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        maxV = max(maxV, (int)arr[i].F.size());
    }
    for (int i = 0 ; i < n ; i++) {
        while (maxV != arr[i].F.size())
            arr[i].F += "1";
    }
    sort(arr.begin(), arr.end());
    for (auto &p : arr)
        cout << p.S << '\n';
}
