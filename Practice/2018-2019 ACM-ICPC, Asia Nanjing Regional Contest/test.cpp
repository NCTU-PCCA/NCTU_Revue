#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data;
    int n = 1e5;
    for (int i = 0 ; i < n ; i++)
        data.push_back(i);
    for (auto &v : data)
        cout << v << ' ';
    cout << '\n';
    vector<int> res(n + 1);
    partial_sum(data.begin(), data.end(), res.begin() + 1);
    for (auto &v : res)
        cout << v << ' ';
}
