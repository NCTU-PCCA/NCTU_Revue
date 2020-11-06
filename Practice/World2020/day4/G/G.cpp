#include <bits/stdc++.h>
#define sq(x) (x) * (x)
using namespace std;
int absdis(vector<int> &a, vector<int> &b) {
    int sum = 0;
    for (int i = 0 ; i < 128 ; i++)
        sum += abs(a[i] - b[i]);
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; string s; getline(cin, s);
    vector<string> S;
    int len ;
    for (int x = 0 ; x < n ; x++) {
        getline(cin, s); S.push_back(s); len = s.size();
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            vector<int> id;
            for (int x = 0 ; x < 4 ; x++)
                id.push_back(x);
            int maxV = 0;
            do {
                string ret = "";
                for (int x = 0 ; x < 4 ; x++) {
                    ret += S[j].substr(id[x] * (len / 4), len / 4);
                }
                int sum = 0;
                for (int x = 0 ; x < len ; x++)
                    sum += (S[i][x] == ret[x]);
                maxV = max(maxV, sum);
            } while (next_permutation(id.begin(), id.end()));
            cout << i << ' ' << j << ' ' << maxV << '\n';
        }
    }
}
