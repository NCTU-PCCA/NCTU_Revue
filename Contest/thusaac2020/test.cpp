#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL sum = 0;
    vector<int> cnt(10, 0);
    for (int i = 0 ; i < 1e5 ; i++) {
        for (int i = 1 ; i <= 9 ; i++) {
            int c = i;
            while (c != 0 && c != 10) {
                c += (rand() % 2) * 2 - 1;
            }
            if (c == 0)
                cnt[i]++;
        }
    }
    for (int i = 1 ; i <= 9 ; i++)
        cout << i << ' ' << cnt[i] << '\n';
}
