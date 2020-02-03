#include <bits/stdc++.h>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        cin >> n >> m;
        char s[m][n+5];
        for(int i = 0 ; i < m;i++){
            scanf("%s",s[i]);
        }
        vector<int>v[m+5];
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                if(s[i][j] == '1'){
                    v[i].push_back(j);
                }
            }
        }
        int mi = 1000;
        for(int i = 1 ; i < (1<<m);i++){
            int u[n+5] = {};
            for(int j = 0 ; j < m ; j++){
                if((1<<j)&i){
                    for(auto k:v[j]){
                        u[k] = 1;
                    }
                }
            }
            int f = 0;
            for(int j = 0 ; j < n ; j++){
                if(!u[j]){
                    f = 1;
                    break;
                }
            }
            if(!f){
                mi = min(mi,__builtin_popcount(i));
            }
        }
        if(mi == 1000){
            cout << -1 << '\n';
        }
        else{
            cout << mi << '\n';
        }
    }
}
