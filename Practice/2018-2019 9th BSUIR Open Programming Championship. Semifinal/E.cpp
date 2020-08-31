#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool isLegal(auto &cnt) {
    int sum = 0;
    for (int i = 0 ; i < 10 ; i++)
        sum += cnt[i];
    if (sum == 19 && cnt[1] == 1 && cnt[0] == 18)
        return true;
    if (sum == cnt[0])
        return sum == 1;
    return sum < 19;
}
string form(auto &cnt) {
    assert(isLegal(cnt));
    int sum = 0;
    for (int i = 0 ; i < 10 ; i++)
        sum += cnt[i];
    if (sum == cnt[0])
        return "0";
    int idx = -1;
    for (int i = 1 ; i < 10 ; i++) {
        if (cnt[i] == 0)
            continue;
        idx = i;
        break;
    }
    string res = "";
    res += char(idx + '0');
    cnt[idx]--;
    for (int i = 0 ; i < 10 ; i++) {
        while (cnt[i]) {
            res += char(i + '0');
            cnt[i]--;
        }
    }
    return res;
}

bool isAllZero(auto &cnt) {
    int sum = 0;
    for (int i = 0 ; i < 10 ; i++)
        sum += cnt[i];
    return cnt[0] == sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if (s.size() == 1) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }
    if (s.size() == 2) {
        sort(s.begin(), s.end());
        cout << s[0] << ' ' << s[1] << '\n';
        return 0;
    }
    vector<int> cnt(10, 0);
    for (auto &c : s)
        cnt[c - '0']++;
    if (s.size() - cnt[0] == 0) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }
    if (s.size() - cnt[0] == 1) {
        cnt[0]--;
        if (isLegal(cnt)) {
            cout << 0 << ' ' << form(cnt) << '\n';
        } else {
            cout << -1 << ' ' << -1 << '\n';
        }
        return 0;
    }

    if (cnt[0] >= 18 && cnt[1] >= 1) {
        cnt[0] -= 18, cnt[1]--;
        if (isLegal(cnt)) {
            cout << form(cnt) << ' ' << 1000000000000000000 << '\n';
            return 0;
        }
        cnt[0] += 18, cnt[1]++;
    }

    int taken = min((int)s.size() - 1, 18);

    vector<int> cntb(10, 0);
    for (int i = 9 ; i >= 0 ; i--) {
        while (cnt[i] && taken) {
            cnt[i]--, taken--;
            cntb[i]++;
        }
    }

    if (isAllZero(cnt) && cnt[0] > 1) {
        int idx = -1;
        for (int i = 1 ; i < 10 ; i++) {
            if (cntb[i] == 0)
                continue;
            idx = i;
            break;
        }
        cntb[idx]--; cnt[idx]++;
        cnt[0]--; cntb[0]++;
    }

    if (isLegal(cnt) && isLegal(cntb)) {
        cout << form(cnt) << ' ' << form(cntb) << '\n';
    } else {
        cout << -1 << ' ' << -1 << '\n';
    }
}
