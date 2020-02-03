#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1);
using namespace std;
typedef long long LL;
struct P {
    string name;
    int mon, day;
    bool operator < (const P &rhs) const {
        return mon == rhs.mon ? day < rhs.day : mon < rhs.mon;
    }
};
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int diff(P a, P b) {
    P cur = a; int ret = 0;
    while (1) {
        if (cur.mon == b.mon && cur.day == b.day)
            break;
        ret++;
        cur.day++;
        if (cur.day > mon[cur.mon])
            cur.day = 1, cur.mon++;
        if (cur.mon > 12)
            cur.mon = 1;
    }
    return ret;
}
P prev(P a) {
    P ret = a;
    if (ret.mon == 1 && ret.day == 1) {
        ret.mon = 12;
        ret.day = 31;
        return ret;
    }
    ret.day--;
    if (ret.day == 0) {
        ret.day = mon[ret.mon - 1];
        ret.mon--;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<P> data(n);
    for (auto &p : data) {
        cin >> p.name;
        char c;
        cin >> p.mon >> c >> p.day;
    }
    sort(data.begin(), data.end());
    data.push_back(data.front());
    vector<P> tmp;
    for (int i = 0 ; i < n ; i++) {
        if (data[i].day == data[i + 1].day && data[i].mon == data[i + 1].mon)
            continue;
        tmp.push_back(data[i]);
    }
    tmp.push_back(data.front());
    data = tmp;
    if (tmp.size() == 1) {
        cout << setw(2) << setfill('0') << prev(tmp[0]).mon << '-' << setw(2) << setfill('0') << prev(tmp[0]).day << '\n';
        return 0;
    }
    P ans; int maxV = 0;
    for (int i = 0 ; i < data.size() - 1 ; i++) {
        if (maxV < diff(data[i], data[i + 1])) {
            maxV = diff(data[i], data[i + 1]);
            ans = prev(data[i + 1]);
        } else if (maxV == diff(data[i], data[i + 1])) {
            P fake; fake.mon = 10; fake.day = 28;
            if (diff(fake, prev(data[i + 1])) < diff(fake, ans))
                ans = prev(data[i + 1]);
        }
    }
    cout << setw(2) << setfill('0') << ans.mon << '-' << setw(2) << setfill('0') << ans.day << '\n';
    
}
