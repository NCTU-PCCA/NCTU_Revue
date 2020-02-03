#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define pb push_back
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s;
    s = " " + s;
    int pre[n*2+5][3]={};
    int cnt[3] = {};
    for (int i = 1 ; i <= n ; i++) {
        cnt[s[i]-'A']++;
    }
    for (int i = 1 ; i <= 2 * n ; i++) {
        fr(j,0,3){
            if(j==s[i]-'A'){
                pre[i][j] = pre[i-1][j] + 1;
            }
            else{
                pre[i][j] = pre[i-1][j];
            }
        }
    }
    int mi = n;
    for (int i = 1 ; i <= n ; i++) {
        vector<int>v;
        fr(j,0,3){
            v.pb(j);
        }
        do{
            int c = 0;
            int ptr = i - 1;
            fr(j,0,3){
                c += cnt[v[j]] - (pre[ptr+cnt[ v[j] ]][v[j]] - pre[ptr][v[j]]);
                ptr += cnt[v[j]];
            }
            mi = min(mi,c);
        }while(next_permutation(v.begin(),v.end()));
    }
    cout << mi << endl;
}
