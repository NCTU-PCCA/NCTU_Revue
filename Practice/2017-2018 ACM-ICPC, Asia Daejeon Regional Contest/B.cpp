#include <bits/stdc++.h>
#define F first
#define S second
#define pb insert
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
int u[5];
int c[5][5] = {};
int a, b;
set<pair<set<pair<int,int>>,set<pair<int,int>>>>ans;
set<pair<int,int>>v1;
set<pair<int,int>>v2;
set<pair<pair<int,int>,pair<set<pair<int,int>>,set<pair<int,int>>>>>st;
void dfs(int turn,int lx,int ly) {
    if (st.count({{lx,ly},{v1,v2}}))return;
    st.insert({{lx,ly},{v1,v2}});
    int f = 0;
    if (turn) {
        for (auto &i : v2) {
            if (i.F == lx && i.S == ly)continue;
            int dx = i.F - lx;
            int dy = i.S - ly;
            if (abs(dx) > 1 || abs(dy) > 1) continue;
            if (v2.count({lx * 2 - i.F,ly*2-i.S})) {
                f = 1;
                break;
            }
            if (v2.count({i.F * 2 - lx, i.S * 2 - ly}) ) {
                f = 1;
                break;
            }
        }
    }
    else {
        for (auto &i : v1) {
            if (i.F == lx && i.S == ly)continue;
            int dx = i.F - lx;
            int dy = i.S - ly;
            if (abs(dx) > 1 || abs(dy) > 1) continue;
            if (v1.count({lx * 2 - i.F,ly*2-i.S})) {
                f = 1;
                break;
                
            }
            if (v1.count({i.F * 2 - lx, i.S * 2 - ly}) ) {
                f = 1;
                break;
            }
        }
    }
    if (f) {
        if (turn == 1 && lx == a && ly == b) {
            ans.insert({v1,v2});
        }
        return;
    }
    for (int i = 1 ; i <= 4 ; i++) {
        if (u[i] >= 4) continue;
        u[i]++;
        if (turn) {
            v1.pb({i,u[i]});
        }
        else {
            v2.pb({i,u[i]});
        }
        dfs(turn^1,i,u[i]);
        if (turn) {
            v1.erase({i,u[i]});
        }
        else {
            v2.erase({i,u[i]});
        }
        u[i]--;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> a >> b;
    swap(a, b);
    v1.pb({n,1});    
    u[n] = 1;
    dfs(0,n,1);
    cout << ans.size() << '\n';
}
