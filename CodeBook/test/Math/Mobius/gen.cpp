#include <bits/stdc++.h>
using namespace std;
int test(int x) {
    int cnt = 0;
    int cur = 1;
    while (x != 1) {
        cur++;
        if (x % cur)
            continue;
        x /= cur; cnt++;
        if (x % cur == 0)
            return 0;
    }
    return (cnt % 2 ? -1 : 1);
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int testcase = 9; while (testcase--) {
        stringstream ss; ss << 9 - testcase;
        string testS; ss >> testS;
        ofstream input("input/" + testS + ".in");
        ofstream answer("answer/" + testS + ".ans");
        int t = 1000; while (t--) {
            int x = rand() % 10000 + 5;
            input << x << '\n';
            answer << test(x) << '\n';
        }
    }
}
