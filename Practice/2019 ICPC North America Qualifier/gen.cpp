#include <bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));
    ofstream in("input.in");
    ofstream out("output.out");
    int t = 1000; while (t--) {
        int n = rand() % 10000 + 5;
        in << n << '\n';
        vector<int> data;
        for (int i = 0 ; i < n ; i++) {
            int v = rand() % 200 - 100;
            in << v << ' ';
            data.push_back(v);
        }
        in << '\n';
        int ans = 0, sum = 0;
        for (int i = 0 ; i < n ; i++) {
            sum += data[i];
            sum = max(0, sum);
            ans = max(sum, ans);
        }
        out << ans << '\n';
    }
}
