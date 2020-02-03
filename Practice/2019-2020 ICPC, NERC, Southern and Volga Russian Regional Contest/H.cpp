#include <bits/stdc++.h>
#define f(n) for(int i=0;i<n;i++)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        vector<int>v;
        for(int i=0;i<10;i++){
            int add;
            cin >> add;
            add++;
            v.push_back(add);
        }
        v[0]++;
        int idx = 0,mi = 1e6;
        for(int i=0;i<10;i++){
            if(v[i]<mi){
                mi = v[i];
                idx = i;
            }
        }
        if(idx == 0){
            cout<<1;
            f(v[0]-1){
                cout<<0;
            }
            cout << endl;
        }
        else{
            f(v[idx]){
                cout<<idx;
            }
            cout << endl;
        }
    }

}
