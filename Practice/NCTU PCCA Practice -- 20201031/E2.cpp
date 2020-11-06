#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int idx; cin >> idx; cout << idx << ' ';
        int M; cin >> M;
        long double x; cin >> x;
        int ap = 0, aq = 1, bp = 1, bq = 1;
        while (1) {
            int mp = ap + bp, mq = aq + bq;
            assert(__gcd(mp, mq) == 1);
            if (mp > M || mq > M)
                break;
            if ((long double)mp / mq < x)
                ap = mp, aq = mq;
            else
                bp = mp, bq = mq;
        }
        long double ax = (long double)ap / aq;
        long double bx = (long double)bp / bq;
        if (abs(ax - x) < abs(bx - x))
            cout << ap << '/' << aq << '\n';
        else
            cout << bp << '/' << bq << '\n';
    }

}
