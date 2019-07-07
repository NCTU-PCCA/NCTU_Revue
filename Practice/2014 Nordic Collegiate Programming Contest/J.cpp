#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct obj {
    string dir; LL a, r;
};
bool cmp(const obj &a, const obj &b) {
    return a.a + a.r < b.a + b.r;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL t, n; cin >> t >> n;
    vector<obj> data;
    while (n--) {
        string dir; LL a, r; cin >> dir >> a >> r;
        data.push_back({dir, a, r});
    }
    sort(data.begin(), data.end(), cmp);
    
}
