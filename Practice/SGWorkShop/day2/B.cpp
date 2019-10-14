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
    string s;
    cin >> s;
    if(s!="Mia"){
        int t;
        cin >> t;
        while(t--){
            int ret = 0;
            f(64){
                int add;
                cin >> add;
                if(add){
                    ret ^= i;
                }
            }
            cout << ret+1 << endl;
            cin >> s;
        }
    }
    else{
        int t;
        cin >> t;
        while(t--){
            int b[64]={};
            int x = 0;
            f(64){
                cin >> b[i];
                if(b[i]){
                    x ^= i;
                }
            }
            int num ;
            cin >> num;
            num--;
            x ^= num;
            b[x]^=1;
            f(64){
                if(i%8==7){
                    cout<<b[i]<<endl;
                }
                else{
                    cout<<b[i]<<' ';
                }
            }
            cout<<"---"<<endl;
        }
    }

}
