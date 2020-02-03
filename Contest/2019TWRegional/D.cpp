#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<string> data;
    string s; while (cin >> s) {
        if (s != "bubble" && s != "tapioka")
            data.push_back(s);
    }
    if (data.size() == 0) 
        cout << "nothing\n";
    else {
        for (auto &v : data)
            cout << v << " ";
        cout << '\n';
    }
}
