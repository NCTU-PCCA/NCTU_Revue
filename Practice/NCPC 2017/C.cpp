#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n){
        int nxt[10005]={};
        for(int i=0;i<n;i++){
            int add1,add2;
            cin >> add1 >> add2;
            nxt[add1]=add2;
        }
        int t;
        cin >> t;
        while(t--){
            int q;
            cin >> q;
            vector<int>v;
            int ex[10005]={};
            ex[q]=1;
            v.push_back(q);
            int nn = nxt[q];
            while(!ex[nn]){
                v.push_back(nn);
                ex[nn]=1;
                nn = nxt[nn];
            }
            int f = 0, g = 1;
            for(auto i:v){
                if(i==nn)f=1;
                if(f) {
                    if (g) g = 0;
                    else cout << ' ';
                    cout<<i;
                }
            }
            cout << endl;
        }
    }
}

