#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(NULL));
    int testcase = 10; while (testcase--) {
        stringstream ss; ss << 10 - testcase;
        string testS; ss >> testS;
        ofstream input("input/" + testS + ".in");
        ofstream answer("answer/" + testS + ".ans");
        int t = 100; while (t--) {
            int len = rand() % 100 + 30;
            string ans;
            for (int i = 0 ; i < len ; i++)
                ans += char(rand() % 26 + 'a');
            string rev = ans;
            reverse(rev.begin(), rev.end());
            if (len % 2)
                ans += char(rand() % 26 + 'a');
            ans += rev;
            int pre = rand() % (1000 - ans.size());
            int suf = 1000 - ans.size() - pre;
            string output;
            for (int i = 0 ; i < pre ; i++)
                output += char(rand() % 26 + 'a');
            output += ans;
            for (int i = 0 ; i < suf ; i++)
                output += char(rand() % 26 + 'a');
            while (pre - 1 >= 0 && pre + ans.size() < output.size() && output[pre - 1] == output[pre + ans.size()])
                ans = output[pre - 1] + ans + output[pre + ans.size()], pre--;
            input << output << '\n';
            answer << ans << '\n';
        }
    }
}
