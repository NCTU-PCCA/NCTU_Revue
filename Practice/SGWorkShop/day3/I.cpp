#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<char> > G(2, vector<char>(n));
    for (int i = 0 ; i < 2 ; i++)
        for (int j = 0 ; j < n ; j++)
            cin >> G[i][j];
    int curX = 0, curY = 0, ans = 1, cnt = 0;
    while (1) {
        if (G[curX ^ 1][curY] == '#') {
            curY++;
            ans++;
            cnt++;
        } else if (curY + 1 < n && G[curX ^ 1][curY + 1] == '#') {
            if (k > 0) {
                curY += 2;
                ans += 4;
                k--;
            } else {
                curY += 2;
                ans += 2;
            }
        } else {
            curX ^= 1;
            curY++;
            ans += 2;
        }
        if (curY == n - 1 && curX == 1) {
            if (G[0][n - 1] != '#')
                k++;
            cnt++;
            break;
        } else if (curY == n && curX == 0) {
            ans -= 2;
            k++, cnt++;
            break;
        } else if (curY == n && curX == 1) {
            ans--;
            break;
        }
    }
    ans += min(cnt, k) / 2 * 2;
    cout << ans << '\n';
}
